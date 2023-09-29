#Crie a classe Imovel, que possui um endereço e um preço.

# -crie uma classe Novo, que herda Imovel e possui um adicional no preço. Crie métodos de acesso e impressão deste valor adicional.
# -crie uma classe Velho, que herda Imovel e possui um desconto no preço. Crie métodos de acesso e impressão para este desconto.

class Imovel:
    def __init__(self,endereco, preco) -> None:
        self.endereco =endereco
        self.preco = preco
    
    def mostraPreco(self):
        print(f"Preço do imovel: R${self.preco:.2f}")

class Novo(Imovel):
    def __init__(self, endereco, preco, adicional) -> None:
        super().__init__(endereco, preco)
        self.adicional = adicional
    
    def adAdicional(self):
        return self.adicional
    
    def calTotal(self):
        return self.preco + self.adicional
    
    def mostraAdicional(self):
        print(f"Adicional do imovel novo: R${self.adicional:.2f}")
    
    def mostraTotal(self):
        print(f"Valor final imovel novo: R${self.calTotal():.2f}")

class Velho(Imovel):
    def __init__(self, endereco, preco, desconto) -> None:
        super().__init__(endereco, preco)
        self.desconto = desconto
    
    def adDesconto(self):
        return self.desconto
    
    def calTotal(self):
        return self.preco - self.desconto
    
    def mostraDesconto(self):
       print(f"Desconto do imovel usado: R${self.desconto:.2f}")
    
    def mostraTotal(self):
        print(f"Valor final imovel usado: R${self.calTotal():.2f}")

    
    
if __name__ == "__main__":
    #imovel1 = Imovel("Rua tal- 000", 135000)
    imovel2 = Novo("Rua tal- 003", 135000, 15000)
    imovel3 = Velho("Rua tal- 002", 135000, 10000)

    #imovel1.mostraPreco()
    imovel2.mostraPreco()
    imovel2.mostraAdicional()
    imovel2.mostraTotal()
    imovel3.mostraPreco()
    imovel3.mostraDesconto()
    imovel3.mostraTotal()

   # print(f"Adiciona do imovel novo da {imovel2.endereco}: R${imovel2.adAdicional():.2f}")
   # print(f"Desconto do imovel antigo da {imovel3.endereco}: R${imovel3.adDesconto():.2f}")




    
