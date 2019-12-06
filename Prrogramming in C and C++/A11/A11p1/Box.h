/*
CH-230-A
a11_p1.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

class Box
{
    private:
        double height;
        double width;
        double depth;
    public:
        Box();                 
        Box(double newheight,double newwidth,double newdepth);  
        ~Box();
	    Box(Box &b);
	    
        void setheight(double newheight);
	    void setwidth(double newwidth);
        void setdepth(double newdepth);
	
	    double getheight();
	    double getwidth();
        double getdepth();

	    void vprint();

};