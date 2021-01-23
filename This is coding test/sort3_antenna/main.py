f = open("input.txt", 'r')
n = int(f.readline())
home = list(map(int,f.readline().split()))
f.close()
'''
import sys
n = int(sys.stdin.readline().rstrip())
home = list(map(int,sys.stdin.readline().rstrip().split()))
'''

home.sort()

print(home[(n-1)//2])