data="Python is a great programming language"

words=data.split()#default separator is whitespace

print("The words separated are :")
for i in words:
    print(i)

data2=data.upper()
print(data2)

print("Position of programming in the text is =",data.find("programming"))

print(data.replace('g',"G"))