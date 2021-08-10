from collections import defaultdict

if __name__ == "__main__":
    colors_number = int(input())
    colors = list()
    for _ in range(colors_number*2):
        colors.append(int(input()))
    visited_colors = list()
    visited_colors_boolean = defaultdict(bool)
    colors = colors[::-1]
    result = []
    while colors:
        x = colors.pop()
        if not visited_colors_boolean[x]:
            visited_colors.append(x)
            visited_colors_boolean[x] = True
        else:
            j = len(visited_colors)
            y = visited_colors.pop()
            visited_colors_boolean[y] = False
            if x != y:
                result.append(str(j))
                colors.append(y)
                colors.append(x)
    print(len(result))
    print('\n'.join(result))

'''
5
5
2
3
1
4
1
4
3
5
2
=
2
5
2
'''