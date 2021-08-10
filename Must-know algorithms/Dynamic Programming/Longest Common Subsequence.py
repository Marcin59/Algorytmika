'''

LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.

'''

def lcs1(X, Y, m, n):  # Wersja naiwna o pesymistycznej złożoności czasowej O(2^n)(kiedy ciągi nie mają wspólnych cyfr)
    if m == 0 or n == 0:
        return 0
    elif X[m - 1] == Y[n - 1]:
        return 1 + lcs1(X, Y, m - 1, n - 1)
    else:
        return max(lcs1(X, Y, m, n - 1), lcs1(X, Y, m - 1, n))

def lcs2(X, Y, m ,n): # Wersja dynamiczna o złożoności czasowej O(mn)
    L = [[0] * (n + 1) for _ in range(m + 1)]

    """Following steps build L[m+1][n+1] in bottom up fashion 
    Note: L[i][j] contains length of LCS of X[0..i-1] 
    and Y[0..j-1]"""
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i - 1] == Y[j - 1]:
                L[i][j] = L[i - 1][j - 1] + 1
            else:
                L[i][j] = max(L[i - 1][j], L[i][j - 1])
    return L[m][n]

if __name__ == '__main__':
    X = "AGGTAB"
    Y = "GXTXAYB"
    m = len(X)
    n = len(Y)
    result1 = lcs1(X, Y, m, n)
    result2 = lcs2(X, Y, m, n)
    print(result1)
    print(result2)
