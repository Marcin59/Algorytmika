def find_string(number):
    result = [number]
    while result[-1] != 1 and result[-1] != 4:
        new_number = 0
        for i in str(result[-1]):
            new_number += int(i) * int(i)
        result.append(new_number)
    return result
if __name__ == "__main__":

    quantity_numbers = int(input())

    for _ in range(quantity_numbers):
        print(*find_string(int(input())))



'''
3
33
17
638
=
33 18 65 61 37 58 89 145 42 20 4
17 50 25 29 85 89 145 42 20 4
638 109 82 68 100 1
'''
