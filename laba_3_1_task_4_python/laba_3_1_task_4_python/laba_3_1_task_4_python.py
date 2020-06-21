def rev(a,m):
    if a == 1: return 1
    return(1 - rev(m % a,a) * m)/a + m
print(">>> c * d = 1 (mod m) <<<")
c = int(input("Input c: "))
m = int(input("Input m: "))
print("->",c,"* d = 1 ( mod",m,")")
d = int(rev(c,m))
print("-> d =",d)
