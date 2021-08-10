if __name__ == '__main__':
    colors_number = int(input())
    colors = []
    for color in range(1, colors_number+1):
        for lenght in list(map(int, input().split()))[1:]:
            colors.append([lenght, color])
    colors = sorted(colors, key=lambda x: x[0])
    sides = [colors[0][0], -float('inf'), -float('inf')]
    sides_colors = [colors[0][1], 0, 0]
    index = 1
    result = False
    sticks_number = len(colors)
    while True:
        if index >= sticks_number:
            break
        data = colors[index]
        try:
            position = sides_colors.index(data[1])
            for i in range(position-1, -1, -1):
                sides[i+1] = sides[i]
                sides_colors[i+1] = sides_colors[i]
            sides[0] = data[0]
            sides_colors[0] = data[1]
        except:
            for i in range(2 - 1, -1, -1):
                sides[i + 1] = sides[i]
                sides_colors[i + 1] = sides_colors[i]
            sides[0] = data[0]
            sides_colors[0] = data[1]

        if sides[1] + sides[2] > sides[0]:
            result = True
            break
        index += 1

    if result:
        for i in range(3):
            print(sides_colors[i], end=' ')
            print(sides[i], end=' ')
    else:
        print('NIE')
'''
4
1 42
2 6 9
3 8 4 8
1 12

'''