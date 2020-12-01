#include <iostream>
#include <string>
#include"Vector.h"
using namespace std;

int main (int argc,char** argv){
    
    int size;
    cout<<"Number of Components:";
    cin>>size;

    cout<<"Vector 1"<<endl;
    double *component1;
    component1=new double[size];
    for(int i=0;i<size;i++)
    {
        cin>>component1[i];
    }

    cout<<endl<<"Vector 2"<<endl;
    double *component2;
    component2=new double[size];
    for(int i=0;i<size;i++)
    {
        cin>>component2[i];
    }
  

    Vector v1;
    v1.setComponent(component1);
    v1.setSize(size);
    Vector v2(v1);
    Vector v3(size,component2);
    
    cout<<"Vector 1"<<endl;
    v1.printvector();
    cout<<"Vector 2"<<endl;
    v2.printvector();
    cout<<"Vector 3"<<endl;
    v3.printvector();    


    cout<<"Norm: "<<v1.norm()<<endl;
    cout<<"Scalar: "<<v1.scalar(v3)<<endl;
    cout<<"Sum: ";
    (v1.sum(v3).printvector());
    cout<<"Diffrence: ";
    v1.diff(v3).printvector();

    
    return 0;
}
