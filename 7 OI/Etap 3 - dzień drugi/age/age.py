from collections import defaultdict

if __name__ == "__main__":
    cities, roads = list(map(int, input().split()))
    graph = defaultdict(list)
    visited = set()
    agent1, agent2 = list(map(int, input().split()))
    for _ in range(roads):
        A, B = list(map(int, input().split()))
        graph[A].append(B)
    queue = [[agent1, agent2]]
    result = 0
    i = 1
    while queue and queue[0][0] != queue[0][1]:
        i -= 1
        for agent1_road in graph[queue[0][0]]:
            for agent2_road in graph[queue[0][1]]:
                if (agent1_road, agent2_road) not in visited:
                    queue.append([agent1_road, agent2_road])
                    visited.add((agent1_road, agent2_road))
        queue.pop(0)
        if i == 0:

            i = len(queue)
            result += 1
    print(result)
'''
6 7
1 5
1 2
4 5
2 3
3 4
4 1
5 4
5 6

'''