def print_path(graph, node, target, path):
    for neighbour in graph[node]:
        if neighbour == target:
            print(path+[neighbour])
        else:
            print_path(graph, neighbour, target, path+[neighbour])

if __name__ == '__main__':
    graph = {
        'A': ['B', 'C'],
        'B': ['D', 'E'],
        'C': ['F'],
        'D': [],
        'E': ['F'],
        'F': []
    }
    start_node = 'A'
    target = 'F'
    path = [start_node]
    print_path(graph, start_node, target, path)