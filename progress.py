#leetcode progress reporter

import sys
import datetime
import time
from time import strptime
from collections import defaultdict
import calendar

offset = 79
total = 331
locked = 58

### Trend by day
mp = {}
f = open('day.log', 'r')
maxnum = 0;
for line in f:
    data = line.split()
    dt = datetime.date(2016,int(strptime(data[0],'%b').tm_mon), int(data[1]));
    mp[dt] = (int(data[2]))

d = datetime.date(2016,2,25);
today = datetime.date.today()  
delta = datetime.timedelta(days=1)
while d <= today:
    s = d.strftime("%b %d")
    if d in mp:
        for k in range(mp[d]):
            s += " "
    s += "|"
    print s
    d += delta



### Num of today & past 3 days
if today in mp:
    print "Today: "+str(mp[today])
else:
    print "Today: 0"

d = today-delta
s = "Past 3 days: "
for i in range(3):
    if d in mp:
        s+=str(mp[d])
    else:
        s += "0"
    s+=" "
    d -= delta
s += "<- LRU"
print s


### Num of problems completed
cnt = offset+int(sys.argv[1])
left = total-cnt-locked;
print str(cnt)+"/"+str(total)+" accepted"
print str(cnt-offset) + " this semester"
print str(offset) + " other time"
#print str(total-cnt)+"/"+str(total)+" left"
print str(left)+"/"+str(total)+" left"


### problem per day
d1 = datetime.date(2016,2,25)  
d2 = datetime.date.today()  
d = (d2-d1).days  
print str(d)+" days from begin"
perday = float(cnt-offset)/float(d)
print str(round( perday, 2)) + "/day"
needdays = round((left)/perday,2);
print str(needdays) + " more days needed (" + str(round(needdays/30,2))+" months)"
print "Expected finish date: "+str(d2+datetime.timedelta(int(needdays)))



### Progress bar
progress = 100*cnt/total
s = str(progress) + "%: " 
for i in range(0,50):
    if (100*i/50) > progress:
        s = s+"-"
    else:
        s = s+">"
s += "offer(?)"
print s



### Drink thick(poisonous?) chicken soup
print "play(work?) harder, do more!!!"
