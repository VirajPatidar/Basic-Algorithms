import math
import sys

def encrypt(text, key):
    text_len = len(text)
    text = list(text)
    key_list = sorted(list(key))
    col = len(key)
    row = int(math.ceil(text_len / col))
    fill_null = int((row * col) - text_len)
    text.extend('_' * fill_null)
    
    matrix = [text[i: i + col] for i in range(0, len(text), col)]
    
    cipher = ""

    key_index = 0
    for _ in range(col):
        curr = key.index(key_list[key_index])
        cipher += ''.join([row[curr] for row in matrix])
        key_index += 1
    
    return cipher


def decrypt(cipher, key):
    cipher_len = len(cipher)

    cipher = list(cipher)
    col = len(key)
    row = int(math.ceil(cipher_len / col))
    key_lst = sorted(list(key))
    text = []
    
    for _ in range(row):
        text += [[None] * col]
    
    key_index = 0
    msg_index = 0

    for _ in range(col):
        curr = key.index(key_lst[key_index])
        for j in range(row):
            text[j][curr] = cipher[msg_index]
            msg_index += 1
        key_index += 1
        
    text = ''.join(sum(text, []))

    null_count = text.count('_')
    if null_count > 0:
        return text[:-null_count]
    
    return text



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