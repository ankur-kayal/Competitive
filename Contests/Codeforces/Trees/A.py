R = map(float, input().split(','))
R = sorted(R, reverse=True)
maxD = 42.195
cnt = 0
for i in R:
	if i < maxD:
		print(i)
		cnt+=1
	if cnt == 3:
		break