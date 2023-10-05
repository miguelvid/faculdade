# Exemplo de agregacao

# Exemplo semelhante ao composicao02.py porem ao inves de usar composicao utiliza agregacao


class Salario:
    def __init__(self, valor):
        self.valor = valor

    def get_total(self):
        return (self.valor * 12)


class Empregado:
    def __init__(self, s):
        self.salario = s  # <--- agregacao
                          #    estah sendo criada uma referencia para um objeto que jah existe

    def salario_anual(self):
        return "Total: " + str(self.salario.get_total())


if __name__ == "__main__":

    sal = Salario(10)     # cria um objeto salario e inicializa com 10

    emp = Empregado(sal)  # cria um empregado com salario 10
                          # "sal" eh um objeto
    print(emp.salario_anual())


    #------------------------------
    # note que se o objeto "emp" for excluido o objeto "sal" continua existindo
    # isso eh uma caracteristica da agregacao
    # ------------------------------