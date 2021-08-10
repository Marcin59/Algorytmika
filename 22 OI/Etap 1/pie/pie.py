import numpy as np

def check_seal():
    writting_rows, writting_columns, seal_rows, seal_columns = list(map(int, input().split()))
    writting = np.array([list(x for x in input()) for _ in range(writting_rows)])
    seal = np.array([list(x for x in input()) for _ in range(seal_rows)])

    # while all(x == '.' for x in seal[0]):
    #     seal = np.delete(seal, 0, 0)
    #
    # while all(x == '.' for x in seal[:, 0]):
    #     seal = np.delete(seal, 0, 1)

    ink_co_ordinates = []
    max_row, max_column = 0, 0

    for row, the_list in enumerate(seal):
        for column, elem in enumerate(the_list):
            if elem == 'x':
                ink_co_ordinates.append([row, column])
                if row > max_row:
                    max_row = row
                if column > max_column:
                    max_column = column
    start = []
    for row, the_list in enumerate(writting):
        for column, elem in enumerate(the_list):
            if elem == 'x':
                 start = [row, column]
                 break
        if elem == 'x':
            break

    for row in range(start[0], writting_rows - max_row):
        for column in range(start[1], writting_columns-max_column):
            for elem in ink_co_ordinates:
                writting[row+elem[0], column+elem[1]] = '.'

    result = np.all(writting == writting[0])

    if result:
        return"TAK"
    else:
        return"NIE"

if __name__ == "__main__":
    iterations = int(input())
    for _ in range(iterations):
        print(check_seal())

'''
2
3 4 4 2
xx..
.xx.
xx..
x.
.x
x.
..
2 2 2 2
xx
xx
.x
x.

1
3 4 2 2
xx..
.xx.
xx..
.x
.x

'''