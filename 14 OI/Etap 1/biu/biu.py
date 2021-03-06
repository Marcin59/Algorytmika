from collections import defaultdict

if __name__ == '__main__':
    workers_number, numbers_number = list(map(int, input().split()))
    numbers = defaultdict(list)
    for _ in range(numbers_number):
        a, b = list(map(int, input().split()))
        numbers[a].append(b)
        numbers[b].append(a)

    print(numbers)

'''
7 16
1 3
1 4
1 5
2 3
3 4
4 5
4 7
4 6
5 6
6 7
2 4
2 7
2 5
3 5
3 7
1 7

'''