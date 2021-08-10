from math import inf

def botton_up_cut_rod(p, n):
    r = [0]
    for j in range(1, n+1):
        q = -inf
        for i in range(j):
            q = max(q, p[i] + r[j-i-1])
        r.append(q)
    print(r)
    return r[n]

if __name__ == "__main__":
    data = [1, 5, 8, 9, 10, 17, 17, 20, 24, 24]
    print(botton_up_cut_rod(data, 10))