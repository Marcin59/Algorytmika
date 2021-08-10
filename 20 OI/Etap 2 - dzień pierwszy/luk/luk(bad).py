from collections import defaultdict

if __name__ == '__main__':
    cities = int(input())
    graph = defaultdict(list)
    for _ in range(cities-1):
        a, b = list(map(int, input().split()))
        graph[a].append(b)
        graph[b].append(a)

    queue = [1]
    visited = [1]
    result = 0
    new_result = 0
    free = 0
    while queue:
        new_queue = []
        if result - len(queue) >= 0:
            free += result - len(queue)
        elif free <= len(queue):
            new_result = len(queue) - free
            free = 0
        else:
            new_result = 0
            free -= new_result

        result = max(result, new_result)
        for parent in queue:
            for child in graph[parent]:
                if child not in visited:
                    new_queue.append(child)
                    visited.append(child)

        queue = new_queue

    print(result)

'''
7
1 2
1 3
2 5
2 6
7 2
4 1

'''