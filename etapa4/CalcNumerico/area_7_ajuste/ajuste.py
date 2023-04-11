import sympy as sp

def regression(f0, x, x0, y0, fator_termos=None):
    nf = len(f0)
    n = len(x0)
    v = sp.Matrix(
        [
            [
                float(f0[j].subs(x, x0[i]))
                for j in range(nf)
            ]
            for i in range(n)
        ]
    )

    A = (v.T * v).inv() * (v.T * sp.Matrix(y0))

    f = 0
    for i in range(len(A)):
        if fator_termos == None:
            f += f0[i] * A[i]
        else:
            f += f0[i] * fator_termos[i](A[i])

    return f