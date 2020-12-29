import sys 
# For getting input from input.txt file 
sys.stdin = open('input.txt', 'r')  
  
# Printing the Output to output.txt file 
sys.stdout = open('output.txt', 'w') 

for _ in range(int(input())):
	n, k, z = map(int, input().split())
	a = [int(x) for x in input().split()]
	ans = 0
	s = 0
	mx = 0
	for t in range(z + 1):
		pos = k - 2 * t
		if pos < 0:
			continue
		mx = 0
		s = 0
		for i in range(pos + 1):
			if i < n - 1:
				mx = max(mx, a[i] + a[i + 1])
			s += a[i]
			print(i)
		ans = max(ans, s + mx * t)
		print(t,s+mx*t,s,mx)
	print(ans)