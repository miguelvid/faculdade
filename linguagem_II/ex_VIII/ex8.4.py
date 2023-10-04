# Defina o código necessário para que você consiga instanciar uma ContaCorrente e uma ContaPoupanca da seguinte forma:

# if __name__ == '__main__':
     # cc = ContaCorrente('123-4', 'João', 1000.0)
     # cp = ContaPoupanca('123-5', 'José', 1000.0)

     #  cc.atualiza(0.01)
     # cp.atualiza(0.01)
     # print(cc.saldo)
     # print(cp.saldo)

# *** ContaCorrente e ContaPoupanca são derivadas da classe abstrata Conta ***


from abc import ABC, abstractmethod

class Conta(ABC):
    def __init__(self, numero, titular, saldo=0, limite=1000.0):
        self._numero = numero
        self._titular = titular
        self._saldo = saldo
        self._limite = limite

    @abstractmethod
    def atualiza(self, taxa):
        pass

    # permite que você defina um método como uma propriedade de um objeto.
    @property
    def saldo(self):
        return self._saldo
    
    # permite que você defina um método como uma propriedade de um objeto.
    @property
    def titular(self):
        return self._titular

class ContaCorrente(Conta):
    def atualiza(self, taxa):
        self._saldo += self._saldo * taxa

class ContaPoupanca(Conta):
    def atualiza(self, taxa):
        self._saldo += self._saldo * taxa

if __name__ == '__main__':
    cc = ContaCorrente('000-0', 'Julia', 1000.0)
    cp = ContaPoupanca('000-0', 'Miguel', 1000.0)

    cc.atualiza(0.01)
    cp.atualiza(0.02) 

    print(f"Saldo da Conta Corrente do titular {cc.titular}: R${cc.saldo}") # permitiu acessar o metodo como se fosse um atibuto
    print(f"Saldo da Conta Poupança do tutular {cp.titular}: R${cp.saldo}") # permitiu acessar o metodo como se fosse um atibuto 