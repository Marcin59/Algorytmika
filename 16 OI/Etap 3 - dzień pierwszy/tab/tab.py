if __name__ == '__main__':
    tables = int(input())
    for _ in range(tables):
        m, n = list(map(int, input().split()))
        table1 = set()
        table2 = set()
        for i in range(m):
            table1.add(frozenset(map(int, input().split())))
        for i in range(m):
            table2.add(frozenset(map(int, input().split())))
        if table1 == table2:
            print('TAK')
        else:
            print('NIE')

'''
2
4 3
1 2 3
4 5 6
7 8 9
10 11 12
11 10 12
8 7 9
5 4 6
2 1 3
2 2
1 2
3 4
5 6
7 8

'''