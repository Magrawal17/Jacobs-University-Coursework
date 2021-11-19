fil=input("Enter file name = ")

f=open(fil,"r")

count=0

for line in f:
    count+=1
    wordlist=line.split()
    num_words=len(wordlist)
    print("Line =",count,"Wordcount =",num_words,"Words =",wordlist)

f.close()