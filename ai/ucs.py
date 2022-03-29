# Uniform Cost Search (directed graph)
import heapq

def ucs(start, end, graph):
    node = start
    frontier = [[0,node]]
    heapq.heapify(frontier)
    explored = []
    while 1:
        if not frontier:
            return -1
        wt, node = frontier.pop(0);
        if node == end:
            return wt
        for wt1,node1 in graph[node]:
            heapq.heappush(frontier, [wt+wt1,node1])

gr = {
    1: [[4,2],[5,4]],
    2: [[2,3],[1,4]],
    3: [],
    4: [[1,3]]
}

print("Shortest: ",ucs(1,3,gr))
