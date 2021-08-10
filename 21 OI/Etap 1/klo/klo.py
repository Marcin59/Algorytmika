if __name__ == "__main__":
    colors_number, first_color, last_color = map(int, input().split())
    colors = [0] + list(map(int, input().split()))
    all_blocks = sum(colors)
    colors[last_color] -= 1
    result = [0]
    while result and len(result) < all_blocks:
        if colors[first_color] > 0:
            result.append(first_color)
            colors[first_color] -= 1
            if result[-1] == result[-2]:
                result = False
                break
        if colors[last_color] > 0:
            result.append(last_color)
            colors[last_color] -= 1
            if result[-1] == result[-2]:
                result = False
                break
        for i in range(1, len(colors)):
            if i != first_color and i != last_color:
                if colors[i] > 0:
                    result.append(i)
                    colors[i] -= 1
                    if result[-1] == result[-2]:
                        result = False
                        break
            if not result:
                break

    if result:
        for i in result[1:]+[last_color]:
            print(i, end=' ')
    else:
        print(0)