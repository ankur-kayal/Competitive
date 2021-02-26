import sys
import math
from collections import deque

sys.setrecursionlimit(100000)

n = int(input())

adj = [[] for i in range(n + 1)]
new_node_id = [ i for i in range(n + 1)]
dividing_factor = [ {} for i in range(n + 1)]
count_children = [0 for i in range(n + 1)]
parent = [0, 0]
maxW = 1000000
# ignored = 541313 #garbage value remember to reset after each query


def dfs(node, height):
    has_one_child = False
    if count_children[node] == 1:
        has_one_child = True

    if count_children[node] == 0:
        dividing_factor[node][1] = 1;
        return

    for child in adj[node]:
        dfs(child, height + 1)

        if not has_one_child:
            for key in dividing_factor[new_node_id[child]]:
                value = dividing_factor[new_node_id[child]].get(key)
                if key * count_children[node] <= maxW:
                    if dividing_factor[node].get(key * count_children[node], -1) == -1:
                        dividing_factor[node][key * count_children[node]] = 0
                    dividing_factor[node][key * count_children[node]] += value

    if has_one_child:
        new_node_id[node] = new_node_id[adj[node][0]]


def calculate(node, tasks):
    ignored = tasks
    if count_children[node] == 0:
        return 0
    if tasks % count_children[node] == 0:
        for key in dividing_factor[node]:
            if tasks % key == 0:
                ignored -= (tasks // key) * dividing_factor[node].get(key)

    return ignored



parent = parent + list(map(int,input().split()))
for i in range(2, n+1):
    adj[parent[i]].append(i)
    count_children[parent[i]] += 1


dfs(1, 1)

# print(dividing_factor)

Q = int(input())
for _ in range(Q):
    vertex, task = list(map(int,input().split()))


    print(calculate(new_node_id[vertex], task))
