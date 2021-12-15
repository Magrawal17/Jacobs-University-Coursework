from graphics import *
 
 
# defining a function
def main():
    win = GraphWin()
    # creating a square using Rectangle class
    square = Rectangle(Point(70, 70), Point(30, 30))
    square.setOutline("red")
    square.setFill("red")
    # drawing the square
    square.draw(win)
    for i in range(10):
        # getting the point of click
        p = win.getMouse()
        # getting the centre of the square
        c = square.getCenter()
        dx = p.getX() - c.getX()
        dy = p.getY() - c.getY()
        # creating a clone of the ori square
        new_square = square.clone()
        # moving the clone to the new place
        new_square.move(dx, dy)
        # drawing the close
        new_square.draw(win)
    win.close()
 
# calling the function
main()