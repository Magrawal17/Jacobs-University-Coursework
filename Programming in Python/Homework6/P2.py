def main():
    f=open("numbers.txt","r")
        
    s=0

    for line in f:
        b=line.strip()#strip removes all the whitespaces from the string
        s=s+ int(b)

    print("Sum is =",s)
    f.close()

main()



