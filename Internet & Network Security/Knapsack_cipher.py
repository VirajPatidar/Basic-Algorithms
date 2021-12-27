import sys
import random
from itertools import combinations

def modInverse(a, m):
    for x in range(1, m):
        if (((a%m) * (x%m)) % m == 1):
            return x
    return -1

def generate_keypair(n: int, m: int):
    
    private = [1]
    public = []

    for i in range(0, 5):
       r = random.randint(1, 3)
       private.append(sum(private) + r)

    # private = [1, 2, 4, 10, 20, 40]
    
    for i in private:
        public.append((i*n)%m)

    return (public, private)


def encrypt(msg, public):
    cypher_text = []
    msg = [int(x) for x in str(msg)]
    a = 0
    b = 6

    for i in range(0, len(msg), 6):
        sum=0
        for i in range(a, b):
            if(msg[i]==1):
                sum = sum + public[i%6]
        a = a+6
        b = b+6
        cypher_text.append(sum)

    return cypher_text


def getSplitSumList(num, private):
    for i in range(0, len(private)):
        combos = list(combinations(private, i))
        for j in combos:
            if (sum(j) == num):
                return(j)
    return([])

        

def decrypt(cypher_text, n, m, private):
    plain_text = ''
    nInv = modInverse(n, m)
    ct=[]

    for i in cypher_text:
        ct.append((i*nInv)%m)

    for i in ct:
        sumList = getSplitSumList(i, private)
        for j in range(0, 6):
            if(private[j] in sumList):
                plain_text += "1"
            else:
                plain_text += "0"

    return plain_text



if __name__ == "__main__":

    x=1
    n, m = map(int, input("Enter values of n and m: ").split())
    public, private = generate_keypair(n, m)

    while x==1 or x==2:
        x = int(input('\nPress 1 to encrypt and 2 to decrypt: '))
        if x!=1 and x!=2:
            print('Exiting..')
            sys.exit()

        if x == 1:
            msg = int(input("Enter message text: "))
            print(f"Encrypted Text: {encrypt(msg, public)}")
        else:
            cipher = [int(x) for x in input("Enter cipher text: ").split()]
            print(f"Plain Text: {decrypt(cipher, n, m, private)}")

# n=31
# m=110
# private = [1, 2, 4, 10, 20, 40]
# public = [31, 62, 14, 90, 70, 30]
# plain = 100100111100101110
# cipher = [121, 197, 205]
# ct = [11, 17, 35]
# 11 = (1, 10) = 100100     
# 17 = (1, 2, 4, 10) = 111100
# 35 = (1, 4, 10, 20) = 101110 

# 53 120
# 111010101101111001