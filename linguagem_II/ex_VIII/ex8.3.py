# Tente instânciar uma Conta :

# if __name__ == '__main__':
 #  c = Conta()

# O que acontece? Por que?


from abc import ABC, abstractmethod

class Conta(ABC):
    @abstractmethod
    def atualiza(self):
        pass

if __name__ == '__main__':  # TypeError: Can't instantiate abstract class Conta with abstract method atualiza
    c = Conta()             # não pode criar objetos diretamente a partir de classes abstratas.