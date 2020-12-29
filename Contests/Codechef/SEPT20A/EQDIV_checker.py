import sys 
# For getting input from input.txt file 
sys.stdin = open('input_checker.txt', 'r')  
  
# Printing the Output to output.txt file 
sys.stdout = open('output_checker.txt', 'w') 

t,k = map(int,input().split())
for _ in range(t):
	ans = int(input())
	s = input()
	s = '#' + s;
	sa = 0
	sb = 0
	for i in range(1,len(s)):
		ele = pow(i,k)
		if s[i] == '1':
			sa+=ele
		else:
			sb+=ele 
	if(ans == abs(sa-sb)):
		print("Correct")
	else:
		print("Wrong")

	print(len(s)-1,ans, abs(sa-sb))