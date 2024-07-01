class LampadaTresEstados:
    def __init__(self, estado=0):
        self.estado = estado

    def mostrar_estado_atual(self):
        return f"Estado atual: {self.estado}% de intensidade"

    def mudar_estado(self, estado):
        if estado < 0 or estado > 100:
            return "Estado inválido. Intensidade deve estar entre 0% e 100%."
        else:
            self.estado = estado
            return f"Mudando estado para intensidade de luz {self.estado}%"