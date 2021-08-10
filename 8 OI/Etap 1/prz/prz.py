if __name__ == '__main__':
    n = int(input())
    compartments = [[0, 0]]
    lenghts = [[0, 0] for _ in range(n+1)]
    for i in range(n):
        a, b = list(map(int, input().split()))
        compartments.append([a, b])
    lenghts.sort(key=lambda x: x[1])
    for count, elem in enumerate(compartments[1:], 1):
        min_before = min(lenghts[count])
        lenghts[count][0] = min(lenghts[count])