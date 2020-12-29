import sys 
# For getting input from input.txt file 
sys.stdin = open('input.txt', 'r')  
  
# Printing the Output to output.txt file 
sys.stdout = open('output.txt', 'w') 

def binary(n):
	binn = bin(n)[2:]
	while(len(binn) < 25):
		binn = '0' + binn
	return binn

t = int(input())
for _ in range(t):
	x,y,l,r = map(int,input().split())
	val = -1
	ans = 0
	for i in range(l,r+1):
		tmp = (x & i) * (y & i)
		if tmp > val:
			ans = i
			val = tmp
	print(ans)
	binx = binary(x)
	biny = binary(y)
	bina = binary(ans)
	print("x",binx,x)
	print("y",biny,y)
	print("o",binary(x | y),(x|y))
	print("r",binary(r),r)
	print("a",bina,ans)
	print("e",binary((x|y)&r),((x|y)&r))
	print((x|y) - ans)
	print((x|y) - r)