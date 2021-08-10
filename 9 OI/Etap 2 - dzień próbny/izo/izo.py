if __name__ == '__main__':
    insulators_number = int(input())
    insulators = []
    for _ in range(insulators_number):
        insulators.append(int(input()))
    insulators = sorted(insulators)
    result = 0
    if not insulators_number%2:
        print(sum(insulators[int(insulators_number/2):])*2)
    else:
        print(sum(insulators[int(insulators_number/2)+1:])*2 + insulators[int(insulators_number/2)])