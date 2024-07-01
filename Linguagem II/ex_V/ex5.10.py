class ContaCorrente:
    def __init__(self, saldo_inicial, cheque_especial):
        self.saldo = saldo_inicial
        self.cheque_especial = cheque_especial

    def deposita(self, valor):
        self.saldo += valor
        print(f"Depósito de R${valor:.2f} realizado.")

    def saque(self, valor):
        if self.saldo + self.cheque_especial >= valor:
            self.saldo -= valor
            print(f"Saque de R${valor:.2f} realizado.")
        else:
            print("Saldo insuficiente.")

    def extrato(self):
        print(f"Saldo: R${self.saldo:.2f}, Cheque Especial: R${self.cheque_especial:.2f}")


class Banco:
    def __init__(self):
        self.contas = []
        self.poupancas = []

    def abreConta(self, saldo_inicial, cheque_especial):
        conta = ContaCorrente(saldo_inicial, cheque_especial)
        self.contas.append(conta)
        print("Conta Corrente aberta.")

    def abrePoupanca(self, saldo_inicial):
        poupanca = Poupanca(saldo_inicial)
        self.poupancas.append(poupanca)
        print("Conta Poupança aberta.")

    def transferencia(self, conta_origem, conta_destino, valor):
        if conta_origem.saldo >= valor:
            conta_origem.saque(valor)
            conta_destino.deposita(valor)
            print("Transferência realizada.")
        else:
            print("Saldo insuficiente para transferência.")


class Poupanca:
    def __init__(self, saldo_inicial):
        self.saldo = saldo_inicial

    def deposita(self, valor):
        self.saldo += valor
        print(f"Depósito de R${valor:.2f} realizado na Poupança.")

    def saque(self, valor):
        if self.saldo >= valor:
            self.saldo -= valor
            print(f"Saque de R${valor:.2f} realizado na Poupança.")
        else:
            print("Saldo insuficiente na Poupança.")

    def extrato(self):
        print(f"Saldo na Poupança: R${self.saldo:.2f}")


if __name__ == "__main__":
    banco = Banco()

    banco.abreConta(1000.0, 500.0)
    banco.abrePoupanca(500.0)

    conta_corrente = banco.contas[0]
    poupanca = banco.poupancas[0]

    conta_corrente.deposita(200.0)
    conta_corrente.saque(300.0)

    poupanca.deposita(100.0)
    poupanca.saque(50.0)

    banco.transferencia(conta_corrente, poupanca, 150.0)

    print("Extratos:")
    conta_corrente.extrato()
    poupanca.extrato()