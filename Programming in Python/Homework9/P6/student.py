class Student(object):
   """Represents a student."""

   def __init__(self, name, number,age):
      """All scores are initially 0."""
      self._name = name
      self._scores = []
      self._age=age
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
      return "Name: " + self._name  + \
             "\nAge: " + str(self._age) +"\nScores: " + " ".join(map(str, self._scores)) 

   def setName(self,name):
      """Sets the student's name."""
      self._name = name
   
   def setAge(self,age):
      """Sets the student's name."""
      self._age = age
   
   def getAge(self):
      """Sets the student's name."""
      return self._age