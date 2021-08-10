def longestPalSubstr(st):
    n = len(st)  # get length of input string

    # table[i][j] will be false if substring
    # str[i..j] is not palindrome. Else
    # table[i][j] will be true
    table = [[0 for _ in range(n)] for _
             in range(n)]

    # All substrings of length 1 are
    # palindromes
    for i in range(n):
        table[i][i] = True

    # check for sub-string of length 2.
    start = 0

    for i in range(n-1):
        if (st[i] == st[i + 1]):
            table[i][i + 1] = True
            start = i
            maxLength = 2

    # Check for lengths greater than 2.
    # k is length of substring
    k = 3
    while k <= n:
        # Fix the starting index
        i = 0
        while i < (n - k + 1):

            # Get the ending index of
            # substring from starting
            # index i and length k
            j = i + k - 1

            # checking for sub-string from
            # ith index to jth index iff
            # st[i + 1] to st[(j-1)] is a
            # palindrome
            if (table[i + 1][j - 1] and
                    st[i] == st[j]):
                table[i][j] = True

                if (k > maxLength):
                    start = i
                    maxLength = k
            i = i + 1
        k = k + 1
    print("Longest palindrome substring is: ")
    print(st[start:start + maxLength - 1])

    return maxLength  # return length of LPS

# Driver program to test above functions
if __name__ == "__main__":
    st = "forgeeksskeegfor"
    l = longestPalSubstr(st)
    print("Length is:", l)
