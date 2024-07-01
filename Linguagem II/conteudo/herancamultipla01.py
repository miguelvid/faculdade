class A(object):
    def f(self):
        print("Metodo f() classe A")

class B(object):

    def f(self):
        print ("Metodo f() classe B")

class C(A, B):
    pass

if __name__ == "__main__":
    objC = C()
    objC.f()  #invoca metodo f() da classe A (motivo: MRO)
