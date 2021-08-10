if __name__ == '__main__':
    tourist_number = int(input())
    tourist = []
    for _ in range(tourist_number):
        tourist.append(int(input()))
    tourist.sort()
    result = tourist[0]*(tourist_number-2)
    for i in range(1, tourist_number):
        result += tourist[i]
    print(result)
'''
4
6
7
10
15

'''