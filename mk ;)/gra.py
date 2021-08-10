# Marcin Kapiszewski

def find_way(answer):
    movements = infinity_list.copy()
    movements[answer] = 0
    for hole in holes:
        if hole[0] == n:
            movements[n] += 1
        else:
            movements[hole[0]+1] = min(movements[hole[0]+1],  movements[hole[0]])
            movements[hole[0]] = movements[hole[0]+1]+1
    return min(movements)

if __name__ == '__main__':

    n, X, z = list(map(int, input().split()))
    infinity_list = [float('inf')] * (n+2)
    holes = []

    for i in range(1, n+1):
        data = list(map(int, input().split()[1:]))
        for distance in data:
            holes.append((i, distance))
    holes.sort(key=lambda k: k[1])

    for _ in range(z):
        answer = int(input())
        result = find_way(answer)
        print(result)
