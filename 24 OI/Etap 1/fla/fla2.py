def find_all_possibilities(Y, distance):
    return list(range(Y-distance, Y+distance+1, 2))

def DFS(index, posibilities):
    global result
    for i in posibilities:
        if result != 0:
            break
        distance = X[index] - X[index - 1]
        next_posibilities = [y for y in find_all_possibilities(i, distance) if
                             Y_max[index] > y > Y_min[index]]
        if next_posibilities and index+1 < obstacles:
            #result += (i - (X[index - 1] - X[index-2]))
            DFS(index+1, next_posibilities)
            #break
        if index+1 == obstacles and next_posibilities:
            result = int((next_posibilities[0] + X[-1])/2)
    # print(posibilities)

if __name__ == "__main__":
    obstacles, lenght = list(map(int, input().split()))
    X = []
    Y_min = []
    Y_max = []
    result = 0
    over = False

    for _ in range(obstacles):
        a, b, c = list(map(int, input().split()))
        X.append(a)
        Y_min.append(b)
        Y_max.append(c)
    # print(X, Y_max, Y_min)
    # print(find_all_possibilities(0, X[0]))

    posibilities = [y for y in find_all_possibilities(0, X[0]) if Y_max[0] > y > Y_min[0]]
    next_posibilities = []
    for i in posibilities:
        next_posibilities = [y for y in find_all_possibilities(i, X[1]-X[0]) if Y_max[1] > y > Y_min[1]]
        if next_posibilities:
            break
    # print(posibilities)
    posibilities = next_posibilities
    DFS(1, posibilities)
    print(result)

'''
4 11
4 1 4
7 -1 2
8 -1 3
9 0 2

5 12
3 0 3
5 0 2
6 -2 4
8 1 4
11 2 4

'''