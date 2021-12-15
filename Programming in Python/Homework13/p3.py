import csv
import datetime

def extract_datetime(row):
    date = row[0].split(".")
    d = int(date[0])
    mn = int(date[1])
    y = int(date[2])
    
    time = row[1].split(":")
    h = int(time[0])
    m = int(time[1])
    return datetime.datetime(y, mn, d, h, m)

def extract_temp(row) :
    t = row[2] 
    try :
        return float(t)
    except :
        return None

def extract_rel_humidity(row) :
    rh = row[3]
    try :
        return float(rh)
    except :
        return None

def extract_wind_dir(row) :
    wd = row[7]
    try :
        return float(wd)
    except :
        return None

def extract_wind(row) :
    sp = row[6]
    try :
        return float(sp)
    except :
        return None

f = open("exp200803.csv", "r")
reader = csv.reader(f)

fout = open("wdata2.csv", "w")
writer = csv.writer(fout) 

writer.writerow( ('time', 'temp', 'humidity', 'wind', 'direction') )

for row in reader:
    if row[0] == "11.03.2008":
        t = extract_datetime(row)
        if not t:
            continue
        temp = extract_temp(row) 
        if not temp:
            continue
        h = extract_rel_humidity(row) 
        if not h:
            continue
        w= extract_wind(row)
        if not w:
            continue
        wd = extract_wind_dir(row)
        if not wd:
            continue
        writer.writerow((t, temp, h, w, wd))
fout.close()
f.close()
