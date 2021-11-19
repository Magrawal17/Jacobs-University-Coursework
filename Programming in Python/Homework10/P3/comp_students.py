from student import *

def main():
    S1=Student("Betty",2)
    S2=Student("Alex",2)
    S3=Student("Alex",3)

    print("{0} == {1} --> {2}".format(S1.getName(),S2.getName(),S1==S2))
    print("{0} != {1} --> {2}".format(S1.getName(),S2.getName(),S1!=S2))
    print("{0} == {1} --> {2}".format(S2.getName(),S3.getName(),S2==S3))
    print("{0}  > {1} --> {2}".format(S1.getName(),S2.getName(),S1>S2))
    print("{0} >= {1} --> {2}".format(S2.getName(),S3.getName(),S2>=S3))
    print("{0}  < {1} --> {2}".format(S1.getName(),S3.getName(),S1<S3))
    print("{0} <= {1} --> {2}".format(S1.getName(),S2.getName(),S1<=S2))

main()