f = open("input.txt", 'r')
line = f.readline()
f.close()

s=0
for i in range(len(line)):
    # addition is better, when the number is 1 or 0
    if(int(line[i])<=1 or s<=1): s+=int(line[i])
    else: s*=int(line[i])

print(s)
