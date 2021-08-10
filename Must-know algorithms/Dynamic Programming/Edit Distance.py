'''

Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost.

'''

def edit_distance1(str1, str2, m, n): # Złożoność przestrzenna O(mn)
    changes = [[0 for _ in range(n+1)] for _ in range(m+1)]

    for i in range(m+1):
        for j in range(n+1):
            if i == 0:
                changes[i][j] = j
            elif j == 0:
                changes[i][j] = i
            elif str1[i-1] == str2[j-1]:
                changes[i][j] = changes[i-1][j-1]
            else:
                changes[i][j] = 1 + min(changes[i][j-1],   # Insert
                                        changes[i-1][j],   # Remove
                                        changes[i-1][j-1])  # Replace
    print(changes)
    return changes[m][n]

def edit_distance2(str1, str2, m, n): # Złożoność przestrzenna O(m)
    changes = [[0 for _ in range(m+1)] for _ in range(2)]

    for i in range(m+1):
        for j in range(n+1):
            if i == 0:
                changes[i%2][j] = j

            elif j == 0:
                changes[i%2][j] = i

            elif str1[i-1] == str2[j-1]:
                changes[i%2][j] = changes[(i-1)%2][j-1]

            else:
                changes[i%2][j] = 1 + min(changes[i%2][j-1],   # Insert
                                        changes[(i-1)%2][j],   # Remove
                                        changes[(i-1)%2][j-1])  # Replace
    print(changes)
    return changes[m%2][n]

if __name__ == '__main__':
    str1 = 'marcin'
    str2 = 'maricn'
    m = len(str1)
    n = len(str2)
    result = edit_distance1(str1, str2, m, n)
    result2 = edit_distance2(str1, str2, m, n)
    print(result)
    print(result2)