# Crie uma classe chamada ContaInvestimento :
    # class ContaInvestimeto(Conta):
      # pass

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

class ContaInvestimento(Conta):
    def atualiza(self, taxa):
        self._saldo += self._saldo * taxa

if __name__ == '__main__':
    conta_invest = ContaInvestimento('000-0', 'Miguel', 2000.0)
    conta_invest.atualiza(0.06) #%6
    print(f"Saldo da Conta Investimento do titular {conta_invest._titular}: R${conta_invest.saldo}")