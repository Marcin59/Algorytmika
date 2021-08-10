if __name__ == "__main__":
    n = int(input())
    a = []
    b = []
    for _ in range(n):
        data = list(map(float, input().split()))
        a.append(data[0])
        b.append(data[1])
    result = list(range(1, n+1))
    print(sorted(range(n), key=lambda k: a[k]*b[k-1]))
'''
5
0.002000 0.003000
0.016000 0.001000
0.100000 0.300000
0.016000 0.005000
0.030000 0.060000

'''