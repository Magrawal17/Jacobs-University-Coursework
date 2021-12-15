import csv
import sys
import urllib.request

url = 'https://grader.eecs.jacobs-university.de/courses/350112/python/csv/exp200811.csv'
outfile = 'exp200811.csv'

try:
    u = urllib.request.urlretrieve(url, outfile)
    print("Successfully stored the data into " + outfile)
except:
    print("Error fetching URL: ", url)
    sys.exit(1)

f = open("exp200811.csv", "r")
reader = csv.reader(f)

fout = open("wdata4.csv", "w")
writer = csv.writer(fout) 

for row in reader:
    if reader.line_num == 2:
        fout.write("Modified the file with this text\n")
    else:
        writer.writerow(row)

fout.close()
f.close()

print("Successfully modified data into wdata4.csv")
