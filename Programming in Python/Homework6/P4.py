fil=input("Enter file name = ")

f=open(fil,"r")

a=f.read()#read whole content of the file at once

w=open("copy.txt","w")
w.write(a)

w.close()

f.close()
