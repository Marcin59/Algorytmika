def findSccs():
    for i in range(n):
        if ids[i] == unvisited:
            DFS(i)
    return low

def DFS(at):
    global ID, sccCount
    stack.append(at)
    onStack[at] = True
    ids[at] = low[at] = ID
    ID += 1

    keys = list(graph.keys())
    key = keys[at]
    for neighbour in graph[key]:
        neighbour = keys.index(neighbour)
        if ids[neighbour] == unvisited:
            DFS(neighbour)
        if onStack[neighbour]:
            low[at] = min(low[at], low[neighbour])

    if ids[at] == low[at]:
        for _ in range(len(stack)):
            node = stack.pop()
            onStack[node] = False
            low[node] = ids[at]
            if node == at:
                break
        sccCount += 1

# Driver Code
if __name__ == '__main__':
    # Using a Python dictionary to act as an adjacency list
    graph = {
        'A': ['B', 'E'],
        'B': ['F'],
        'C': ['B', 'D', 'G'],
        'D': ['G'],
        'E': ['A', 'F'],
        'F': ['C', 'G'],
        'G': ['H'],
        'H': ['D']
    }
    unvisited = -1
    n = len(graph.keys())
    ID = 0
    sccCount = 0

    ids = [unvisited for _ in range(n)]
    low = [0 for _ in range(n)]
    onStack = [False for _ in range(n)]
    stack = []

    print(findSccs())

    # https://www.youtube.com/watch?v=wUgWX0nc4NY
