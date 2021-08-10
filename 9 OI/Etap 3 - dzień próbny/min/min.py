if __name__ == "__main__":
    actions = int(input())-1
    minus = sign = last_sign = input()
    result = '-'
    for _ in range(actions-1):
        sign = input()
        if sign == last_sign:
            result += '-'
        elif sign !=  minus:
            result += '(-'
            last_sign = sign
        else:
            result += ")-"
            last_sign = sign

    if sign != minus:
        result += ')'
    print(result)

'''
7
-
-
+
+
-
+
'''