''''
# Exemplo de heranca

                Animal
                  |
          +-------+--------+
          |       |        | 
        Gato   Cachorro  Coelho       

'''
class Animal():
    def __init__(self, nome, cor):
        self.__nome = nome
        self.__cor = cor

    def comer(self):
        print(f"O {self.__nome} está comendo")


class Gato(Animal):
    def __init__(self, nome, cor):
        super().__init__(nome, cor)


class Cachorro(Animal):
    def __init__(self, nome, cor):
        super().__init__(nome, cor)


class Coelho(Animal):
    def __init__(self, nome, cor):
        super().__init__(nome, cor)



if __name__ == "__main__":
    gato = Gato("Bichano", "Branco")
    cachorro = Cachorro("Totó", "Preto")
    coelho = Coelho("Pernalonga", "Cinza")

    gato.comer()
    cachorro.comer()
    coelho.comer()