import numpy as np

def do_everything():
    bottom, number_of_disc = [int(x) for x in input().split()]

    tube = np.array(input().split(), dtype=np.int32)
    tube[0] = int(tube[0])

    for i in range(1, bottom):
        tube[i] = tube[i-1:i+1].min()

    rings = np.array(input().split(), dtype=np.int32)
    for ring in rings:
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