import sys 
# For getting input from input.txt file 
sys.stdin = open('input.txt', 'r')  
  
# Printing the Output to output.txt file 
sys.stdout = open('output.txt', 'w') 

k = int(input())
t = int(input())
for _ in range(t):
	n = int(input())
	sa = 0
	sb = 0
	ans = ['0'] * n
	n1 = n
	while(n > 0):
		if sa >= sb:
			sb+=pow(n,k)
			ans[n-1] = '1'
		else:
			sa+=pow(n,k)
		# print(sa,sb, min(sa,sb))
		# sa -=min(sa,sb)
		# sb -=min(sa,sb)
		n-=1
		# print(sa,sb)
	print(n1,abs(sa-sb))
	s = ''.join(ans)
	print(s)