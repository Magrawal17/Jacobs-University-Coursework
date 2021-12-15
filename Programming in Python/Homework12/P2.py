from graphics import *
 
def main():
    """Draws a face."""
    win = GraphWin()
 
    ear1 = Circle(Point(20,60),10)
    ear1.setFill("brown")
    ear1.draw(win)
 
    ear2 = Circle(Point(100,60),10)
    ear2.setFill("brown")
    ear2.draw(win)
    
    head = Circle(Point(60, 60), 40)
    head.setFill("brown")
    head.draw(win)
 
    eye1 = Circle(Point(45, 40), 10)
    eye1.setFill("white")
    eye1.draw(win)
    pupil1 = Point(45,40)
    pupil1.draw(win)
 
    eye2 = Circle(Point(75, 40), 10)
    eye2.setFill("white")
    eye2.draw(win)
    pupil2 = Point(75,40)
    pupil2.draw(win)
 
    nose = Polygon(Point(60, 55), Point(55, 65), Point(65, 65))
    nose.setFill("brown")
    nose.draw(win)
 
    mouth = Oval(Point(45, 75), Point(75, 85))
    mouth.setOutline("black")
    mouth.setFill("pink")
    mouth.draw(win)
 
    input()
    
    win.close()
 
main()