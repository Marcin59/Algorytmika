from collections import defaultdict

if __name__ == '__main__':
    n, m, k = list(map(int, input().split()))
    ways = defaultdict(list)

    for _ in range(m):
        A, B, distance = list(map(int, input().split()))
        ways[A].append([B, distance])
        ways[B].append([A, distance])

    print(ways)

    number_of_constraints = int(input())