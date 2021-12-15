from graphics import *
from random import *
 
def main():
    w = int(input("Window width: "))
    win = GraphWin("Graphics Window",w,w) 
    circle = Circle(Point(w/2,w/2),w/2)
    pointcount = 0
    for i in range(1,10001):
        x = randint(0,w)
        y = randint(0,w)
        point = Point(x,y)
        if (((x - w/2)**2)+((y - w/2)**2)) <= ((w**2)/4):
            win.plotPixelFast(x,y,"red")
            pointcount += 1
        else:
            win.plotPixelFast(x,y,"blue")
        if i % 100 == 0:
            app_pi = (pointcount/i)*4
            print("Approximate pi at",i,"is:",app_pi)
            win.plotPixel(x,y,"green")
 
    input("Press ENTER to exit")
    win.close()
 
main()