
f=open('input.txt','r')
n,c=map(int,f.readline().split())
home=list()
for _ in range(n):
    home.append(int(f.readline()))
'''
import sys
n,c = map(int,sys.stdin.readline().rstrip().split())
home=list()
for _ in range(n):
    home.append(int(sys.stdin.readline().rstrip()))
'''

home.sort()
    
min_gap = home[1]-home[0]
max_gap = home[-1]-home[0]
for i in range(1,n):
    min_gap=min(min_gap, home[i]-home[i-1])
    max_gap=max(max_gap, home[i]-home[i-1])
    #print(home[i]-home[i-1])

#print(min_gap, max_gap)
res = 0
while min_gap <= max_gap:
    gap=(max_gap+min_gap)//2
    curr=home[0]
    cnt=1
    for h in home[1:]:
        if curr+gap <= h:
            print(h,curr,gap)
            curr=h
            cnt+=1
    #print(cnt, c)
    if cnt >=c:
        min_gap =gap+1
        res = gap
    else:
        max_gap =gap-1
print(res)