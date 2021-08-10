from collections import defaultdict
def count_nice_passages():
    chain_lenght, nice_colors_lenght = [int(x) for x in input().split()]
    amount_nice_colors = list(map(int, input().split()))
    nice_colors = list(map(int, input().split()))
    chain = list(map(int, input().split()))
    nice_chain_count_colors = sum(amount_nice_colors)
    if len(chain) < nice_chain_count_colors:
        return 0
    nice_chain = dict(zip(nice_colors, amount_nice_colors))
    actualy_chain = defaultdict(int)

    for color in chain[:nice_chain_count_colors]:
        try:
            actualy_chain[color] += 1
        except:
            actualy_chain[color] = 1

    bad_colors = 0
    result = 0

    for key in nice_chain.keys():
        try:
            if nice_chain[key] > actualy_chain[key]:
                bad_colors += nice_chain[key] - actualy_chain[key]
        except:
            bad_colors += nice_chain[key]

    if bad_colors == 0:
        result += 1

    for i in range(chain_lenght - nice_chain_count_colors):
        old, new = chain[i], chain[i + nice_chain_count_colors]
        if old != new:
            actualy_chain[old] -= 1
            actualy_chain[new] += 1

            try:
                if actualy_chain[old] < nice_chain[old]:
                    bad_colors += 1
            except:
                pass

            try:
                if actualy_chain[new] <= nice_chain[new]:
                    bad_colors -= 1
            except:
                pass

        if bad_colors == 0:
            result += 1

    return result

if __name__ == '__main__':
    print(count_nice_passages())



'''

7 3
2 1 1
1 2 3
4 2 1 3 1 2 5

10 4
1
1
1 1 1 2 2 2 1 1 1 1

'''