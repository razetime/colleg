# Best first search
import heapq

def bestfirst(start, end, graph):
    visited = [False for i in range(len(graph)+1)]
    print
    pq = [[0,start]]
    heapq.heapify(pq)
    while pq:
        wt,u = heapq.heappop(pq)
        if u == end:
            return wt
        else:
            for wt,v in graph[u]:
                if not visited[v]:
                    visited[v] = True
                    heapq.heappush(pq,[wt,v])

gr = {
    1: [[4,2],[5,4]],
    2: [[2,3],[1,4]],
    3: [],
    4: [[1,3]]
}
print("Shortest: ",bestfirst(1,3,gr))
                    
                    
                
