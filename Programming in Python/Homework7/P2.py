def main():
    translate("Merry Christmas and Happy New Year")

def translate(list_en):
    data ={"Merry":"god", "Christmas":"jul", "and":"och", "Happy":"gott", "New":"nytt", "Year":"\u00E5r"}
    print("Translation of",list_en,"to swedish is:")
    word_list=list_en.split()
    for word in word_list:
        ret=data.get(word,None)
       # if ret!=None:
        print(ret,end=" ")
    print()
main()
