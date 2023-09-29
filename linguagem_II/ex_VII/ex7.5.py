# Implemente a classe Funcionario e a classe Gerente.

# - crie a classe Assistente, que também é um funcionário, e que possui um número de matrícula (faça o método GET). Sobrescreva o método exibeDados().
# - sabendo que os Assistentes Técnicos possuem um bônus   salarial e que os Assistentes Administrativos possuem um turno (dia ou noite) e um adicional noturno, crie as classes       Tecnico e Administrativo.

class Funcionario:
    def __init__(self, nome, salario) -> None:
        self.nome = nome
        self.salario = salario
   
    def exibeDados(self):
        print(f"Nome: {self.nome}")
        print(f"Salário: R${self.salario:.2f}")
 
class Gerente(Funcionario):
    def __init__(self, nome, salario, area):
        super().__init__(nome, salario)
        self.area = area
   
    def exibeDados(self):
        super().exibeDados()
        print(f"Área: {self.area}")

class Assistente(Funcionario):
    def __init__(self, nome, salario, matricula):
        super().__init__(nome, salario)
        self.matricula = matricula

    def getMatricula(self):
        return self.matricula

    def exibeDados(self):
        super().exibeDados()
        print(f"Matricula: {self.matricula}")

class Tecnico(Assistente):
    def __init__(self, nome, salario, matricula, bonus):
        super().__init__(nome, salario, matricula)
        self.bonus = bonus

    def exibeDados(self):
        super().exibeDados()
        print(f"Bônus Salarial: R${self.bonus:.2f}")


class Administrativo(Assistente):
    def __init__(self, nome, salario, matricula, turno, adicional_noturno):
        super().__init__(nome, salario, matricula)
        self.turno = turno
        self.adicional_noturno = adicional_noturno

    def exibeDados(self):
        super().exibeDados()
        print(f"Turno: {self.turno}")
        print(f"Adicional Noturno: R${self.adicional_noturno:.2f}")


gerente = Gerente("Julia", 5000.00, "Vendas")
gerente.exibeDados()

tecnico = Tecnico("Miguel", 2500.00, "12345", 500.00)
tecnico.exibeDados()

administrativo = Administrativo("Pedrinho", 2200.00, "54321", "Noite", 100.00)
administrativo.exibeDados()