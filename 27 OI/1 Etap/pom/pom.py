def change_digit(str, index,  new_value):
    return str[:index]+new_value+str[index+1:]

def find_result():
    a, b, number_of_changes = input().split()
    number_of_changes = int(number_of_changes)

if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        find_result()


'''
4
555 333 1
0555 0551 3
0555 0333 4
9 9 1

'''