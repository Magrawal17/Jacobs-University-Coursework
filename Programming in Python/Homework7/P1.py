def main():
    inp=input("Enter a sentence = ")
    word_lst=inp.split() #splits the sentence into words
    a=longest_word(word_lst)
    print("The longest word is {0} with length {1}".format(a,len(a)))

def longest_word(lst):
    theDictionary={}
    for words in lst:
        theDictionary[words]=len(words) #creating a tuple (word,length)
    
    theMaximum=max(theDictionary.values())
    for key in theDictionary:
        if theDictionary[key]==theMaximum:
            return key

main()