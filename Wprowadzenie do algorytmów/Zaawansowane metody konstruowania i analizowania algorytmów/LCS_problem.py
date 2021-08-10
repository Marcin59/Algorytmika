def LCS_lenght(X, Y):
    X_lenght = len(X)
    Y_lenght = len(Y)
    lenghts = [[0] * (Y_lenght+1) for _ in range(X_lenght+1)]
    navi = [[None] * (Y_lenght+1) for _ in range(X_lenght+1)]  # 'up', 'left', 'cross'
    for i in range(1, X_lenght+1):
        for j in range(1, Y_lenght+1):
            if X[i-1] == Y[j-1]:
                lenghts[i][j] = lenghts[i-1][j-1]+1
                navi[i][j] = 'cross'
            elif lenghts[i - 1][j] >= lenghts[i][j-1]:
                lenghts[i][j] = lenghts[i-1][j]
                navi[i][j] = 'up'
            else:
                lenghts[i][j] = lenghts[i][j-1]
                navi[i][j] = 'left'
    return lenghts, navi

def print_LCS(navigation, X, i, j):
     if i == 0 or j == 0:
         return
     if navigation[i][j] == "cross":
         print_LCS(navigation, X, i-1, j-1)
         print(X[i-1])
     elif navigation[i][j] == "up":
         print_LCS(navigation, X, i-1, j)
     else:
         print_LCS(navigation, X, i, j-1)

if __name__ == "__main__":
    Y_data = ['B', 'D', 'C', 'A', 'B', 'A', 'A', 'B', 'C', 'B', 'D']
    X_data = ['A', 'B', 'C', 'B', 'D', 'A', 'B']
    lenght, navi = LCS_lenght(X_data, Y_data)
    print(lenght)
    print(navi)
    print_LCS(navi, X_data, len(X_data), len(Y_data))