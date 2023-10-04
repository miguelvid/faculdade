# Torne o método atualiza() abstrato:

# class Conta(ABC):
    # def atualiza():
    # pass

from abc import ABC, abstractmethod

class Conta(ABC):
    
    @abstractmethod
    def atualiza(self,att):
        pass