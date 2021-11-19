def method1():
    f=open("input.txt","r")
        
    ch1=f.read(1)
    ch2=f.read(1)# read(1) inputs data 1 bytes at a time as size=1 is specified read(size)

    #can also use for loop for go through the items in the file
    
    c1=ord(ch1)
    c2=ord(ch2)

    w=open("output.txt","w")
    w.write(str(c1*c2))

    w.close()
    f.close()

method1()



