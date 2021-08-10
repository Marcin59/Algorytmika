from collections import defaultdict

if __name__ == "__main__":
    soldiers = int(input())
    number1 = input().split()
    number2 = input().split()
    positions = defaultdict(lambda: [-1, -1])
    for i in range(soldiers):
        if positions[number1[i]][0] == -1:
            positions[number1[i]][0] = i
        else:
            positions[number1[i]][1] = i
        if positions[number2[i]][0] == -1:
            positions[number2[i]][0] = i
        else:
            positions[number2[i]][1] = i
    visited = defaultdict(lambda: False)
    result = 0
    for i in range(soldiers):
        if not visited[i]:
            visited[i] = True
            if number1[i] == number2[i]:
                continue
            black = 0
            white = 1
            j = i
            x = number1[i]
            while True:
                k = positions[x][0]
                if k == j:
                    k = positions[x][1]
                if k == -1:
                    break
                if k == i:
                    break
                if x == number2[k]:
                    white += 1
                    x = number1[k]
                else:
                    black += 1
                    x = number2[k]
                visited[k] = True
                j = k
            if k == -1:
                j = i
                x = number2[i]
                while True:
                    k = positions[x][0]
                    if k == j:
                        k = positions[x][1]
                    if k == -1:
                        break
                    if x == number1[k]:
                        white += 1
                        x = number2[k]
                    else:
                        black += 1
                        x = number1[k]
                    visited[k] = True
                    j = k
            result += min([black, white])
    print(result)
'''                 
9
2 5 5 2 7 4 7 3 9
1 6 8 4 6 3 9 1 8

4
1 4 4 1
2 3 3 5

8
4 4 6 6 8 8 2 2
3 5 5 7 7 9 3 1
=
4
'''