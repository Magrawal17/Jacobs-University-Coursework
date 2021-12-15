from graphics import *
 
 
def main():
    """Draws a rectangle from user input."""
    win = GraphWin()
    global point1, point2
    point1 = win.getMouse()
    point2 = win.getMouse()
    rect = Rectangle(point1,point2)
    rect.setOutline("red")
    rect.setFill("red")
    rect.draw(win)
    input("Press Enter to quit")
    win.close()
 
def perimeter():
    """Returns rectangle perimeter."""
    length = abs(point1.getX()-point2.getX())
    width = abs(point1.getY()-point2.getY())
    perimeter = 2*(length+width)
    return perimeter
 
def area():
    """Returns rectangle area."""
    length = abs(point1.getX()-point2.getX())
    width = abs(point1.getY()-point2.getY())
    area = length*width
    return area
 
main()
Perimeter = perimeter()
print("Perimeter: ",Perimeter)
Area = area()
print("Area: ",Area)