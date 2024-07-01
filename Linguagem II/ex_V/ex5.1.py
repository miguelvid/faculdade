class CadastroEmpregado:
    def __init__(self, nome, idade, funcao, data_nascimento, telefone, peso, altura, salario):
        self.nome = nome
        self.idade = idade
        self.funcao = funcao
        self.data_nascimento = data_nascimento
        self.telefone = telefone
        self.peso = peso
        self.altura = altura
        self.salario = salario

    def exibir_informacoes(self):
        print(f"Nome: {self.nome}")
        print(f"Idade: {self.idade} anos")
        print(f"Função: {self.funcao}")
        print(f"Data de Nascimento: {self.data_nascimento}")
        print(f"Telefone: {self.telefone}")
        print(f"Peso: {self.peso} kg")
        print(f"Altura: {self.altura} m")
        print(f"Salário: R${self.salario:.2f}")

if __name__ == "__main__":
    empregado1 = CadastroEmpregado("Miguel", 00, "Jogador caro", "00/00/00", "(00) 000-0000", 00, 0.00, 00.0)
    empregado2 = CadastroEmpregado("JUssaara", 00, "Desenvolvedora", "00/00/00", "(00) 000-0000", 00, 0.00, 00.0)

    empregado1.exibir_informacoes()
    empregado2.exibir_informacoes()


   
      