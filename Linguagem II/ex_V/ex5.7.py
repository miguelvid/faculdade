class Produto:
    def __init__(self, codigo, nome, preco):
        self.codigo = codigo
        self.nome = nome
        self.preco = preco

    def __str__(self):
        return f"Código: {self.codigo}, Nome: {self.nome}, Preço: R${self.preco:.2f}"


class ItemPedido:
    def __init__(self, produto, quantidade):
        self.produto = produto
        self.quantidade = quantidade

    def calcular_subtotal(self):
        return self.produto.preco * self.quantidade

    def __str__(self):
        return f"{self.quantidade}x {self.produto.nome} - Subtotal: R${self.calcular_subtotal():.2f}"


class Pedido:
    def __init__(self):
        self.itens = []

    def adicionar_item(self, item):
        self.itens.append(item)

    def calcular_total(self):
        total = sum(item.calcular_subtotal() for item in self.itens)
        return total

    def __str__(self):
        return f"Total do Pedido: R${self.calcular_total():.2f}\nItens do Pedido:\n" + "\n".join(map(str, self.itens))

if __name__ == "__main__":
    produto1 = Produto(1, "Camiseta", 20.0)
    produto2 = Produto(2, "Calça", 40.0)

    item1 = ItemPedido(produto1, 3)
    item2 = ItemPedido(produto2, 2)

    pedido = Pedido()
    pedido.adicionar_item(item1)
    pedido.adicionar_item(item2)

    print("Resumo do Pedido:")
    print(pedido)