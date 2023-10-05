# Altera o valor do atributo de classe a cada instanciacao

class Conta:

    total_contas = 0

    def __init__(self, saldo):
        self._saldo = saldo
        Conta.total_contas += 1   # altera o valor do atributo de classe



c1 = Conta(100.0)
print(c1.total_contas)   # imprime 1

c2 = Conta(200.0)
print(c2.total_contas)   # imprime 2