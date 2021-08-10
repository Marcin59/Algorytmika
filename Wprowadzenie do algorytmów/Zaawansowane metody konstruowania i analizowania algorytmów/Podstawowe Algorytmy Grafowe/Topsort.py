def topsort(graph):

    N = len(graph)
    V = [False for _ in range(N)]
    ordering = [None for _ in range(N)]
    i = N-1

    for at in range(N):
        if V[at] == False:
            visitedNodes = []
            DFS(at, V, visitedNodes, graph)
            for nodeId in visitedNodes:
                ordering[i] = nodeId
                i = i-1
    return ordering

def DFS(at, V, visitedNodes, graph):

    V[at] = True
    key = list(graph.keys())[at]

    for neighbour in graph[key]:
        index = list(graph.keys()).index(neighbour)
        if V[index] == False:
            DFS(index, V, visitedNodes, graph)
    visitedNodes.append(at)

# Driver Code
if __name__ == '__main__':
    # Using a Python dictionary to act as an adjacency list
    graph = {
        'A': ['B', 'C'],
        'B': ['D', 'E'],
        'C': ['F'],
        'D': [],
        'E': ['F'],
        'F': []
    }
    data = {
        'Skarpetki': ['Buty'],
        'Buty': [],
        'Slipki': ['Buty', 'Spodnie'],
        'Spodnie': ['Buty', 'Pasek'],
        'Pasek': ['Marynarka'],
        'Koszula': ['Pasek', 'Krawat'],
        'Krawat': ['Marynarka'],
        'Marynarka': [],
        'Zegarek': []
    }

    visited = set()  # Set to keep track of visited nodes.
    keys = list(data.keys())
    result = topsort(data)
    for i in result:
        print(keys[i], end=' ')
