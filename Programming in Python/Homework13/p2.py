import sys
import urllib.request

url = 'https://grader.eecs.jacobs-university.de/courses/350112/python/csv/exp2008xx.csv'
outfile = 'wdata1.csv'

try:
    month = input("Please enter month in numeric including both digits: ")
    if (1 <= int(month) <= 12) and (len(month) == 2):
        url = url.replace("xx", str(month))
        u = urllib.request.urlretrieve(url, outfile)
        print("Successfully stored the data into " + outfile)
    else:
        print("Invalid month! Please enter from 01 until 12")
except:
    print("Error fetching URL: ", url)
    sys.exit(1)