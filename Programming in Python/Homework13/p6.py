import re
 
# ask user for file name
yourfile = input("Enter file name:")
 
# open file
f = open(yourfile, "r")
# use re.findall to check for jacobs email addresses
strings = re.findall("[a-z]\.[a-z]{2,}@jacobs-university\.de", f.read())
print(strings)
# close file
f.close()