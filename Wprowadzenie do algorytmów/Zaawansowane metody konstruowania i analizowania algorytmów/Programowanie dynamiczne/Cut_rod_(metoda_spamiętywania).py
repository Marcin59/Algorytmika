from math import inf

def memorized_cut_rod(p, n):
    memorized_data = [-inf] * (n+1)
    memorized_data[0] = 0
    return memorized_cut_rod_aux(p, n, memorized_data)

def memorized_cut_rod_aux(p, n, r):
    if r[n] >= 0:
        return r[n]
    q = -inf
    for i in range(n):
        q = max(q, p[i] + memorized_cut_rod_aux(p, n-i-1, r))
    r[n] = q
    print(r)
    return q

if __name__ == "__main__":
    data = [1, 5, 8, 9, 10, 17, 17, 20, 24, 24]
    print(memorized_cut_rod(data, 10))
