import math
x_y_n = {}
eps = 0;

def toFixed(f: float, n=0):
    a, b = str(f).split('.')
    return '{}.{}{}'.format(a, b[:n], '0'*(n-len(b)))

def func(x):
    res = 0.0
    reference = math.log(1-x)
    n = 1
    while int(res * eps) != int(reference * eps):
        res -= (x ** n) / n
        n += 1
    x_y_n.update({x:[res,n]})

epsilon = int(input("Input epsilon: "))
dx = float(input("Input dx: "))
eps = 10 ** epsilon
i = -1.0
while (i >= -1.0 and i < 1.0):
    func(i)
    i += dx
print(" X\t\t|\tln(1 - x)\t|\tn")
print("----------------------------------------------------------")
for i in x_y_n.keys():
    print(toFixed(i,epsilon),"\t|\t",toFixed(x_y_n[i][0],epsilon),"\t|\t",x_y_n[i][1])