def read_file(filename):
    freq = {}
    for piece in open(filename).read().lower().split():
        word = ''.join(c for c in piece if c.isalpha())
        if word:
            freq[word] = 1 + freq.get(word, 0)

    max_word = ''
    max_count = 0

    for w, c in freq.items():
        if c > max_count:
            max_count = c
            max_word = w

    print(max_word, max_count)

if __name__ == '__main__':
    read_file('test.txt')
