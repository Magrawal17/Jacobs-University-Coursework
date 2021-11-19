def main():
    sampleDict = {'Physics': 82, 'Math': 85, 'History': 75,'Management': 70, 'Chemistry': 72}
    print("Min value key =",min_value_key(sampleDict))

def min_value_key(theDictionary):    
    theMinimum=min(theDictionary.values())
    for key in theDictionary:
        if theDictionary[key]==theMinimum:
            return key
main()