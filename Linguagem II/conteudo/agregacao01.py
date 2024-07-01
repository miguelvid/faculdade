# Exemplo super simples de agregacao de classes

# Nao estah sendo feito nenhum tipo de verificacao, dessa forma,  a = A("string") # eh valido

#***** Compare com o arquivo composicao01.py

class B():
    pass

class A():
    def __init__(self, b):
        self.b = b



if __name__ == "__main__":
    b = B()
    a = A(b)  # passa uma referencia do objeto "b" para o construtor de "a"
    print(a.b)