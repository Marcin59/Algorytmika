def DFS(visited, graph, node):
    if node not in visited:
        print(node)
        visited.add(node)
        for neighbour in graph[node]:
            DFS(visited, graph, neighbour)

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
    DFS(visited, data, 'Slipki')