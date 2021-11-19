def main():
    n=int(input("Enter an integer = "))
    #two tuples v and w
    v=()
    w=()

    i=0
    print("Enter {0} real numbers for the first tuple".format(n))
    while(i<n):
        b=float(input())
        v=v+(b,)
        i+=1

    
    i=0
    print("Enter {0} real numbers for the second tuple".format(n))
    
    while(i<n):
        b=float(input())
        w=w+(b,) #concatenating tuples
        i+=1

    scalar_product(v,w,n)

    print("\nFor the first list:")
    largest(v,n)
    smallest(v,n)

    print("\nFor the second list:")
    largest(w,n)
    smallest(w,n)

def scalar_product(v,w,n):
    res=0

    i=0

    while i<n:
        res=res+(v[i]*w[i])
        i+=1
    
    print("Scalar product =",res)
    return

def largest(tup,n):
    m=tup.index(max(tup))

    print("The largest nubmer is = {0} and its position is {1}".format(tup[m],m))


def smallest(tup,n):
    m=tup.index(min(tup))

    print("The smallest nubmer is = {0} and its position is {1}".format(tup[m],m))

main()