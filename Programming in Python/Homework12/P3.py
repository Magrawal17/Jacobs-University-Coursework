from graphics import *
circles = [(100,100,100),(100,100,80),(100,100,60),(100,100,40),(100,100,20)]
 
def draw_archery(_list):
    """Draws an archery target."""
    win = GraphWin()
    count = 1
    for i in _list:
        x = i[0]
        y = i[1]
        radius = i[2]
        circle = Circle(Point(x,y),radius)
                
        countdict = {1:"white",2:"black",3:"blue",4:"red",5:"yellow"}
        circle.setFill(countdict[count])
 
        circle.draw(win)
        count += 1
        
    input()
        
    win.close()
 
draw_archery(circles)