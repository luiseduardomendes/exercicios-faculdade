from area6_interpolação.interp import *
from area_7_ajuste.ajuste import *
import sympy as sp
import math

x = sp.Symbol('x')
f = lagrange_interpolate(
    [0,1,2,3,4], 
    [30, 49, 70, 97, 132],
    x
)
print('Questao 1', f.subs(x, 3.5))

f = lagrange_interpolate(
    [-1, -0.7, 0, 0.69, 1.12], 
    [-4.37, 0, 2, 4.94, 0],
    x
)
print('Questao 2', f.subs(x, 1))

f1 = lagrange_interpolate(
    [-30, 0, 30], 
    [-0.5, 0, 0.5],
    x
)
f2 = lagrange_interpolate(
    [-30, -15, 15], 
    [-0.5, -0.65, 0.26],
    x
)
f3 = lagrange_interpolate(
    [-15, 15, 45], 
    [-0.65, 0.26, 0.71],
    x
)
f4 = lagrange_interpolate(
    [0, 15, 30], 
    [0, 0.26, 0.5],
    x
)
print('Questao 3')
print(f1.subs(x, 20), math.sin(20*math.pi/180), f1.subs(x, 20) - math.sin(20*math.pi/180))
print(f2.subs(x, 20), math.sin(20*math.pi/180), f2.subs(x, 20) - math.sin(20*math.pi/180))
print(f3.subs(x, 20), math.sin(20*math.pi/180), f3.subs(x, 20) - math.sin(20*math.pi/180))
print(f4.subs(x, 20), math.sin(20*math.pi/180), f4.subs(x, 20) - math.sin(20*math.pi/180))


t = [20, 25, 30]
c = [0.99907, 0.99852, 0.99826]
f = lagrange_interpolate(t, c, x)
print('Questao 4')
print(f, f.subs(x, 27))