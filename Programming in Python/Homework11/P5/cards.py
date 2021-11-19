"""
File: cards.py

Module for playing cards, with classes Card and Deck
"""
import random


class Card(object):
    RANKS = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13)
    SUITS = ('Spades', 'Diamonds', 'Hearts', 'Clubs')

    def __init__(self, rank, suit):
        self.rank = rank
        self.suit = suit

    def __str__(self):
        if self.rank == 1:
            rank = 'Ace'
        elif self.rank == 11:
            rank = 'Jack'
        elif self.rank == 12:
            rank = 'Queen'
        elif self.rank == 13:
            rank = 'King'
        else:
            rank = self.rank
        return str(rank) + ' of ' + self.suit


class Deck(object):
    def __init__(self):
        self._cards = []
        for suit in Card.SUITS:
            for rank in Card.RANKS:
                c = Card(rank, suit)
                self._cards.append(c)

    def shuffle(self):
        random.shuffle(self._cards)

    def deal(self):
        if len(self) == 0:
            return None
        else:
            return self._cards.pop(0)

    def __len__(self):
        return len(self._cards)

    def __str__(self):
        result = ''
        for c in self._cards:
            result = self.result + str(c) + '\n'
        return result
