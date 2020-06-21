class Subscriber(object):
    def __init__(self, enc_key, p, message):
        self.message = message
        self.current_message = message
        self.formated_message = []
        self.current_formated_message = []
        self.enc_key = enc_key
        self.dec_key = int(self.__write_decrypt_key(enc_key,p - 1))
        self.p = p
        
    def __write_decrypt_key(self,a,m):
        if a == 1: return 1
        return(1 - self.__write_decrypt_key(m % a,a) * m)/a + m

class Message(Subscriber):
    def get_message(self,mes):
        self.current_message = mes

    def send_message(self):
        return self.current_message

    def format_to_ord(self):
        for i in self.current_message:
            self.formated_message.append(ord(i))

    def format_to_str(self):
        for i in self.current_formated_message:
            self.current_message += chr(i)

    def clear_current_message(self):
        self.current_message = ''

class Crypto(Message):
    def pwr_mod(self,a,x,p):
        exp = (x % (p - 1))
        res = a % p
        for i in range(exp - 1):
            res = (res * a) % p
        return res

    def encrypt(self):
        self.format_to_ord()
        for i in self.formated_message:
            self.current_formated_message.append(self.pwr_mod(i,self.enc_key,self.p))
            print(i)
            print(self.pwr_mod(i,self.enc_key,self.p))
        self.clear_current_message()
        self.format_to_str()
        self.formated_message.clear()
        self.current_formated_message.clear()

    def decrypt(self):
        self.format_to_ord()
        for i in self.formated_message:
            self.current_formated_message.append(self.pwr_mod(i,self.dec_key,self.p))
        self.clear_current_message()
        self.format_to_str()
        self.formated_message.clear()
        self.current_formated_message.clear()

print("--- Shamir's algorithm ---")
message = input("Input Secret message: ")
p = input("Input prime number (or default): ")
#P=int(p)
if p == 'default':
    P = 9973
KeyA = input("Input key for A gcd(key,p - 1) = 1 (or default): ")
KeyB = input("Input key for B gcd(key,p - 1) = 1 (or default): ")
#KEY_A = int(KeyA)
#KEY_B = int(KeyB)

if KeyA == 'default':
    KEY_A = 7721
if KeyB == 'default':
    KEY_B = 6571
A = Crypto(KEY_A,P,message)
B = Crypto(KEY_B,P,message)
print("-> p = ",P)
print("-> Subscriber A encrypt/decrypt key: ",A.enc_key,"/",A.dec_key)
print("-> Subscriber B encrypt/decrypt key: ",B.enc_key,"/",B.dec_key)
print("-> Message: ",message)
print("\n--- First step ---")
A.encrypt()
print("-> A encrypted this message: ",A.send_message())
print("Sending message to B...")
B.get_message(A.send_message())
B.encrypt()
print("\n--- Second step ---")
print("-> B encrypted received message: ",B.send_message())
print("Sending message to A...")
A.get_message(B.send_message())
A.decrypt()
print("\n--- Third step ---")
print("-> A decrypted received message: ",A.send_message())
print("Sending message to B...")
B.get_message(A.send_message())
B.decrypt()
print("\n--- Fourth step ---")
print("-> B decrypted received message: ",B.send_message())
