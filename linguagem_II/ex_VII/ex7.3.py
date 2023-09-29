# Agora implemente uma classe CarroAnfibio é subclasse de Carro e Barco implementados anteriormente.

# Essa classe deve ter um metodo liga que invoca o construtor super(). Instancie um objeto dessa classe e invoque o metodo liga. Observe qual a saída do código.

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

meu_carro_anfibio = CarroAnfibio()
meu_carro_anfibio.girarChave()