"""
File: student.py
Resources to manage a student's name and test scores.
"""

class Student(object):
    def __init__(self, name, number):
        """All scores are initially 0."""
        self._name = name
        self._scores = []
        for count in range(number):
            self._scores.append(0)

    def getName(self):
        """Returns the student's name."""
        return self._name

    def setScore(self, i, score):
        """Resets the ith score, counting from 1."""
        self._scores[i - 1] = score

    def getScore(self, i):
        """Returns the ith score, counting from 1."""
        return self._scores[i - 1]

    def getAverage(self):
        """Returns the average score."""
        return sum(self._scores) / len(self._scores)
        
    def getHighScore(self):
        """Returns the highest score."""
        return max(self._scores)

    def __str__(self):
        """Returns the string representation of the student."""
        return "Name: " + self._name  + "\nScores: " + \
                " ".join(map(str, self._scores))

    def __eq__(self, other):
        if self.getName() == other.getName():
            return True
        else:
            return False

    def __ne__(self, other):  # similar to the equality
        if self.getName() == other.getName():
            return False
        else:
            return True

    def __lt__(self, other):
        return True if self.getName() < other.getName() else False

    def __le__(self, other):
        return True if self.getName() <= other.getName() else False

    def __gt__(self, other):
        return True if self.getName() > other.getName() else False

    def __ge__(self, other):
        return True if self.getName() >= other.getName() else False