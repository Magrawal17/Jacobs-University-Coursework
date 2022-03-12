import os, sys
import string
import random
currentdir = os.path.dirname(os.path.realpath(__file__))
parentdir = os.path.dirname(currentdir)
sys.path.append(parentdir)
import tempfile
import unittest

from app import app
from flask_mysqldb import MySQL



class FlaskTestCase(unittest.TestCase):
    # Please note that this test cases depend on your computer as well as well. For example if I already have
    # a instructor named admin in my database that might not be true for you so KEEP THIS IN MIND.

    # Working Test Cases - 15 . Failed Test Cases 4

    # The landing page opens successfully
    def test_landing_page(self):
        tester = app.test_client(self)
        response = tester.get('/login', content_type="html/text")
        self.assertIn(b'Instructor Login', response.data)

    # The login is successful for correct credentials
    def test_instructor_login_successful(self):
        tester = app.test_client(self)
        response = tester.post('/login', data=dict(username="admin1234", password="admin"), follow_redirects=True)
        self.assertIn(b'Invalid Credentials!', response.data)

    # The login is not successful for incorrect credentials
    def test_instructor_login_unsuccessful(self):
        tester = app.test_client(self)
        response = tester.post('/login', data=dict(username="wrong1", password="wrong"), follow_redirects=True)
        self.assertIn(b'Invalid Credentials!', response.data)

    # Instructor register opens successfully
    def test_instructor_register_page(self):
        tester = app.test_client(self)
        response = tester.get('/register', content_type="html/text")
        self.assertIn(b'Instructor Register', response.data)
    
    # Start Page
    def test_start_page(self):
        tester = app.test_client(self)
        response = tester.get('/start', content_type="html/text")
        self.assertIn(b'Welcome to The Beer Game', response.data)
    
    def test_instructor_registration(self):
        tester = app.test_client(self)
        response = tester.post('/register', data=dict(username="try12", password="wrong"), follow_redirects=True)
        self.assertIn(b'Instructor Login', response.data)

    def test_list1_of_players_page(self):
        tester = app.test_client(self)
        response = tester.get('/view_all_players/1', content_type="html/text")
        self.assertIn(b'List of Players', response.data)
    
    def test_list2_of_players_page(self):
        tester = app.test_client(self)
        response = tester.get('/view_all_players/1', content_type="html/text")
        self.assertIn(b'Username', response.data)
    
    def test_list3_of_players_page(self):
        tester = app.test_client(self)
        response = tester.get('/view_all_players/1', content_type="html/text")
        self.assertIn(b'Password', response.data)

    def test_player1_login(self):
        tester = app.test_client(self)
        response = tester.get('/player_login', content_type="html/text")
        self.assertIn(b'Player Login', response.data)
    
    def test_player2_login(self):
        tester = app.test_client(self)
        response = tester.post('/player_login', data=dict(username="bones", password="twake"), follow_redirects=True)
        self.assertIn(b'Invalid Credentials!', response.data)

    def test_players_screen1(self):
        tester = app.test_client(self)
        response = tester.get('/player_screen1/1', content_type="html/text")
        self.assertIn(b'Retailer', response.data)

    def test_players_screen2(self):
        tester = app.test_client(self)
        response = tester.get('/player_screen1/1', content_type="html/text")
        self.assertIn(b'Wholesaler', response.data)

    def test_players_screen3(self):
        tester = app.test_client(self)
        response = tester.get('/player_screen1/1', content_type="html/text")
        self.assertIn(b'Distributor', response.data)

    def test_players_screen4(self):
        tester = app.test_client(self)
        response = tester.get('/player_screen1/1', content_type="html/text")
        self.assertIn(b'Factory', response.data)

    def test_game_screen1(self):
        tester = app.test_client(self)
        response = tester.get('/player_screen2/FACTORY', content_type="html/text")
        self.assertIn(b'FACTORY', response.data)

    def test_game_screen2(self):
        tester = app.test_client(self)
        response = tester.get('/player_screen2/RETAILER', content_type="html/text")
        self.assertIn(b'RETAILER', response.data)

    def test_game_screen3(self):
        tester = app.test_client(self)
        response = tester.get('/player_screen2/WHOLESALER', content_type="html/text")
        self.assertIn(b'WHOLESALER', response.data)

    def test_game_screen4(self):
        tester = app.test_client(self)
        response = tester.get('/player_screen2/DISTRIBUTOR', content_type="html/text")
        self.assertIn(b'DISTRIBUTOR', response.data)

if __name__=='__main__':
   unittest.main()
   