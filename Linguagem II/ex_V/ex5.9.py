class Produto:
    def __init__(self, preco, tamanho):
        self.preco = preco
        self.tamanho = tamanho

    def vendido(self):
        print("Produto vendido.")

class Vendedor:
    def __init__(self, comissao):
        self.comissao = comissao

    def vende(self, comprador, produto):
        if comprador.verba >= produto.preco:
            print("Venda realizada!")
            comprador.verba -= produto.preco
            self.comissao += produto.preco
            produto.vendido()
        else:
            print("O comprador não possui verba suficiente para comprar este produto.")

class Comprador:
    def __init__(self, verba):
        self.verba = verba

    def compra(self, vendedor, produto):
        if vendedor.comissao > 0:
            print("Compra realizada!")
            vendedor.comissao -= produto.preco
            self.verba -= produto.preco
        else:
            print("O vendedor não possui comissão para receber.")

class Venda:
    def __init__(self, comprador, vendedor, produto):
        self.comprador = comprador
        self.vendedor = vendedor
        self.produto = produto

    def concretizaVenda(self):
        self.vendedor.vende(self.comprador, self.produto)

    def cancelaVenda(self):
        print("Venda cancelada!")

if __name__ == "__main__":
    produto1 = Produto(100.0, "Médio")
    comprador1 = Comprador(1000.0)
    vendedor1 = Vendedor(0.0)

    venda1 = Venda(comprador1, vendedor1, produto1)
    venda1.concretizaVenda()
    print(f"Verba do Comprador: R${comprador1.verba:.2f}")
    print(f"Comissão do Vendedor: R${vendedor1.comissao:.2f}")

    venda1.cancelaVenda()
    print(f"Comissão do Vendedor: R${vendedor1.comissao:.2f}")