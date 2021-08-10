def do_everything():
    bottom, number_of_disc = [int(x) for x in input().split()]

    tube = input().split()
    tube[0] = int(tube[0])

    the_min = min
    for i in range(1, bottom):
        tube[i] = the_min(int(tube[i]), tube[i-1])

    rings = input().split()
    for ring in rings:
        ring = int(ring)
        a = 0
        b = bottom - 1

        while a < b:
            c = int((a + b) / 2 + 1)
            if tube[c] < ring:
                b = c - 1
            else:
                a = c
        bottom = a
        if bottom == 0:
            return 0
    return bottom+1

if __name__ == "__main__":
    print(do_everything())

'''
7 3
5 6 4 3 6 2 3
3 2 5
'''