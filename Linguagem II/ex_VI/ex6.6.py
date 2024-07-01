# Implemente a  classe  Operario  como  subclasse  da classe  Empregado.  Um determinado operário  tem  como  atributos,  além  dos  atributos  da classe Pessoa  e da  classe Empregado, o  atributo  valorProducao  (que corresponde  ao valor monetário dos artigos efetivamente produzidos pelo operário) e comissao (que corresponde  ao valor que será adicionado  ao vencimento base  do operário -  não esqueça que você pode utilizar o método original da classe Empregado como base...). 

# Você deverá  redefinir  nesta  subclasse  o método  herdado  calcularSalario  (o  salário  de  um  operário  é equivalente ao salário de  um  empregado usual  acrescido da  referida  comissão). 

# Escreva  um programa de teste adequado para esta classe.

class Pessoa:
    def __init__(self, nome, endereco):
        self.nome = nome
        self.endereco = endereco

    def get_nome(self):
        return self.nome

    def set_nome(self, nome):
        self.nome = nome

    def get_endereco(self):
        return self.endereco

    def set_endereco(self, endereco):
        self.endereco = endereco


class Empregado(Pessoa):
    def __init__(self, nome, endereco, salarioBase, mesesTrabalhados):
        super().__init__(nome, endereco)
        self.salarioBase = salarioBase
        self.mesesTrabalhados = mesesTrabalhados

    def get_salarioBase(self):
        return self.salarioBase

    def set_salarioBase(self, salarioBase):
        self.salarioBase = salarioBase

    def get_mesesTrabalhados(self):
        return self.mesesTrabalhados

    def set_mesesTrabalhados(self, mesesTrabalhados):
        self.mesesTrabalhados = mesesTrabalhados

    def calcularSalario(self):
        return self.salarioBase * self.mesesTrabalhados


class Operario(Empregado):
    def __init__(self, nome, endereco, salarioBase, mesesTrabalhados, valorProducao, comissao):
        super().__init__(nome, endereco, salarioBase, mesesTrabalhados)
        self.valorProducao = valorProducao
        self.comissao = comissao

    def get_valorProducao(self):
        return self.valorProducao

    def set_valorProducao(self, valorProducao):
        self.valorProducao = valorProducao

    def get_comissao(self):
        return self.comissao

    def set_comissao(self, comissao):
        self.comissao = comissao

    def calcularSalario(self):
        return super().calcularSalario() + self.comissao


if __name__ == "__main__":
    operario = Operario("Operario_1", "Rua tal, nº tal", 000, 00, 000, 000)

    print("Nome:", operario.get_nome())
    print("Endereço:", operario.get_endereco())
    print("Salário Base do Operio:", operario.get_salarioBase())
    print("Meses Trabalhados:", operario.get_mesesTrabalhados())
    print("Valor de Produção:", operario.get_valorProducao())
    print("Comissão:", operario.get_comissao())
    print("Salário do Operario:", operario.calcularSalario())