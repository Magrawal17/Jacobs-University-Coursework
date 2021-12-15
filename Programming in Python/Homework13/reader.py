import csv
import datetime

def extract_time(row):
    y = int(row[1])
    mn = int(row[2])
    d = int(row[3] )
    h,m = row[4].split(':')
    h = int(h)
    m = int(m)
    return datetime.datetime(y, mn, d, h, m)

def extract_temp(row) :
    t = row[5] 
    try :
        return float(t)
    except :
        return None

def extract_rel_humidity(row) :
    rh = row[9]
    try :
        return float(rh)
    except :
        return None

def extract_wind_dir(row) :
    wd = row[11]
    try :
        return float(wd) * 10.0
    except :
        return None

def extract_wind_speed(row) :
    sp = row[13]
    try :
        return float(sp)
    except :
        return None

def extract_pressure(row) :
    p = row[17]
    try :
        return float(p)
    except :
        return None

def extract_description(row) :
    return row[23]

f = open("oct.csv", "r")
reader = csv.reader(f)
name = next(reader)[1]
print('name=', name)
prov = next(reader)[1]
print('prov=', prov)
latitude = next(reader)[1]
print('latitude=', latitude)
longitude = next(reader)[1]
print('longitude=', longitude)
elevation = next(reader)[1]
print('elevation=', elevation)

# skip to line 16
# the line number of the input file is maintained in line_num
while reader.line_num < 16 :
    next(reader)

headers = next(reader)
print(headers)

fout = open("reduced.csv", "w")
writer = csv.writer(fout) 

writer.writerow( ('time', 'temp', 'humidity', 'wind dir',
                'wind speed', 'pressure',  'desc' ) )

for row in reader:
    t = extract_time(row)
    if not t:
        continue
    temp = extract_temp(row) 
    if not temp:
        continue
    h = extract_rel_humidity(row) 
    if not h:
        continue
    wd = extract_wind_dir(row)
    if not wd:
        continue
    ws = extract_wind_speed(row)
    if not ws:
        continue
    press = extract_pressure(row)
    if not press:
        continue
    description = extract_description(row)
    if not description:
        continue
    writer.writerow((t, temp, h, wd, ws, press, description))
fout.close()
f.close()

