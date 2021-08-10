def check_triangle(a, b, c):
    if a + b <= c:
        return 'NIE'
    if c + b <= a:
        return "NIE"
    if a + c <= b:
        return "NIE"
    return "TAK"

def find_all_combinations(data):
    result = ''
    for i in range(len(data)):
        for j in data[i+1:]:
            for k in data[data.index(j)+1:]:
                result = check_triangle(data[i], j, k)
                if result == "NIE":
                    return result
    return result

def convert_to_float(data):
    convert_data = []
    for number in data:
        if '/' in number:
            a, b = int(number[:number.index('/')]), int(number[number.index('/')+1:])
            convert_data.append(a/b)
        else:
            convert_data.append(number)
    return convert_data

if __name__ == "__main__":
    sides = []
    number = input()
    for i in range(int(number)):
        side = input()
        sides.append(side)
    sides = convert_to_float(sides)
    print(find_all_combinations(sides))
"""
8
13/10
1/2
6/5
11/6
9/7
13/10
9/5
8/5 == NIE

5
1/2
3/5
4/7
1/1
4/6 == TAK
"""

