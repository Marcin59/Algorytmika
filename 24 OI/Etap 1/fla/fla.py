def find_all_possibilities(Y, lenght):
    return list(range(Y-lenght, Y+lenght+1, 2))

if __name__ == "__main__":
    obstacles, lenght = list(map(int, input().split()))
    X = []
    Y_min = []
    Y_max = []
    result = 0

    for _ in range(obstacles):
        a, b, c = list(map(int, input().split()))
        X.append(a)
        Y_min.append(b)
        Y_max.append(c)
    print(X, Y_max, Y_min)
    print(find_all_possibilities(0, X[0]))

    posibilities = [y for y in find_all_possibilities(0, X[0]) if Y_max[0] > y > Y_min[0]]
    next_posibilities = []
    for i in posibilities:
        next_posibilities = [y for y in find_all_possibilities(i, X[1]-X[0]) if Y_max[1] > y > Y_min[1]]
        if next_posibilities:
            break
    print(next_posibilities)
    posibilities = next_posibilities

    for count, actual_X in enumerate(X[1:], 1):
        for i in posibilities:
            next_posibilities = [y for y in find_all_possibilities(i, actual_X - X[count-1]) if Y_max[count] > y > Y_min[count]]
            if next_posibilities:
                break
        print(next_posibilities)
        posibilities = next_posibilities

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