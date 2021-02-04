def binary_search(array, target, start, end):
    while start<=end:
        mid=(end-start)//2
        if array[mid]==target: return mid
        elif mid<=target:
            return binary_search(array, target, mid+1, end)
        else:
            return binary_search(array, target, start, mid-1)
    return None
import sys
n, target= map(int, sys.stdin.readline().rstrip().split())
array=list(map(int, sys.stdin.readline().rstrip().split()))
result=binary_search(array, target, 0, n-1)

if result==None:
    print("원소가없듬")
else:
    print(result+1)