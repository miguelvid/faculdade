class Lampada:
    def __init__(self, marca, tipoDeLampada, temperaturaDaLampada, preco, voltagem, ligada):
        self.marca = marca
        self.tipoDeLampada = tipoDeLampada
        self.temperaturaDaLampada = temperaturaDaLampada
        self.preco = preco
        self.voltagem = voltagem
        self.ligada = ligada

    def mudarEstado(self):
        if self.ligada:
            self.ligada = False
            return "Desligando lampada..."
        else:
            self.ligada = True
            return "Ligando lampada..."

    def esta_ligada(self):
        if self.ligada:
            return True
        else:
            return False