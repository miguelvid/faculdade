# Exemplo super simples de composicao de classes

#***** Compare com o arquivo agregacao01.py

class B():
    pass

class A():
    def __init__(self):
        self.b = B()  # instancia o objeto



if __name__ == "__main__":
   a = A()