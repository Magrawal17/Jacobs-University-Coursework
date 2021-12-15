from graphics import *
from random import *
 
def main():
    width = input("Window width: ")        
    number = input("Number of points: ")
    
    try:
        w = int(width)
        num = int(number)+1
        if w > 1000:
            print("Your window is too big.")
            quit()
        elif w < 0:
            print("Your input is not valid.")
            quit()
    except:    
        print("Error: Your input was not valid.")
        quit()
    
    win = GraphWin("Graphics Window",w,w)
    circle = Circle(Point(w/2,w/2),w/2)
    pointcount = 0
    
    for i in range(1,num):
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