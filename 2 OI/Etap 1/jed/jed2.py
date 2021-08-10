def find_number(data):

    numbers = ['0', '1']
    group = '10'
    after_group = 0

    while int(numbers[-1]) % data:

        if len(numbers[after_group]) == len(group):
            group += '0'
            after_group = 0

        numbers.append(group[:-len(numbers[after_group])] + numbers[after_group])

        if len(numbers[-1]) >= 100:
            return "BRAK"

        after_group += 1

    return numbers[-1]

if __name__ == "__main__":
    number_data = int(input())

    for i in range(number_data):
        data = int(input())
        print(find_number(data))


'''
6
17
11011
17
999
125
173
=
11101
11011
11101
111111111111111111111111111
1000
1011001101
'''