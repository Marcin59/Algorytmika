from sys import setrecursionlimit

def remember(l, r, k):
    sectors[k] = '{} {}'.format(l+1, r+1)
    if k >= 3:
        if lolipop[l] == 'T':
            remember(l+1, r, k-2)
        elif lolipop[r] == 'T':
            remember(l, r-1, k-2)
        else:
            remember(l+1, r-1, k-2)

if __name__ == "__main__":
    setrecursionlimit(100000)
    segments, orders = [int(x) for x in input().split()]
    lolipop = input()
    lolipop_price = 0
    l = r = -1

    for i in range(segments):
        if lolipop[i] == "W":
            if l == -1:
                l = i
            r = i
            lolipop_price += 1
        else:
            lolipop_price += 2

    sectors = [None for _ in range(segments*2+1)]
    remember(0, segments-1, lolipop_price)

    if l != -1 and r-1 < segments - l:
        remember(l+1, segments-1, lolipop_price - 2*l-1)
    elif r != -1:
        remember(0, r-1, lolipop_price - 2*(segments - r - 1)-1)

    for _ in range(orders):
        order = int(input())
        if order > lolipop_price or sectors[order] is None:
            print("NIE")
        else:
            print(sectors[order])