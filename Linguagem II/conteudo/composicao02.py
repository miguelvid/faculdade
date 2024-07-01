# Exemplo de composicao

class Salario:
    def __init__(self, valor):
        self.valor = valor

    def get_total(self):
        return (self.valor * 12)


class Empregado:
    def __init__(self, v):
        self.salario = Salario(v)  # <--- composicao
                                   #    estamos instanciando um objeto de outra classe!!!!

    def salario_anual(self):
        return "Total: " + str(self.salario.get_total())


if __name__ == "__main__":
    emp = Empregado(10)  # cria um empregado com salario 10
    print(emp.salario_anual())
