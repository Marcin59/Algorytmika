def NWD(*args):
    m, n = sorted(args)
    if m == 0:
        return n
    else:
        print(n%m)
        return NWD(m, n%m)


if __name__ == '__main__':
    m, n = 34, 55
    result = NWD(m, n)
    print(result)