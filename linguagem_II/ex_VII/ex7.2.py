# Implemente uma classe Barco que deve conter um metodo liga que imprime "Barco ligado" e um atributo velocidade. Implemente tambem o construtor da classe.

class Barco :
    def __init__(self, velocidade = 0) :
        self.velocidade = velocidade
    
    def girarChave(self):
        print("Motor Ligado")

meu_barco = Barco()
meu_barco.girarChave()

try:
    velocidade_desejada = int(input("Digite a velocidade do barco: "))

except ValueError:    
    print("insira um valor valido para a velocidade.")
    exit()

meu_barco = Barco(velocidade_desejada)

print(f"Velocidade do barco: {meu_barco.velocidade}Km/h")