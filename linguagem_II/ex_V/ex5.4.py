class Livro:
    def __init__(self, titulo, autor, isbn):
        self.titulo = titulo
        self.autor = autor
        self.isbn = isbn
        self.disponivel = True

    def emprestar(self):
        if self.disponivel:
            self.disponivel = False
            return True
        else:
            return False

    def devolver(self):
        self.disponivel = True

    def __str__(self):
        status = "Disponível" if self.disponivel else "Emprestado"
        return f"ISBN: {self.isbn}, Título: {self.titulo}, Autor: {self.autor}, Status: {status}"


class Pessoa:
    def __init__(self, nome):
        self.nome = nome

    def __str__(self):
        return f"Nome: {self.nome}"


class Emprestimo:
    def __init__(self, livro, pessoa):
        self.livro = livro
        self.pessoa = pessoa
        self.data_emprestimo = None

    def realizar_emprestimo(self):
        if self.livro.emprestar():
            self.data_emprestimo = "Hoje"
            return True
        else:
            return False

    def realizar_devolucao(self):
        self.livro.devolver()
        self.data_emprestimo = None

    def __str__(self):
        return f"Pessoa: {self.pessoa.nome}, Livro: {self.livro.titulo}, Data de Empréstimo: {self.data_emprestimo}"


def exibir_menu():
    print("\nControle de Empréstimo de Livros")
    print("1. Adicionar Livro")
    print("2. Listar Livros")
    print("3. Realizar Empréstimo")
    print("4. Realizar Devolução")
    print("5. Listar Empréstimos")
    print("6. Sair")


if __name__ == "__main__":
    livros = []
    emprestimos = []

    while True:
        exibir_menu()
        opcao = input("Escolha uma opção: ")

        if opcao == "1":
            titulo = input("Título do livro: ")
            autor = input("Autor do livro: ")
            isbn = input("ISBN do livro: ")
            livro = Livro(titulo, autor, isbn)
            livros.append(livro)
            print(f"Livro {titulo} adicionado à biblioteca.")

        elif opcao == "2":
            print("\nLista de Livros:")
            for livro in livros:
                print(livro)

        elif opcao == "3":
            nome_pessoa = input("Nome da pessoa que está pegando o livro emprestado: ")
            pessoa = Pessoa(nome_pessoa)
            isbn_livro = input("ISBN do livro a ser emprestado: ")
            livro_encontrado = None
            for livro in livros:
                if livro.isbn == isbn_livro:
                    livro_encontrado = livro
                    break
            if livro_encontrado:
                emprestimo = Emprestimo(livro_encontrado, pessoa)
                if emprestimo.realizar_emprestimo():
                    emprestimos.append(emprestimo)
                    print(f"{pessoa.nome} pegou o livro {livro_encontrado.titulo} emprestado.")
                else:
                    print(f"O livro {livro_encontrado.titulo} já está emprestado.")
            else:
                print(f"Livro com ISBN {isbn_livro} não encontrado.")

        elif opcao == "4":
            nome_pessoa = input("Nome da pessoa que está devolvendo o livro: ")
            isbn_livro = input("ISBN do livro a ser devolvido: ")
            for emprestimo in emprestimos:
                if emprestimo.pessoa.nome == nome_pessoa and emprestimo.livro.isbn == isbn_livro:
                    emprestimo.realizar_devolucao()
                    emprestimos.remove(emprestimo)
                    print(f"{pessoa.nome} devolveu o livro {livro.titulo}.")
                    break
            else:
                print("Não foi possível encontrar o empréstimo correspondente.")

        elif opcao == "5":
            print("\nLista de Empréstimos:")
            for emprestimo in emprestimos:
                print(emprestimo)

        elif opcao == "6":
            print("Saindo do Controle de Empréstimo de Livros. Até logo!")
            break

        else:
            print("Opção inválida. Por favor, escolha uma opção válida.")