# Não conseguimos instanciar uma ContaInvestimento que herda Conta sem implementar o método abstrato atualiza() . Vamos criar uma implementação dentro da classe

# ContaInvestimento :
      # def atualiza(self, taxa):
          # self._saldo += self._saldo * taxa * 5

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
        self._saldo += self._saldo * taxa * 5 # pensei q ja era pra ter feiot isso nas anteriores(por isso elas ja tem atualizar)

if __name__ == '__main__':
    ci = ContaInvestimento('123-6', 'Maria', 1000.0)
    ci.atualiza(0.01)
    print(f"Saldo da Conta Investimento do titular {ci._titular}: R${ci.saldo}")