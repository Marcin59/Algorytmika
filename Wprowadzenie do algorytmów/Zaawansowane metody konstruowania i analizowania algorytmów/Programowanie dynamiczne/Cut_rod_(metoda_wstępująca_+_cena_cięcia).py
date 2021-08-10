def botton_up_cut_rod(p, n, cut_price):
    r = [0]+p[:n]
    for j in range(1, n+1):
        q = r[j]
        for i in range(j-1):
            q = max(q, p[i] + r[j - i - 1] - cut_price)
        r[j] = q
    print(r)
    return r[n]

if __name__ == "__main__":
    data = [1, 5, 8, 9, 10, 17, 17, 20, 24, 24]
    cut_price = 1
    print(botton_up_cut_rod(data, 10, cut_price))