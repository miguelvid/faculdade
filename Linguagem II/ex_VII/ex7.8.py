# Crie uma classe chamada Ingresso que possui um valor em reais e um método imprimeValor().

# -crie uma classe VIP, que herda Ingresso e possui um valor adicional. Crie um método que retorne o valor do ingresso VIP (com o adicional incluído).
# -crie uma classe Normal, que herda Ingresso e possui um método que imprime: "Ingresso Normal".
# -crie uma classe CamaroteInferior (que possui a localização do ingresso e métodos para acessar e imprimir esta localização) e uma classe CamaroteSuperior, que é mais cara (possui valor adicional).

#Esta última classe possui um método para retornar o valor do ingresso. Ambas as classes herdam a classe VIP.

class Ingresso:
    def __init__(self, valor) -> None:
        self.valor = valor
    
    def mostraValor(self):
        print(f"Ingresso valor: R${self.valor:.2f}")

class VIP(Ingresso):
    def __init__(self, valor, adicional) -> None:
        super().__init__(valor)
        self.adicional = adicional
    
    def mostraTipo(self):
        print("Ingresso Vip")
    
    def valorVIP(self):
        return self.valor + self.adicional
    
    def mostraValorVip(self):
        print(f"Valor VIP fica: R${self.valorVIP():.2f}")

class Normal(Ingresso):
    def mostraTipo(self):
        print("Ingresso Normal")
    
class Inferior(Ingresso):
    def __init__(self, valor, localizacao) -> None:
        super().__init__(valor)
        self.localizacao = localizacao

    def mostraTipo(self):
        print("Ingreso Camarote Inferior")
    
    def mostraLocalizacao(self):
        print(f"Localização do Camarote Inferior: {self.localizacao}")

class Superior(VIP):
    def __init__(self, valor, adicional, localizacao) -> None:
        super().__init__(valor, adicional)
        self.localizacao = localizacao
    
    def mostraTipo(self):
        print("Ingreso Camarote Superior")
    
    def valorSuperior(self):
        return self.valor + self.adicional
    
    def mostraLocalizacao(self):
        print(f"Localização do Camarote Superior: {self.localizacao}")
    
    def mostraValorSuperior(self):
        print(f"Valor Superior fica: R${self.valorSuperior():.2f}")

if __name__ == "__main__":
    ingresso_normal = Normal(50)
    ingresso_vip = VIP(50, 30)
    camarote_inferior = Inferior(30, "Setor A")
    camarote_superior = Superior(50, 70, "Setor VIP")

    ingresso_normal.mostraTipo()
    ingresso_normal.mostraValor()
    ingresso_vip.mostraTipo()
    ingresso_vip.mostraValorVip()
    camarote_inferior.mostraTipo()
    camarote_inferior.mostraValor()
    camarote_inferior.mostraLocalizacao()
    camarote_superior.mostraTipo()
    camarote_superior.mostraValorSuperior()
    camarote_superior.mostraLocalizacao()