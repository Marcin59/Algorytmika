# Marcin Kapiszewski

def change_string(string, start_index, new_value):
    if start_index == -1:
        return string[:start_index] + new_value
    return string[:start_index] + new_value + string[start_index+1:]

def change_digit(data):
    global input_debt, output_debt, debt
    index = -int(data[1])
    new_value = int(data[2])
    if data[0] == 'W':
        difference = new_value - int(input_debt[index])
        input_debt = change_string(input_debt, index, data[2])
    else:
        difference = new_value - int(output_debt[index])
        output_debt = change_string(output_debt, index, data[2])

    number = int(debt[index]) + difference
    str_number = str(number)
    if number >= 10:
        debt = change_string(debt, index, str_number[1])
        while debt[index-1] == '9':
            debt = change_string(debt, index-1, '0')
            index -= 1
        debt = change_string(debt, index-1, str(int(debt[index-1]) + 1))
    elif number >= 0:
        debt = change_string(debt, index, str_number)
    else:
        debt = change_string(debt, index, str(10 + number))
        while debt[index - 1] == '0':
            debt = change_string(debt, index - 1, '9')
            index -= 1
        debt = change_string(debt, index - 1, str(int(debt[index - 1]) - 1))


if __name__ == "__main__":
    n, z = list(map(int, input().split()))
    input_debt = input()
    output_debt = input()
    the_sum = str(int(input_debt) + int(output_debt))
    debt = '0'*(n - len(the_sum)) + the_sum

    for _ in range(z):
        data = input().split()
        if data[0] == 'S':
            print(debt[-int(data[1])])
        else:
            change_digit(data)
