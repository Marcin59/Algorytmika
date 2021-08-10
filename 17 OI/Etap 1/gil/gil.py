from collections import defaultdict

def DFS(node, graph, gild='K'):
    visited[node-1] = gild
    for child in graph[node]:
        if visited[child-1] == 'N':
            if gild == 'K':
                DFS(child, graph, 'S')
            else:
                DFS(child, graph, 'K')

def do_graph(n):
    graph = defaultdict(list)
    for _ in range(n):
        a, b = input().split()
        a , b = int(a), int(b)
        graph[a].append(b)
        graph[b].append(a)
    return graph

if __name__ == "__main__":
    cities, roads = list(map(int, input().split()))
    graph = do_graph(roads)
    visited = ['N' for _ in range(cities)]
    if len(graph.keys()) == cities:
        for city in range(1, cities+1):
            if visited[city-1] == 'N':
                DFS(city, graph)
        print('TAK')
        print('\n'.join(visited))
    else:
        print('NIE')
'''
7 8
1 2
3 4
5 4
6 4
7 4
5 6
5 7
6 7

'''