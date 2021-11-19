def main():
    lis=[]
    i=0
    while i<7:
        tup=input("Enter tuple values separated by whitespace = ")
        sp=tup.split()
        lis.append(tuple(sp))
        i+=1

    print("Before removing the empty tuples:")
    print(lis)

    #two methods 1)use list comprehension of for loop 2) create a new list without the empty tuple

    #method 1
    #lis=[t for t in lis if t] #creates a list that contains the element t from the for loop that satisfys if t i.e if t != 0 (None)

    #method2
    lis2=[]

    for tuples in lis:
        if (tuples != ()): #checking if the value exists (i.e it is not ())
            lis2.append(tuples)

    print("After removing the empty tuples:")
    print(lis2)


main()