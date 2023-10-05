# Exemplo de como efetuar a agregacao


class Cliente:

    def __init__(self, nome, sobrenome, cpf):
        self.nome = nome
        self.sobrenome = sobrenome
        self.cpf = cpf

    def get_nome(self):
        return self.nome


class Conta:

    def __init__(self, numero, cliente, saldo, limite):
        self.numero = numero
        self.titular = cliente    # agrega o objeto cliente passado como parametro
        self.saldo = saldo
        self.limite = limite

    def get_titular(self):
        return self.titular.get_nome()  # invoca o metodo get_nome() da classe Cliente

if __name__ == "__main__":
    cliente = Cliente('Joao', 'Oliveira', '1111111111-1')
    minha_conta = Conta('123-4', cliente, 120.0, 1000.0)  #cria uma conta agregando um cliente

    print( minha_conta.get_titular())  # imprime "Joao"

    #------------------------------
    # note que se o objeto "minha_conta" for excluido o objeto cliente continua existindo
    # isso eh uma caracteristica da agregacao
    # ------------------------------