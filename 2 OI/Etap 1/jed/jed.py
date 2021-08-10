def find_number(data):

    original_data = data

    while any(x != '0' and x != '1' for x in str(data)):

        data += original_data

        if len(str(data)) >= 100:
            return "BRAK"

    return data

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