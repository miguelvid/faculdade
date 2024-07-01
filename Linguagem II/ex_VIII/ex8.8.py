# Agora teste instanciando uma ContaInvestimento e chame o método atualiza()

# ci = ContaInvestimento('123-6', 'Maria', 1000)
# ci.deposita(1000.0)
# ci.atualiza(0.01)
# print(ci.saldo)

from abc import ABC, abstractmethod

class Conta(ABC):
    def __init__(self, numero, titular, saldo=0):
        self._numero = numero
        self._titular = titular
        self._saldo = saldo

    @abstractmethod
    def deposita(self, valor):
        pass

    @abstractmethod
    def atualiza(self, taxa):
        pass

    @property
    def saldo(self):
        return self._saldo

class ContaInvestimento(Conta):
    def deposita(self, valor):
        self._saldo += self.saldo + valor

    def atualiza(self, taxa):
        self._saldo += self._saldo * taxa * 5 

if __name__ == '__main__':
    ci = ContaInvestimento('123-6', 'Maria', 1000.0)
    ci.deposita(1000.0)
    ci.atualiza(0.01)
    print(f"Saldo da Conta Investimento do titular {ci._titular}: R${ci.saldo}")