# Implemente a  classe Administrador  como  subclasse da classe Empregado. Um determinado administrador tem os atributos herdados da classe Pessoa  e  da classe Empregado mais o atributo  ajudasDeCusto  (um valor que indica quanto o Administrador irá receber de ajuda de custo referente  a viagens,  estadias,  ...). 

# Você  deverá  redefinir  na classe  Administrador  o método herdado calcularSalario (o salário de um administrador é equivalente ao salário de  um  Empregado usual  acrescido das  ajudas de  custo -  não esqueça que você pode utilizar o método original da classe Empregado como base...). 

# Escreva  um programa de teste adequado para esta classe

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


class Administrador(Empregado):
    def __init__(self, nome, endereco, salarioBase, mesesTrabalhados, ajudasDeCusto):
        super().__init__(nome, endereco, salarioBase, mesesTrabalhados)
        self.ajudasDeCusto = ajudasDeCusto

    def get_ajudasDeCusto(self):
        return self.ajudasDeCusto

    def set_ajudasDeCusto(self, ajudasDeCusto):
        self.ajudasDeCusto = ajudasDeCusto

    def calcularSalario(self):
        return super().calcularSalario() + self.ajudasDeCusto


if __name__ == "__main__":
    administrador = Administrador("Admin_1", "Rua tal, nº tal", 000, 00, 000)

    print("Nome:", administrador.get_nome())
    print("Endereco:", administrador.get_endereco())
    print("Salario:", administrador.get_salarioBase())
    print("Meses Trabalhados:", administrador.get_mesesTrabalhados())
    print("Ajudas de Custo :", administrador.get_ajudasDeCusto())
    print("Salário:", administrador.calcularSalario())