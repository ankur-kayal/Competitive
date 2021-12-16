def main():
    pass



if __name__ == "__main__":
    import sys, threading
    import bisect
    import math
    import itertools
    from sys import stdout
 
    ############  Sorted Containers  ######################
    import heapq
    from queue import PriorityQueue
    from collections import OrderedDict
 
    ############ Tree Problems ( Use Python 3) ###########
    sys.setrecursionlimit(2 ** 32 // 2 - 1)
    threading.stack_size(1 << 27)
 
    input = sys.stdin.readline
    thread = threading.Thread(target=main)
    thread.start()
    thread.join()

