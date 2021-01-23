import sys
n = int(sys.stdin.readline().rstrip())
student=[]
for _ in range(n):
    g = list(sys.stdin.readline().rstrip().split())
    student.append((100-int(g[1]),int(g[2]),100-int(g[3]),g[0]))

    
student.sort()
for st in student: print(st[3])