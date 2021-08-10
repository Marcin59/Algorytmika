def decomposition(m, n):
    while m > 0:
        if m >= n:
            print(n)
            m = m - n
        n = n - 1

if __name__ == "__main__":
    decomposition(8, 4)