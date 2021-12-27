import sys

def gcd(x: int, y: int):
    small, large = (x,y) if x<y else (y,x)

    while small != 0:
        temp = large % small
        large = small
        small = temp

    return large


def find_e(z: int):
    e = 2
    while e < z:
        if gcd(e, z)==1:
            return e
        e += 1


def find_d(e: int, z: int):
    d = 2
    while d < z:
        if ((d*e) % z)==1:
            return d
        d += 1

def generate_keypair(p: int, q: int):
    n = p * q
    z = (p-1)*(q-1)

    e = find_e(z)
    d = find_d(e, z)

    return ((e, n), (d, n))

def digital_signature_generation(msg, pvt_key):
    d, n = pvt_key
    cypher_text = ''
    for ch in msg:
        ch = ord(ch)
        cypher_text += chr((ch ** d) % n)

    return cypher_text

def digital_signature_verification(cypher_text, pub_key):
    e, n = pub_key
    plain_text = ''
    for ch in cypher_text:
        ch = ord(ch)
        plain_text += chr((ch ** e) % n)

    return plain_text



if __name__ == "__main__":

    p, q = map(int, input("Enter values of p and q: ").split())

    x=1
    while x==1 or x==2:
        x = int(input('\nPress 1 to generate digital signature and 2 to verify digital signature: '))
        if x!=1 and x!=2:
            print('Exiting..')
            sys.exit()

        public, private = generate_keypair(p, q)

        if x == 1:
            msg = input("Enter message text: ")
            print(f"Digital signature generated: {digital_signature_generation(msg, private)}")
        else:
            cipher = input("Enter cipher text: ")
            print(f"Digital signature verified: {digital_signature_verification(cipher, public)}")