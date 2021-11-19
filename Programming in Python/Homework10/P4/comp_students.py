
from student import *
import random


def main():

    # create 10 students
    # arbitrary tests number
    s1 = Student("Betty", 2)
    s2 = Student("Joanna", 2)
    s3 = Student("Andy", 2)
    s4 = Student("George", 3)
    s5 = Student("Mike", 2)
    s6 = Student("Peter", 5)
    s7 = Student("Jimmy", 3)
    s8 = Student("Alex", 1)
    s9 = Student("Andy", 3)
    s10 = Student("Dilan", 4)

    # place those students in a list and shuffle it
    st_list = [s1, s2, s3, s4, s5, s6, s7, s8, s9, s10]
    random.shuffle(st_list)

    # print the unsorted list
    print("\nThe Unsorted list is:")
    i = 0  # convenience
    for st in st_list:
        i += 1
        print(i, '->', st.getName())

    # sort and print
    st_list.sort(reverse=True)  # descending order is reverse
    # the key of the sort is going to be the overloaded operator
    print("\nThe Sorted list is:")
    j = 0  # convenience
    for st in st_list:
        j += 1
        print(j, '->', st.getName())


main()