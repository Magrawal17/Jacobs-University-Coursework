### Students taking this course in Spring 2022, Please remember to take this sample only for reference. Some of the frameworks used here have been not been permiteed for this course so please refer to the TA's or Proffesor. Additionally this is a sample when you are not able to host it somewhere, this is how the step by step insructions should be for others to use it. 


# README for beergame

### Contributors

Sprint 1
- Sherry Usman
- Nitesh Khatiwada

Sprint 2
- Peeyush Man Singh
- Mahiem Agrawal


## About the Project

The Beer Distribution Game (The Beer Game) is a simulation game created by a group of professors at MIT Sloan School of Management in early 1960s to demonstrate a number of key principles of supply chain management. The game is played by teams of at least four players, often in heated competition, and takes from one to one and a half hours to complete. A debriefing session of roughly equivalent length typically follows to review the results of each team and discuss the lessons involved.

### Built with
* HTML
* CSS
* [Python3](https://www.python.org/download/releases/3.0/)
* [Bootstrap](https://getbootstrap.com/docs/3.4/css/)
* [VannilaJS](http://vanilla-js.com/)
* [Flask](https://www.fullstackpython.com/flask.html)
* [MySQL](https://www.mysql.com/)

## File Structure
```
\--se-02-team-15
        \--extras                   # Sample HTML Pages from previous sprints
            \- ..
        \--static
            \--css                  # All the CSS Files used
            \--img                  # All the images used 
        \--templates    
            \--                     # Main HTML files    
        \--sql  
            \--                     # SQL Query used for initialization
        \--tests
            |--test_sprint1.py      # Main Testing Python Code
        -- app.py                    # Main Python Code
        -- README.md
        -- requirements.txt          # Required flask dependencies to run this program
        -- .gitignore    
```

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. What things you need to install the software and how to install them.V

### Prerequisites

* [Mysql](https://dev.mysql.com/downloads/installer/)
* Flask 
```
pip3 install Flask
```
* Virtual Env
```
sudo pip3 install virtualenv 
```

## Installation Guide

```bash
# Clone the repo.
# Obviously this wont work for you students, for you to run it you need download the entire repositary.
# Then go to this folder where it is. But your readme for the project should start with git clone for sure.
# git clone https://github.com/lorenzorota/se-02-team-15.git -> only for sample
cd se-02-team-15/

# Create virtual environment
$ virtualenv env

# Start virtual environment
$ source env/bin/activate

# Install all the dependencies
$ pip3 install -r requirements.txt

# Open  MySQL
$ mysql -u {ENTER YOUR USERNAME OR ROOT} -p

# Run this command in MYSQL command line to create required database.
mysql> source sql/se_project.sql
mysql> exit

# Create db.yam file 
$ touch db.yaml

# Open db.yaml and enter database credentials in the file format described below
$ nano db.yaml

# Run python server
$ python3 app.py

```

### `db.yaml` file Format. Enter your respective credentials

We tried using ClamV so that it would be easier for the user. However clamv did not support the required flask dependices to run this program.

```yaml
mysql_host: "localhost"
mysql_user: "{YOUR USERNAME CHANGE THIS WHEN TYPING IN YOUR COMPUTER}"
mysql_password: "{YOUR PASSWORD CHANGE THIS WHEN TYPING IN YOUR COMPUTER}"
mysql_db: "seteam15"
```

# View Documentation

Go to this URL once the server has started.

```
http://localhost:5000/docs
```
# Run tests

Run this code once you are entire the environment

```sh
$ python3 tests/test_sprint1.py
```

## Sprint 2 Changes done

✅  Created requirements.txt file, which was not provided.

✅   Added env folder to .gitignore

✅   Sanitized SQL queries file. Added additional queries. Removed unnecessary sql dump statements.

✅   Added project installation guide to README.

✅   Added db.yaml to store database credentials.

✅   Created documentation generation infrastructure using Flask-Selfdoc.

✅   Fixed unittests. Only one test case was not running initially, even though 3 test cases were defined.

✅   Created sql table query for a single instructor to be in control of multiple games.

✅   Added player registration functionality.

✅   Added player login functionality.

✅   Added tests for login and register.

✅   Create game by admin functionality implemented. After game creation, displays list of all players' usernames, passwords and roles.

Basically we were just given a simple frontend implementation from the first srpint. Now this time we added the full backend + frontend integration as well as revamping the entire frontend code that we were given. Almost 80% of the work has already been done now just some final backend code is left for other sprints. A instrucot is able to create a multiple games and players can successfully login into that game and can come to the ordering screen.

## Acknowledgments

* Special thanks to Albrid Bendo, Lorenzo Rota, Subid Basaula and Flori Doci for guiding through the task.
