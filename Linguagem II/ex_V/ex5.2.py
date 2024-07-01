class Produto:
    def __init__(self, nome, preco, quantidade_em_estoque):
        self.nome = nome
        self.preco = preco
        self.quantidade_em_estoque = quantidade_em_estoque

    def __str__(self):
        return f"{self.nome} - R${self.preco:.2f}"

class ItemPedido:
    def __init__(self, produto, quantidade):
        self.produto = produto
        self.quantidade = quantidade

    def calcular_subtotal(self):
        return self.produto.preco * self.quantidade

class Pedido:
    def __init__(self, cliente):
        self.cliente = cliente
        self.itens = []

    def adicionar_item(self, item):
        self.itens.append(item)

    def calcular_total(self):
        total = 0
        for item in self.itens:
            total += item.calcular_subtotal()
        return total

    def exibir_recibo(self):
        print("Itens do Pedido:")
        for item in self.itens:
            print(f"{item.quantidade}x {item.produto.nome} - Subtotal: R${item.calcular_subtotal():.2f}")
        print(f"Total a pagar: R${self.calcular_total():.2f}")

class Pagamento:
    def __init__(self, valor, metodo):
        self.valor = valor
        self.metodo = metodo

    def processar_pagamento(self):
        print(f"Pagamento de R${self.valor:.2f} realizado com {self.metodo}")

if __name__ == "__main__":
    produto1 = Produto("Arroz", 5.0, 100)
    produto2 = Produto("Feijão", 3.5, 80)
    produto3 = Produto("Óleo de Cozinha", 7.0, 50)

    item1 = ItemPedido(produto1, 2)
    item2 = ItemPedido(produto2, 3)
    item3 = ItemPedido(produto3, 1)

    pedido1 = Pedido("Cliente 1")
    pedido1.adicionar_item(item1)
    pedido1.adicionar_item(item2)
    pedido1.adicionar_item(item3)

    pedido1.exibir_recibo()

    pagamento1 = Pagamento(pedido1.calcular_total(), "cartão de crédito")
    pagamento1.processar_pagamento()