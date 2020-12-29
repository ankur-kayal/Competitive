
t = int(input())
for _ in range(t):
	x = int(input())
	start = 0
	ts = 0
	ans = 0
	while(True):
		start = start * 2 + 1;
		ts+=(start * (start + 1) // 2)
		if ts <=x:
			ans+=1
		else:
			break

	print(ans)