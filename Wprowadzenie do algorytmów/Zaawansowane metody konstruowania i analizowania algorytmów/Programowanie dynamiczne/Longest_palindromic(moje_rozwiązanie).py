def longest_palindromic(word, i, j):
    if word[i:j] == word[i:j][::-1]:
        return word[i:j]
    else:
        return max(longest_palindromic(word, i+1, j), longest_palindromic(word, i, j-1), key=len)

if __name__ == '__main__':
    word = 'wassawadadslhhhhhhhhh'
    a = longest_palindromic(word, 0, len(word))
    print(a)