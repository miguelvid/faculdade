# Faça a mesma coisa que o exercicio anterior (crei uma classe CarroAnfibio2). Porém inverta a ordem da herança, herde primeiro Barco e depois Carro. Instancie um objeto dessa classe e invoque o metodo liga. Observe qual a saída do código.

class Carro:
    def __init__(self, velocidade=0):
        self.velocidade = velocidade

    def girarChave(self):
        print("Motor ligado, carro")

class Barco:
    def __init__(self, velocidade=0):
        self.velocidade = velocidade

    def girarChave(self):
        print("Motor ligado,barco")

class CarroAnfibio(Carro, Barco):
    def girarChave(self):
        super().girarChave()    # Python chama o método da primeira classe base declarada
        print("Modo Anfíbio ativado")   


class CarroAnfibio2(Barco, Carro):
    def girarChave(self):
        super().girarChave()    # Python chama o método da primeira classe base declarada(eu falei hihi)
        print("Modo Anfíbio ativado")


meu_carro_anfibio = CarroAnfibio()
meu_carro_anfibio.girarChave()
meu_carro_anfibio = CarroAnfibio2()
meu_carro_anfibio.girarChave()