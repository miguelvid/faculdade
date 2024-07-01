# Implemente o seguinte diagrama de classes

# Animal
    # -nome:Sting
    # -raca:String
    #--------------
    # +Animal()
    # +Animal(nome:String)
    # +caminha():String

# Cachorro(sub-class de animal)
    # +late():String

# Gato(sub-class de animal)
    # +mia():String

class Animal:
    def __init__(self, nome, raca) -> None:
        self.nome = nome
        self.raca = raca
    
    def caminha(self):
        return f"{self.nome} esta caminhando"  # vi que usar return é melhor pq da pra capturar o valor retornado e o usar posteriormente.
    
class Cachorro(Animal):
    def late(self):
        return f"{self.nome} esta latindo pq é um {self.raca}"

class Gato(Animal):
    def mia(self):
        return f"{self.nome} esta miando pq é um {self.raca}"
    
if __name__ == "__main__":
    # animal = Animal("bixo", "Indefinido")
    cachorro = Cachorro("Zeus", "Pintcher")
    gato = Gato("Alice", "Angora")

    # print(animal.caminha())
    print(cachorro.caminha())
    print(cachorro.late())
    print(gato.caminha())
    print(gato.mia())

    

