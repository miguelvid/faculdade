# Torne a classe Conta abstrata.
    # import abc
    # class Conta(ABC):
        # def __init__(self, numero, titular, saldo=0, limite=1000.0):
             # self._titular = titular
             # self._saldo = saldo
             # self._limite = limite

    # outros métodos e propriedades

from abc import ABC, abstractmethod

class Conta(ABC):
    def __init__(self, numero, titular, saldo=0, limite=1000.0):
        self._numero = numero
        self._titular = titular
        self._saldo = saldo
        self._limite = limite

    @abstractmethod
    def sacar(self, valor):
        pass

    @abstractmethod
    def depositar(self, valor):
        pass

    def get_numero(self):
        return self._numero

    def get_limite(self):
        return self._limite
    
    def get_saldo(self):
        return self._saldo

class ContaCorrente(Conta):
    def sacar(self, valor):
        if valor <= 0:
            print("O valor de saque deve ser maior que zero.")
        elif valor <= self._saldo + self._limite:
            self._saldo -= valor
            print(f"Saque de R${valor} realizado. Saldo atual: R${self._saldo}")
        else:
            print("Saldo insuficiente.")

    def depositar(self, valor):
        if valor <= 0:
            print("O valor de depósito deve ser maior que zero.")
        else:
            self._saldo += valor
            print(f"Depósito de R${valor} realizado. Saldo atual: R${self._saldo}")


conta = ContaCorrente(0000, "miguel", saldo=33, limite=9999.0)
print(f"Conta número: {conta.get_numero()}, Titular: {conta._titular} Saldo:{conta.get_saldo()} Limite: {conta.get_limite()}")
conta.depositar(1000)
conta.sacar(500)