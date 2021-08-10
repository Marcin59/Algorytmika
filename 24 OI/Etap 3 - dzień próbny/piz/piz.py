from collections import defaultdict

if __name__ == '__main__':
    graph = defaultdict(list)
    intersections, max_course = list(map(int, input().split()))
    for _ in range(intersections-1):
        a, b, time = list(map(int, input().split()))
        graph[a].append([b, time])
        graph[b].append([a, time])
    print(graph)

'''
7 3
1 2 5
2 3 11
2 4 2
5 2 6
1 6 1
7 1 1

'''