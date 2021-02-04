
f=open('input.txt','r')
n=int(f.readline())
sold=list(map(int,f.readline().split()))

'''
import sys
n=int(sys.stdin.readline().rstrip())
sold=list(map(int,sys.stdin.readline().rstrip().split()))
'''
sold.reverse()

dp=[1]*n
for i in range(n):
    for j in range(i):
        if sold[j]< sold[i]:
            dp[i]=max(dp[i], dp[j]+1)

print(n-max(dp))