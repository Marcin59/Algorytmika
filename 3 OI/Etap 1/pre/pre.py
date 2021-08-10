from math import sqrt

def calculate_deviation():
    L = original_lenght + change
    c = original_lenght
    return sqrt((L**2 - c**2)*3/16)

if __name__ == "__main__":
    number_data = int(input())
    for _ in range(number_data):
        data = [int(x) for x in input().split()]
        original_lenght, change = data
        print(round(calculate_deviation()))

'''
2
1000 20
15000 10
=
87
237
'''