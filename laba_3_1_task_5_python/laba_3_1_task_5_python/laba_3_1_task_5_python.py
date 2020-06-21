p = 997
enc_key_A = 347
enc_key_B = 451

def pwr_mod(a,x,p):
    exp = (x % (p - 1))
    res = a % p
    for i in range(exp - 1):
        res = (res * a) % p
    return res

def rev(a,m):
    if a == 1: return 1
    return(1 - rev(m % a,a) * m)/a + m

def fragmentation(text):
    frag_txt = []
    for i in text:
        frag_txt.append(i)
    return frag_txt

def defragmentation(frag_txt):
    text = ''
    for i in frag_txt:
        text += i
    return text

def txt_to_ord(chr_text):
    ord_text = []
    for i in chr_text:
        ord_text.append(ord(i))
    return ord_text

def ord_to_txt(ord_text):
    chr_text = []
    for i in ord_text:
        chr_text.append(chr(i))
    return chr_text

def encrypt(txt,key):
    enc_txt = []
    for i in txt:
        enc_txt.append(pwr_mod(i,key,p))
    return enc_txt

def decrypt(enc_txt,key):
    txt = []
    for i in enc_txt:
        txt.append(pwr_mod(i,key,p))
    return txt

dec_key_A = int(rev(enc_key_A,p - 1))
dec_key_B = int(rev(enc_key_B,p - 1))
print("dec_key_A: ",dec_key_A)
print("dec_key_B: ",dec_key_B)

M = input("Input message: ")
frag_m = fragmentation(M)
print("frag_m: ",frag_m)
ord_frag_m = txt_to_ord(frag_m)
print("ord_frag_m: ",ord_frag_m)
A_enc_m = encrypt(ord_frag_m,enc_key_A)
print("A_enc_m: ",A_enc_m)
print("A_chr_enc_m: ",defragmentation(ord_to_txt(A_enc_m)))
B_A_enc_m = encrypt(A_enc_m,enc_key_B)
print("AB_enc_m: ",B_A_enc_m)
print("AB_chr_enc_m: ",defragmentation(ord_to_txt(B_A_enc_m)))
B_enc_m = decrypt(B_A_enc_m,dec_key_A)
print("B_enc_m: ",B_enc_m)
print("B_chr_enc_m: ",defragmentation(ord_to_txt(B_enc_m)))
dec_m = decrypt(B_enc_m,dec_key_B)
print("dec_m: ",dec_m)
print("chr_dec_m: ",defragmentation(ord_to_txt(dec_m)))