import sys 
# For getting input from input.txt file 
sys.stdin = open('input.txt', 'r')  
  
# Printing the Output to output.txt file 
sys.stdout = open('output.txt', 'w') 

a = []
for _ in range(100000000):
	try:
		s = input()
	except:
		break
	a.append(s)

anno = []
comp = []

annot = ['ACov', 'BCov','CCov','DCov','ECov','FCov']
compo = ['A', 'B', 'C', 'D', 'E', 'F']

marks = 0

for ptr in a:
	i = ptr
	while(len(i) < 4):
		i+='#'
	i1 = i.find('(')
	i2 = i.find(')')
	# print(i1,i2)
	if i2 - i1 == 2 and i[-2] in compo and i[-2] not in comp:
		comp.append(i[-2])
		marks += 0.5
	if i[:4] in annot and i[:4] not in anno:
		anno.append(i[:4])
		marks+=0.5

print(marks)