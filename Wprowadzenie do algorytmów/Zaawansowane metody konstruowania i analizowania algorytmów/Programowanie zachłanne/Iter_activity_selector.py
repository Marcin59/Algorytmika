def printMaxActivities(s, f):
    n = len(f)
    i = 0
    A = [i]

    for j in range(n):

        if s[j] >= f[i]:
            A.append(j)
            i = j
    return A

if __name__ == '__main__':
    s = [1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12]
    f = [4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16]
    s2 = [1, 3, 0, 5, 8, 5]
    f2 = [2, 4, 6, 7, 9, 9]
    print(printMaxActivities(s2, f2))

# This code is contributed by Nikhil Kumar Singh