import sys 
# For getting input from input.txt file 
sys.stdin = open('input.txt', 'r')  
  
# Printing the Output to output.txt file 
sys.stdout = open('output.txt', 'w') 

def allEqual(initial, final, config, answer):
    index1, index2, index3 = config
    if initial[index1] == final[index1] and initial[index2] == final[index2] and initial[index3] == final[index3]:
        answer = min(0, answer)
    return answer
        
def oneEqual(initial, final, config, answer):
    index1, index2, index3 = config
    if initial[index1] == final[index1]:
        if final[index2] - initial[index2] == final[index3] - initial[index3]:
            answer = min(1, answer)
        if initial[index2] != 0 and initial[index3] != 0 and  final[index2] % initial[index2] == 0 and final[index3] % initial[index3] == 0 and final[index2] // initial[index2] == final[index3] // initial[index3]:
            answer = min(1, answer)
        answer = min(2,answer)
    return answer
            
def twoEqual(initial, final, config, answer):
    index1, index2, index3 = config
    # answer = min(1,answer)
    if initial[index1] == final[index1] and initial[index2] == final[index2] and initial[index3] != final[index3]:
        answer = min(1, answer)
        
    return answer
        
def plusMultiply(initial, final, config, answer):
    index1, index2, index3 = config
    if initial[index3] != 0 and final[index3] % initial[index3] == 0 :
        plus = final[index1] - initial[index1]
        multiply = final[index3] // initial[index3]
        if (initial[index2] + plus) * multiply == final[index2]:
            answer = min(2, answer)
            
    return answer
            
def multiplyPlus(initial, final, config, answer):
    index1, index2, index3 = config
    if initial[index1] != 0 and final[index1] % initial[index1] == 0:
        plus = final[index3] - initial[index3]
        multiply = final[index1] // initial[index1]
        if (initial[index2] * multiply) + plus == final[index2]:
            answer = min(2, answer)
    return answer
            
            
def plusPlus(initial, final, config, answer):
    index1, index2, index3 = config
    plus1 = final[index1] - initial[index1]
    plus2 = final[index3] - initial[index3]
    if initial[index2] + plus1 + plus2 == final[index2]:
        answer = min(2, answer)
    return answer
        
def multiplyMultiply(initial, final, config, answer):
    index1, index2, index3 = config
    if initial[index1] != 0 and initial[index3] != 0 and final[index3] % initial[index3] == 0 and final[index1] % initial[index1] == 0:
        multiply1 = final[index1] // initial[index1]
        multiply2 = final[index3] // initial[index3]
        if initial[index2] * multiply1 * multiply2 == final[index2]:
            answer = min(2, answer)
    return answer


def plus(initial, final, config, answer):
    index1, index2, index3 = config
    if final[index1] - initial[index1] == final[index2] - initial[index2] and final[index1] - initial[index1] == final[index3] - initial[index3]:
        answer = min(1, answer)
    if initial[index1] != 0 and initial[index2] != 0 and initial[index3] != 0 and final[index1] % initial[index1] == 0 and final[index2] % initial[index2] == 0 and final[index3] % initial[index3] == 0:
        if final[index1] // initial[index1] == final[index2] // initial[index2] and final[index1] // initial[index1] == final[index3] // initial[index3]:
            answer = min(1, answer)
    return answer
            
def plus3mul2(initial, final, config, answer):
    index1, index2, index3 = config
    plus = final[index1] - initial[index1]
    if (initial[index2] + plus) != 0 and (initial[index3] + plus) != 0 and final[index2] % (initial[index2] + plus) == 0 and final[index3] % (initial[index3] + plus) == 0 and  final[index2] // (initial[index2] + plus) == final[index3] // (initial[index3] + plus):
        answer = min(2, answer)
    if final[index2] - initial[index2] == plus and (initial[index3] + plus) != 0 and final[index3] % (initial[index3] + plus) == 0:
        answer = min(2, answer)
    if initial[index1]!=0 and final[index1] % initial[index1] == 0:
        multiply = final[index1] // initial[index1]
        if final[index2] - multiply * initial[index2] == final[index3] - multiply * initial[index3]:
            answer = min(2, answer)
        if initial[index2] != 0 and final[index2] % initial[index2] == 0 and final[index2] // initial[index2] == multiply:
            answer = min(2, answer)
    return answer

def allPlusMultiply(initial, final, config, answer):
    index1, index2, index3 = config
    num1 = final[index1] - final[index2]
    num2 = final[index2] - final[index3]
    num3 = final[index3] - final[index1]
    deno1 = initial[index1] - initial[index2]
    deno2 = initial[index2] - initial[index3]
    deno3 = initial[index3] - initial[index1]
    
    if deno1 != 0 and deno2 !=0 and deno3!= 0 and num1 % deno1 == 0 and num2 % deno2 == 0 and num3 % deno3 == 0:
        if num1 // deno1 == num2 // deno2 and num1 // deno1 == num3 // deno3:
            answer = min(2, answer)
    return answer
            
t = int(input())
for _ in range(t):
    initial = list(map(int,input().split()))
    final = list(map(int,input().split()))
    config = [[0,1,2],[0,2,1],[1,0,2],[1,2,0],[2,1,0],[2,0,1]]
    answer = 3
    for i in config:
        answer = min(answer, allEqual(initial, final, i, answer))
        answer = min(answer, oneEqual(initial, final, i, answer))
        answer = min(answer, twoEqual(initial, final, i, answer))
        answer = min(answer, plusMultiply(initial, final, i, answer))
        answer = min(answer, plus(initial, final, i, answer))
        answer = min(answer, multiplyMultiply(initial, final, i, answer))
        answer = min(answer, multiplyPlus(initial, final, i, answer))
        answer = min(answer, plus3mul2(initial, final, i, answer))
        answer = min(answer, plusPlus(initial, final, i, answer))
        answer = min(answer, allPlusMultiply(initial, final, i, answer))
    print(answer)
    