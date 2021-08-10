if __name__ == "__main__":
    m, n = list(map(int, input().split()))
    lines = []
    for _ in range(m-1):
        lines.append([int(input()), 'x'])
    for _ in range(n-1):
        lines.append([int(input()), 'y'])
    lines.sort(key=lambda x: x[0], reverse=True)
    X_breaks = 1
    Y_breaks = 1
    result = 0
    for elem in lines:
        if elem[1] == 'x':
            X_breaks += 1
            result += elem[0]*Y_breaks
        else:
            Y_breaks += 1
            result += elem[0] * X_breaks
    print(result)
'''
6 4
2
1
3
1
4
4
1
2

'''