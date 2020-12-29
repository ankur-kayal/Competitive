import sys 
import random
# For getting input from input.txt file 
sys.stdin = open('input_tcgen.txt', 'r')  
  
# Printing the Output to output.txt file 
sys.stdout = open('output_tcgen.txt', 'w') 

t,k = map(int,input().split())
print(k)
print(t)
for i in range(t):
	print(i+1)
