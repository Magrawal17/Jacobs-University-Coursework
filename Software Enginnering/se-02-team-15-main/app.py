from flask import Flask, render_template, url_for, request, redirect, session
from flask_mysqldb import MySQL
import os
import yaml
from flask_selfdoc import Autodoc
import random
import string
import webbrowser


app = Flask(__name__)
auto = Autodoc(app)

app.secret_key = os.urandom(16)

db = yaml.safe_load(open('db.yaml'))
app.config['MYSQL_HOST'] = db['mysql_host']
app.config['MYSQL_USER'] = db['mysql_user']
app.config['MYSQL_PASSWORD'] = db['mysql_password']
app.config['MYSQL_DB'] = db['mysql_db']

mysql = MySQL(app)

def mysql_connection():
    cursor = mysql.connection.cursor()
    return cursor


@app.route('/login', methods=['GET', 'POST'])
@auto.doc()
def login():
    """Login route for Instructor.
    Form Data: 
        username: Username of Instructor
        password: Password of Instructor
    If username and password match, redirect to create game page.
    If invalid credentials provided, display an error message and retry.
    """
    if request.method == 'POST' and 'username' in request.form and 'password' in request.form:
        username = request.form['username']
        password = request.form['password']
        cur = mysql_connection()
        cur.execute("SELECT * FROM Instructor I WHERE I.i_username = %s AND I.i_password = %s", (username, password))
        account = cur.fetchone()
        if account:
            session['loggedin'] = True
            session['username'] = username
            session['instructor_id'] = account[0]
            cur.execute('SELECT id_game from instructor_controls_games p WHERE p.id_instructor = %s', [session['instructor_id']]);
            all_games = cur.fetchall()
            return render_template("list_all_games.html", games=all_games)
        else:
            return render_template("login.html", invalid_credentials=True)
    else:
        return render_template('login.html')

@app.route('/register', methods=['GET', 'POST'])
@auto.doc()
def register():
    """Register route for instructor.
    Form Data: 
        username: Username of Instructor
        password: Password of Instructor
    Save user to database. Username should be unique.
    Redirect to login page on successful registration.
    """
    if request.method == 'POST':
        login_credentials = request.form
        username = login_credentials["username"]
        password = login_credentials['password']
        cur = mysql_connection()
        cur.execute('INSERT INTO Instructor(i_username, i_password) VALUES(%s, %s)', (username, password))
        mysql.connection.commit()
        cur.close()
        return render_template("login.html", acc_created=True)
    else:
        return render_template("register.html")

@app.route('/player_login', methods=['GET', 'POST'])
@auto.doc()
def player_login():
    """Login route for player
    Form Data: 
        username: Username of Player
        password: Password of Player
    Login if username and password matches.
    Password is provided if admin creates a game and the player has been chosen to play.
    If invalid credentials priovided, display an error message and retry.
    """
    if request.method == 'POST' and 'username' in request.form and 'password' in request.form:
        username = request.form['username']
        password = request.form['password']
        cur = mysql_connection()
        cur.execute("SELECT * FROM Player P WHERE P.p_username = %s AND P.p_password = %s", (username, password))
        account = cur.fetchone()
        if account:
            session['loggedin'] = True
            session['username'] = username
            session['player_id'] = account[0]
            return redirect(url_for('player_screen1', game_id=account[3]))
        else:
            return render_template("player_login.html", invalid_credentials=True)
    else:
        return render_template('player_login.html')


