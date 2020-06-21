def get_char_number(sumbol):
    alphabet = [ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' ]
    for i in range(len(alphabet)):
        if (sumbol == alphabet[i]):
            return i

def get_number_char(number):
    alphabet = [ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' ]
    return alphabet[number]

def encrypt(text,key):
    encrypt_text = []
    i = 0
    for sumbol in text:
        
        encrypt_text.append(get_number_char(( get_char_number(sumbol) + get_char_number(key[i])) % 26))
        i+=1
    return encrypt_text

def decrypt(encrypt_text,key):
    decrypt_text = []
    i = 0
    for sumbol in encrypt_text:
        
        if (get_char_number(sumbol) - get_char_number(key[i])) < 0:
            decrypt_text.append(get_number_char( 26 + ( get_char_number(sumbol) - get_char_number(key[i]))))
        else:
            decrypt_text.append(get_number_char(( get_char_number(sumbol) - get_char_number(key[i] ))))
        i+=1
    return decrypt_text

def formate_key(key,text):
    formated_key = []
    while (len(formated_key) != len(text)):
        for sumbol in key:
            if (len(formated_key) == len(text)):
                break;
            formated_key.append(sumbol)
    return formated_key

key_list = []
text_list = []
text = input("Enter message: ")

for s in text:
    text_list.append(s)

print(text_list)

key = input("Enter key: ")

for s in key:
    key_list.append(s)

print(key_list)

key_list = formate_key(key_list,text_list)
print("Formated key: ", key_list)

encrypt_text_list = encrypt(text_list,key_list)
print("Encrypted text: " , encrypt_text_list )

decrypt_text_list = decrypt(encrypt_text_list,key_list)
print("Decrypted text: " , decrypt_text_list )
