from math import inf

def cut_rod(p, n):
    if n == 0:
        return 0
    q = -inf
    for i in range(n):
        q = max(q, p[i] + cut_rod(p, n-i-1))
    return q

if __name__ == "__main__":
    data = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
    print(cut_rod(data, 3))