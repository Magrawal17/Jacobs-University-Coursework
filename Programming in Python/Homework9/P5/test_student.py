from student import *

def main():
    S1=Student("John",3)

    S1.setScore(1,100)
    S1.setScore(2,95)
    S1.setScore(3,50)

    print("Before changing name:")
    print(S1)

    S1.setName("Jack")

    print("After changing name:")
    print(S1)

main()
