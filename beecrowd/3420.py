'''input
6
10
15
1234567890
1000000000000
1000000000000000
1000000000000000000
'''
import math;
eps = 1e-9

def func(n):
  return n * math.floor((n+1)/2 + eps)

n = int(input())
while (n > 0):
  n -= 1
  c = int(input())
  l = 1
  r = c
  ans = 0
  while (l <= r): 
    mid = math.floor((l+r)/2 + eps)
    val = func(mid)*2 + func(mid-1)
    
    if(val <= c):
      ans = mid
      l = mid+1
    elif(val > c):
      r = mid-1
    
  print(ans)

