# Implemente a seguinte estrutura de classes:
    # Item --absctract--
        # +empresta()
        # +retorna()
   
     # Livro
        # +bloqueia()
        # +desbloqueia()
                    # Periodico
   
     # ItemRestrito
        # +alterarnivel()
                    # Fita
                    # Sala Estudos

from abc import ABC, abstractmethod

class Item(ABC):
    def __init__(self):
        self.emprestado = False

    @abstractmethod
    def empresta(self):
        pass

    @abstractmethod
    def retorna(self):
        pass

class Livro(Item):
    def __init__(self):
        super().__init__()
        self.bloqueado = False

    def empresta(self):
        if not self.emprestado and not self.bloqueado:
            self.emprestado = True
            print("Livro emprestado com sucesso.")
        else:
            print("Não é possível emprestar o livro.")

    def retorna(self):
        if self.emprestado:
            self.emprestado = False
            print("Livro devolvido com sucesso.")
        else:
            print("O livro não estava emprestado.")

    def bloqueia(self):
        if not self.bloqueado:
            self.bloqueado = True
            print("Livro bloqueado com sucesso.")
        else:
            print("O livro já está bloqueado.")

    def desbloqueia(self):
        if self.bloqueado:
            self.bloqueado = False
            print("Livro desbloqueado com sucesso.")
        else:
            print("O livro não estava bloqueado.")

class ItemRestrito(Item):
    def __init__(self):
        super().__init__()
        self.nivel_acesso = 1

    def empresta(self):
        if not self.emprestado and self.nivel_acesso >= 2:
            self.emprestado = True
            print("Item restrito emprestado com sucesso.")
        else:
            print("Não é possível emprestar o item restrito.")

    def retorna(self):
        if self.emprestado:
            self.emprestado = False
            print("Item restrito devolvido com sucesso.")
        else:
            print("O item restrito não estava emprestado.")

    def alterar_nivel(self, novo_nivel):
        if novo_nivel >= 1 and novo_nivel <= 3:
            self.nivel_acesso = novo_nivel
            print("Nível de acesso do item restrito alterado para", novo_nivel)
        else:
            print("Nível de acesso inválido. Deve estar entre 1 e 3.")

livro = Livro()
item_restrito = ItemRestrito()

livro.empresta()
livro.bloqueia()
livro.empresta()
livro.desbloqueia()
livro.empresta()
livro.retorna()

item_restrito.alterar_nivel(0)
item_restrito.empresta()
item_restrito.retorna()

# Não entendi direito essa questao entao provavelmente ta errado(enchi linguiça nessa hehe).