from graphics import *
 
def main():
    w = 255
    win = GraphWin("Graphics Window",w,w)
 
    for red in range(w):
        for green in range(w):
            if red % 150 == 0 or green % 150 == 0:
                win.plotPixel(red,green,"brown")
            else:
                win.plotPixelFast(red,green,color_rgb(red,green,100))
 
    input("Press ENTER to exit")
    win.close()
 
main()