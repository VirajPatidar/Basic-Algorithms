import re
import copy
import sys 

reg_x = []
reg_y = []
reg_z = []

def loading_registers(key):
	i = 0
	while(i < 19): 
		reg_x.insert(i, int(key[i]))
		i = i + 1

	j = 0
	p = 19
	while(j < 22): 
		reg_y.insert(j, int(key[p]))
		p = p + 1
		j = j + 1

	k = 22 + 19
	r = 0
	while(r < 23): 
		reg_z.insert(r, int(key[k]))
		k = k + 1
		r = r + 1


def get_majority(x,y,z): 
	if(x + y + z > 1):
		return 1
	else:
		return 0


def get_keystream(length):

	keystream = []
	i = 0

	while i < length:
		majority = get_majority(reg_x[8], reg_y[10], reg_z[10])

		if reg_x[8] == majority: 
			new = reg_x[13] ^ reg_x[16] ^ reg_x[17] ^ reg_x[18]
			reg_x_two = copy.deepcopy(reg_x)
			j = 1
			while(j < len(reg_x)):
				reg_x[j] = reg_x_two[j-1]
				j = j + 1
			reg_x[0] = new

		if reg_y[10] == majority:
			bit1 = reg_y[20] ^ reg_y[21]
			reg_y_two = copy.deepcopy(reg_y)
			k = 1
			while(k < len(reg_y)):
				reg_y[k] = reg_y_two[k-1]
				k = k + 1
			reg_y[0] = bit1

		if reg_z[10] == majority:
			bit2 = reg_z[7] ^ reg_z[20] ^ reg_z[21] ^ reg_z[22]
			reg_z_two = copy.deepcopy(reg_z)
			m = 1
			while(m < len(reg_z)):
				reg_z[m] = reg_z_two[m-1]
				m = m + 1
			reg_z[0] = bit2

		keystream.insert(i, reg_x[18] ^ reg_y[21] ^ reg_z[22])
		i = i + 1

	return keystream


def to_binary(plain): 
	s = ""
	i = 0
	for i in plain:
		binary = str(' '.join(format(ord(x), 'b') for x in i))
		j = len(binary)
		while(j < 8):
			binary = "0" + binary
			s = s + binary
			j = j + 1
	binary_values = []
	k = 0
	while(k < len(s)):
		binary_values.insert(k, int(s[k]))
		k = k + 1
	return binary_values


def convert_binary_to_str(binary):
	s = ""
	length = len(binary) - 8
	i = 0
	while(i <= length):
		s = s + chr(int(binary[i:i+8], 2))
		i = i + 8
	return str(s)



def encrypt(plain):
	s = ""
	binary = to_binary(plain)
	keystream = get_keystream(len(binary))
	i = 0
	while(i < len(binary)):
		s = s + str(binary[i] ^ keystream[i])
		i = i + 1
	return s



def decrypt(cipher):  
	s = ""
	binary = []
	keystream = get_keystream(len(cipher))
	i = 0
	while(i < len(cipher)):
		binary.insert(i,int(cipher[i]))
		s = s + str(binary[i] ^ keystream[i])
		i = i + 1
	return convert_binary_to_str(str(s))


if __name__ == '__main__':
    key = ''.join(str(e) for e in (to_binary(str(input('Enter an 8 character string (64-bit) key: ')))))

    print('The key is: ', key)

    if(len(key) == 64 and re.match("^([01])+", key)):
        loading_registers(key)
    else:
        print("Invalid Key !")
        sys.exit(0)

    choice = int(input('\n1: Encrypt\n2: Decrypt\nAny other number to exit\n'))

    if(choice == 1):
        plaintext = str(input('Enter the plaintext: '))
        print(encrypt(plaintext), '\n')

    elif(choice == 2):
        ciphertext = str(input('Enter a ciphertext: '))
        print(decrypt(ciphertext), '\n')

    else:
        sys.exit(0)		
