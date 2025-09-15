import re

f=open('mbox2.txt','r')
text='X-'
lines=f.readlines()
print("hello")
for line in lines:
    if text in line:
        line=line.split()
        if text in line[0]:
            print(line)