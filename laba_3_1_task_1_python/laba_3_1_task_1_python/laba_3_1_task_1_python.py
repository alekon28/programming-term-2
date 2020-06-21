import math
chart = dict()
dx = 0.0

def func(x):
    if (x>=-8 and x<-5):
        chart.update({x:-3})
    elif (x>-5 and x<-3):
        chart.update({x:(3.0 / 5.0) * x + 4.5})
    elif (x>=-3 and x<3):
        chart.update({x:((3.0 ** 2.0)  - x ** 2) ** 0.5})
    elif (x>3 and x<8):
        chart.update({x:(3.0 / 5.0) * x - 1.8})
    elif (x>=8 and x<=10):
        chart.update({x:3})

dx = float(input("Input dx: "))
i = -8.0
while i <= 10.0:
    func(i)
    i += dx
print(" X\t|\tY")
print("-----------------------")
for i in chart:
    print(" ",i,"\t|\t",format(chart[i],'.3f'))
