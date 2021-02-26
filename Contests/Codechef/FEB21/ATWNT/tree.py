import sys
sys.setrecursionlimit(10**5+1)

M = (10**5 + 1)

vec = []
factor = []
renumbered = []
maxTask = 10**6

def reshape(node):
    if len(vec[node]) == 1:
        return reshape(vec[node][0])
    return vec[node]

def findFactor(node):
    s = len(vec[node])
    if s==0:
        factor[node][1] = 1
        return

        
    for i in vec[node]:
        findFactor(i)
        if s != 1:
            for j in factor[renumbered[i]]:
                if s*j <= maxTask:
                    if s*j in factor[node]:
                        factor[node][s*j] += factor[renumbered[i]][j]
                    else:
                        factor[node][s*j] = factor[renumbered[i]][j]

    if s == 1:
        renumbered[node] = renumbered[vec[node][0]]
                
                
                
def Task(node, a):
    node = renumbered[node]
    c = 0
    for i in factor[node]:
        if a % i == 0:
            c += (int(a/i) * factor[node][i])
            
    return (a - c)
    
n = int(input())
vec = [[] for _ in range(n+1)]
factor = [{} for _ in range(n+1)]
vertex = list(map(int, input().split()))
renumbered = [ i for i in range(n + 1)]
index = 1
for i in vertex:
    vec[i].append(index+1)
    index += 1

# for i in range(1, n+1):
#     vec[i] = reshape(i);
    
findFactor(1)
q = int(input())
while q>0:
    q -= 1
    v, a = map(int, input().split())
    print(Task(v, a))
    
# print(factor)
# print(vec)
# print(renumbered)
