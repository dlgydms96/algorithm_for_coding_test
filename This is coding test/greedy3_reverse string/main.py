'''
f = open("input.txt", 'r')
line = f.readline()
f.close()
'''
line=input()
cnt=0
for i in range(len(line)):
    if(i==0): s=int(line[i])
    if(not s==int(line[i]) and int(line[i-1]) != int(line[i])): cnt+=1

print(cnt)
