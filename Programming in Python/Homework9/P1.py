class Student(object):
   """Represents a student."""

   def __init__(self, name, number):
      """All scores are initially 0."""
      print("Constructor being called")
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

def main():
    S1=Student("Jenny",2)
    S2=Student("Steve",2)
    S3=Student("Celine",2)

    S1.setScore(1,95)
    S1.setScore(2,90)

    S2.setScore(1,95)
    S2.setScore(2,90)

    S3.setScore(1,95)
    S3.setScore(2,90)

    print(S1)
    print(S2)
    print(S3)

main()
