# Instancie um objeto de cada uma das classes concretas do exercicio anterior

from abc import ABC, abstractmethod

class Conta(ABC):
    def __init__(self, numero, titular, saldo=0):
        self._numero = numero
        self._titular = titular
        self._saldo = saldo

    @abstractmethod
    def atualiza(self, taxa):
        pass

    @property
    def saldo(self):
        return self._saldo

class ContaCorrente(Conta):
    def atualiza(self, taxa):
        self._saldo += self._saldo * taxa

class ContaPoupanca(Conta):
    def atualiza(self, taxa):
        self._saldo += self._saldo * taxa

class ContaInvestimento(Conta):
    def atualiza(self, taxa):
        self._saldo += self._saldo * taxa * 5

if __name__ == '__main__':
    # ContaCorrente
    cc = ContaCorrente('000-0', 'Maria1', 1000.0)
    cc.atualiza(0.01)
    print(f"Saldo da Conta Corrente do {cc._titular}: R${cc.saldo}")

    # ContaPoupanca
    cp = ContaPoupanca('000-0', 'Maria2', 1000.0)
    cp.atualiza(0.02) 
    print(f"Saldo da Conta Poupança do {cp._titular}: R${cp.saldo}")

    # ContaInvestimento
    ci = ContaInvestimento('000-0', 'Maria3', 1000.0)
    ci.atualiza(0.01)
    print(f"Saldo da Conta Investimento da {ci._titular}: R${ci.saldo}")