import sys
import urllib . request

month = str(input('Enter the month as a double-digit integer:'))

# defines the url
url =  'https://grader.eecs.jacobs-university.de/courses/350112/python/csv/exp2008xx.csv'

# adds the input month to the end of the url
url = url.replace('xx', month)

# saves the data into a new csv file
urllib.request.urlretrieve(url, 'wdata1.csv')