@app.route('/create_game', methods=['GET', 'POST'])
@auto.doc()
def create_game():
    """Create game by instructor
    Form Data: 
        session_length: Maximum number of weeks in game
        holding_cost: Holding cost for all departments
        backlog_cost: Backlog cost for all departments
        wholesaler_present: If wholesaler is present or not
        retailer_present: If retailer is present of not
        info_sharing: If info sharing should be activated
    Create game with these values in the game table.
    For every role, assign a student who has not been assigned to any game.
    If there is no student who have not been assigned to any game, display error and revert all students assigned to current game.
    On successful assignment of every role to each student, display username, password and role of all students playinh in currrent game.
    """
    if request.method == 'POST' and 'session_length' in request.form and 'holding_cost' in request.form and 'backlog_cost' in request.form and 'wholesaler_present' in request.form and 'retailer_present' in request.form and 'info_sharing' in request.form:
        session_length = request.form['session_length']
        holding_cost = request.form['holding_cost']
        backlog_cost = request.form['backlog_cost']
        wholesaler_present = request.form['wholesaler_present'] == 'Yes'
        retailer_present = request.form['retailer_present'] == 'Yes'
        info_sharing = request.form['info_sharing']

        cur = mysql_connection()
        cur.execute('INSERT INTO Game(holding_cost, backlog_cost, session_length, retailer_present, wholesaler_present) VALUES(%s, %s, %s, %s, %s)', (float(holding_cost), float(backlog_cost), int(session_length), int(bool(retailer_present)), int(bool(wholesaler_present))))
        mysql.connection.commit()
        gameId = cur.lastrowid

        game_roles = ["RETAILER", "WHOLESALER","DISTRIBUTOR", "FACTORY"]

        for game_role in game_roles:

            if(game_role == "RETAILER" and retailer_present == False):
                continue
            if(game_role == "WHOLESALER" and wholesaler_present == False):
                continue

            new_password = ''.join(random.choice(string.digits) for i in range(10)) 
            new_username = ''.join(random.choice(string.ascii_letters) for i in range(10)) 
            cur.execute("INSERT INTO Player(p_username, p_password, id_game) VALUES(%s, %s, %s)", (new_username,new_password, gameId))
            mysql.connection.commit()

        cur.execute("INSERT INTO instructor_controls_games(id_instructor, id_game) VALUES(%s, %s)", (session['instructor_id'], gameId))
        mysql.connection.commit()

        cur.execute('SELECT id_game from instructor_controls_games p WHERE p.id_instructor = %s', [session['instructor_id']]);
        all_games = cur.fetchall()

        return render_template("list_all_games.html", games=all_games)
    else:
        return render_template('create_game.html')

@app.route('/view_all_players/<int:game_id>', methods=['GET'])
@auto.doc()
def view_all_players(game_id):
    """View player credentials of game with game_id
    Displays player username and password
    """
    cur = mysql_connection()
    cur.execute('SELECT p_username, p_password from Player p WHERE p.id_game = %s', [game_id]);
    all_players = cur.fetchall()
    return render_template("list_all_players.html", players=all_players)

@app.route('/start')
@auto.doc()
def start():
    """Homepage of webapp.
    Contains the choice to select between instructor and player
    """
    return render_template('start.html')

@app.route('/player_screen1/<int:game_id>')
@auto.doc()
def player_screen1(game_id):
    """First screen displayed to player. Contains choice to select game role.
        After choosing a game role, player should be redirected to main game page.
        game-id: Number
    """
    cur = mysql_connection()
    cur.execute("SELECT retailer_present, wholesaler_present FROM Game G WHERE G.id_game = %s", [game_id])
    data = cur.fetchone()
    if data:
        return render_template('player_screen1.html', game_id=game_id, retailer_present=data[0], wholesaler_present=data[1])

@app.route('/player_screen2/<string:player_role>')
@auto.doc()
def player_screen2(player_role):
    """Main game page. Contains of four screen with demand, order, backlog and costs.
    Player should be able to input demand for current week.
    """
    cur = mysql_connection()
    cur.execute("UPDATE Player SET p_role = %s WHERE id_player = %s", [player_role, session['player_id']])
    mysql.connection.commit()

    return render_template('player_screen2.html', player_role=player_role)

@app.route('/docs')
def documentation():
    return auto.html(title='Beergame API Documentation')

if __name__ == "__main__":
    webbrowser.open_new('http://localhost:5000/start')
    app.run()


