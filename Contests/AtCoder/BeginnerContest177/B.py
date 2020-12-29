import sys 
# For getting input from input.txt file 
sys.stdin = open('input.txt', 'r')  
  
# Printing the Output to output.txt file 
sys.stdout = open('output.txt', 'w') 

def compute(a,b):
	# print(a,b)
	n = len(a)
	cnt = 0
	for i in range(n):
		if(a[i] == b[i]):
			cnt+=1
	return cnt

s = input()
t = input()
# print(s,t)


sl = len(s)
tl = len(t)

ans = tl

tmp1 = s[0:tl]
tmp2 = t 
# print(compute(tmp1,tmp2))
ans = min(tl - compute(tmp1,tmp2), ans)
# ans = min(tl - compute(tmp1[::-1], tmp2[::-1]), ans)

for i in range(sl-tl):
	tmp1 = s[i:i+tl]
	tmp2 = t
	ans = min(tl - compute(tmp1,tmp2), ans)
	# ans = min(tl - compute(tmp1[::-1], tmp2[::-1]), ans)

print(ans)
