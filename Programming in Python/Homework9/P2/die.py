"""
File: die.py

This module defines the Die class.
"""

from random import randint

class Die(object):
    """This class represents a six-sided die."""

    def __init__(self):
        """The initial face of the die."""
        self._value = 1

    def roll(self):
        """Resets the die's value to a random number 
        between 1 and 6."""
        self._value = randint(1, 6)

    def getValue(self):
        return self._value

    def __str__(self):
        return str(self._value)   