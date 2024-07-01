# Implementente uma classe Carro que deve conter um metodo liga que imprime "Carro ligado" e um atributo velocidade. Implemente tambem o construtor da classe.

class Carro :
    def __init__(self, velocidade = 0) :
        self.velocidade = velocidade
    
    def girarChave(self):
        print("Motor Ligado")

meu_carro = Carro()
meu_carro.girarChave()

try:
    velocidade_desejada = int(input("Digite a velocidade do carro: "))

except ValueError:    
    print("insira um valor valido para a velocidade.")
    exit()

meu_carro = Carro(velocidade_desejada)

print(f"Velocidade do carro: {meu_carro.velocidade}Km/h")

