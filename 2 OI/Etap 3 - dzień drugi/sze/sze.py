if __name__ == "__main__":
    n = int(input())
    a = []
    b = []
    for _ in range(n):
        data = list(map(float, input().split()))
        a.append(data[0])
        b.append(data[1])
    result = list(range(1, n+1))
    for i in range(n-1, 0, -1):
        for j in range(i):
            if a[j]*b[j+1] < a[j+1]*b[j]:
                a[j], a[j+1] = a[j+1], a[j]
                b[j], b[j+1] = b[j+1], b[j]
                result[j], result[j+1] = result[j+1], result[j]
    for i in range(n):
        print(result[i])

'''
5
0.002000 0.003000
0.016000 0.001000
0.100000 0.300000
0.016000 0.005000
0.030000 0.060000

'''