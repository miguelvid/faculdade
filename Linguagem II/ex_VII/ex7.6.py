# Implemente o seguinte diagrama de classes

# Pessoa
    # -nome:Sting
    # -idade:int
    #--------------
    # +Pessoa()

# Rica(sub-class de animal)
    # +fazCompras()

# Pobre(sub-class de animal)
    # +trabalha()

# Miseravel(sub-class de animal)
    # +mendiga()

class  Pessoa:
    def __init__(self, nome, idade = 0) -> None:
        self.nome = nome
        self.idade = idade

class Rica(Pessoa):
    def fazCompras(self):
        print(f"{self.nome} de {self.idade} anos, esta no shoping comprando.")

class Pobre(Pessoa):
    def trabalha(self):
        print(f"{self.nome} de {self.idade} anos, esta trabalhando batendo laje.")

class Miseravel(Pessoa):
    def mendiga(self):
        print(f"{self.nome} de {self.idade} anos, esta mendigando por ai.")


if __name__ == "__main__":
    pessoa_rica = Rica("Cleusa", 67)
    pessoa_pobre = Pobre("Toinho", 37)
    pessoa_miseravel = Miseravel("Miguel", 19)


    pessoa_rica.fazCompras()
    pessoa_pobre.trabalha()
    pessoa_miseravel.mendiga()




