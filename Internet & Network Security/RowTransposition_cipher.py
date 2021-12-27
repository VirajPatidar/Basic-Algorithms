import sys

def make_mat(text, key):
    text = text.replace(' ', '')
    matrix = []
    row = []
    count = 0

    for char in text:
        row.append(char)
        count += 1

        if count % len(key) == 0:
            matrix.append(row)
            row = []

    if len(text) % len(key) != 0:
        while len(row) != len(key):
            row.append('X')
        matrix.append(row)

    return matrix



def encrypt(text, key):
    matrix = make_mat(text, key)
    sorted_keyword = ''.join(sorted(key))
    cipher = []
    ind = []

    for char in sorted_keyword:
        ind.append(key.find(char))

    for row in matrix:
        for i in ind:
            cipher.append(row[i])

    return ''.join(cipher)



def decrypt(cipher, key):
    matrix = []
    row = []
    count = 0

    for char in cipher:
        row.append(char)
        count += 1
        if count % len(key) == 0:
            matrix.append(row)
            row = []

    indices = []
    sorted_keyword = ''.join(sorted(key))
    for char in key:
        indices.append(sorted_keyword.find(char))

    text = []

    for row in matrix:
        for i in indices:
            if row[i] != 'X':
                text.append(row[i])
    return ''.join(text)


if __name__ == '__main__':

    x=1
    while x==1 or x==2:
        x = int(input('\nPress 1 to encrypt and 2 to decrypt: '))
        if x!=1 and x!=2:
            print('Exiting..')
            sys.exit()
        text = input('Enter text: ')
        key = input('Enter key: ')

        if x == 1:
            print(f"Encoded text: {encrypt(text, key)}")
        else:
            print(f"Decoded text: {decrypt(text, key)}")