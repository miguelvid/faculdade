# Exemplo de como proteger que novos atributos sejam criados dinamicamente na classe

# Pode-se usar __slots__
# O __slots__ avisa o Python para não usar um dicionário e apenas alocar espaço para um conjunto fixo de atributos.
# Embora __slots__ seja muito utilizado para não permitir que usuários de nossas classes criem outros atributos,
#   essa não é sua principal função nem o motivo de sua existência.


class Conta:

    __slots__ = ['_numero', '_titular', '_saldo', '_limite']

    def __init__(self, numero, titular, saldo, limite=1000.0):
        self._numero = numero
        self._titular = titular
        self._saldo = saldo
        self._limite = limite


c = Conta(123, "titular da conta", 50.0)

c.nome = "minha_conta" # ira gerar um erro
                       # c.nome = "minha_conta"
                       # AttributeError: 'Conta' object has no attribute 'nome'
                       # __slots__ nao permite que seja criado um novo atributo "nome" de forma dinamica


