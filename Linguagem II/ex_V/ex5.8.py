class Pneu:
    def __init__(self, marca, tamanho):
        self.marca = marca
        self.tamanho = tamanho

    def __str__(self):
        return f"Pneu: Marca - {self.marca}, Tamanho - {self.tamanho}"


class Motor:
    def __init__(self, tipo, potencia):
        self.tipo = tipo
        self.potencia = potencia

    def __str__(self):
        return f"Motor: Tipo - {self.tipo}, Potência - {self.potencia} CV"


class Carro:
    def __init__(self, marca, modelo, ano, pneus, motor):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
        self.pneus = pneus
        self.motor = motor

    def __str__(self):
        return f"Carro: Marca - {self.marca}, Modelo - {self.modelo}, Ano - {self.ano}\n{self.pneus}\n{self.motor}"


if __name__ == "__main__":
    pneu1 = Pneu("Michelin", "225/55 R17")
    pneu2 = Pneu("Michelin", "225/55 R17")
    pneu3 = Pneu("Michelin", "225/55 R17")
    pneu4 = Pneu("Michelin", "225/55 R17")

    motor = Motor("V8", 400)

    carro = Carro("Toyota", "Camry", 2023, [pneu1, pneu2, pneu3, pneu4], motor)

    print("Detalhes do Carro:")
    print(carro)