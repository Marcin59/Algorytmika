def move(n, whence, where, pom):
    if n == 1:
        print('{} => {}'.format(whence, where))
    else:
        move(n-1, whence, pom, where)
        move(1, whence, where, pom)
        move(n-1,pom, where, whence)

def HanoiRek(n):
    move(n, 'A', 'B', "C")

if __name__ == "__main__":
    n = 4
    HanoiRek(n)
