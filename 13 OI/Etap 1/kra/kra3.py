if __name__ == "__main__":

    bottom, number_of_disc = [int(x) for x in input().split()]

    tube = input().split()
    tube[0] = int(tube[0])

    the_min = min
    for i in range(1, bottom):
        tube[i] = the_min(int(tube[i]), tube[i - 1])

    rings = input().split()
    for ring in rings:
        ring = int(ring)
        a = bottom - 1
        while a > 0 and tube[a] < ring:
            a = a-1
        bottom = a
        if bottom == 0:
            print(0)
            break
    if bottom > 0:
        print(bottom+1)