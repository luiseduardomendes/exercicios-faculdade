import sympy as sp

def lagrange_interpolate (x_, y_, x : sp.Symbol):
    n = len(x_)
    L = [1 for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if (i != j):
                L[i] *= (x - x_[j]) / (x_[i] - x_[j])
            
    P = 0
    for i in range(n):
        P += y_[i] * L[i]
    
    return sp.simplify(P)
