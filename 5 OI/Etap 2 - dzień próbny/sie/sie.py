from collections import defaultdict

if __name__ == "__main__":
    cities = int(input())
    connections = defaultdict(list)
    for i in range(cities):
        distances = list(map(int, input().split()))
        for count, distance in enumerate(distances, 1):
            connections[i].append(distance)

    for i in range(cities):
        for j in range(i+1, cities):
            if all(connections[i][j] != connections[j][k] + connections[k][i] for k in range(cities) if k != i and k != j):
                print(i+1, j+1)

'''
3
0 1 2
1 0 3
2 3 0

'''