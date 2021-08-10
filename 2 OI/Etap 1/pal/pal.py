def checkPalindrome(data):
    return data == data[::-1]

if __name__ == "__main__":
    data = 'aaa'
    pals = []
    parity = None
    if not len(data) % 2:
        parity = True
    else:
        parity = False
    print(parity)
    print(checkPalindrome(data))



