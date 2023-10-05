# Exemplo com metodo __init__
#
# Contem atributos e metodos de instancia


class Pessoa:

    def __init__(self, n, i):
        self.__nome = n
        self.__idade = i

    def digaOi(self):
        print("Oi, meu nome é %s e eu tenho %s anos" % (self.__nome, self.__idade))

    def get_idade(self):
        return self.__idade

    def set_idade(self, num):
        if isinstance(num, int):  # verificacao se idade informada eh um inteiro
            if num > 0:
                self.__idade = num
                return
            else:
                print('Erro de formato')


# class instance
pessoa = Pessoa("Ober", 10)

pessoa.digaOi()
print(pessoa.get_idade())

pessoa.set_idade("123")
print(pessoa.get_idade())
