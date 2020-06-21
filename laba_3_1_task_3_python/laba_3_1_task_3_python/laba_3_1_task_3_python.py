print('a ^ x mod p\n')
a = int(input('Input a: '))
x = int(input('Input x: '))
p = int(input('Input p: '))
#print('\nAnswer: ',a ** (x % (p - 1)) % p)
exp = (x % (p - 1))
a %= p
res = a % p
for i in range(exp - 1):
    res = (res * a) % p
print('\nAnswer: ',res)