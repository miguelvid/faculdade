# Exemplo com metodo __init__

# __init__() sera invocado quando ocorrer uma instanciacao
#             ele eh invocado automaticamente!!!!


class MyNum(object):
    def __init__(self):
        print("Chamando __init__()!\n")
        self.val = 0

    def increment(self):
        self.val = self.val + 1
        print(self.val)

dd = MyNum()
dd.increment()  # imprime 1
dd.increment()  # imprime 2