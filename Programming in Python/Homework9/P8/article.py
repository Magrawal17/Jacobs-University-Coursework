class Article(object):

    def __init__(self,name,category,color,rating,price):
        self._name=name
        self._cat=category
        self._color=color
        self._rating=rating
        self._price=price
    
    def __str__(self):

        return "Name: " + self._name + \
            "\nCatgeory: " + self._cat + \
            "\nColor: " + self._color + \
            "\nRating: " + self._rating + \
            "\nPrice: " + str(self._price) + "$" 

    def set(self,name):
        self._name=name

    def set(self,cat):
        self._cat=cat

    def set(self,rat):
        self._rating=rat

    def set(self,color):
        self._color=color

    def set(self,price):
        self._price=price


    def getName(self):
        return self._name   
    
    def getCategory(self):
        return self._cat
    
    def getRating(self):
        return self._rating 

    def getColor(self):
        return self._color 

    def getPrice(self):
        return self._price 

    def __add__(self,other):
        newName= self._name+" and " + other._name
        newCat= self._cat+" and " + other._cat
        newColor= self._color+" and " + other._color
        newRat= self._rating+" and " + other._rating
        newPrice= self._price + other._price

        return Article(newName,newCat,newColor,newRat,newPrice)
