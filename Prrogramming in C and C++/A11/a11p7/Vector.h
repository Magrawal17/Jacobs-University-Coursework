class Vector {
private:
    int size;
    double* components;   
public:
        
    Vector();
    Vector(Vector& b);
    ~Vector();
    Vector(int newsize,double* &newcomponents);
    
    void setSize(int newsize);
    void setComponent(double*&);

    int getSize() const;
    double* getComponents() const;

    void printvector();
    double norm() const;
    Vector sum(const Vector& b) const;
    Vector diff(const Vector& b) const;
    double scalar(Vector& b) const;
        
        
};