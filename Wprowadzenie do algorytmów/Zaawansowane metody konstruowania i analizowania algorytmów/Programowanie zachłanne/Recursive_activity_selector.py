def Recursive_Activity_Selector(s, f, k=0):
    n = len(s)
    m = k+1
    A = [k]
    while m < n and s[m] < f[k]:
        m += 1
    if m < n:
        for i in Recursive_Activity_Selector(s, f, m):
            A.append(i)
        return A
    else:
        return A

if __name__ == '__main__':
    s = [1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12]
    f = [4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16]
    s2 = [1, 3, 0, 5, 8, 5]
    f2 = [2, 4, 6, 7, 9, 9]
    print(Recursive_Activity_Selector(s2, f2))