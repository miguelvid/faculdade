class Contato:
    def __init__(self, nome, telefone):
        self.nome = nome
        self.telefone = telefone

    def __str__(self):
        return f"Nome: {self.nome}, Telefone: {self.telefone}"


class Agenda:
    def __init__(self):
        self.contatos = []

    def adicionar_contato(self, contato):
        self.contatos.append(contato)

    def remover_contato(self, nome):
        contatos_removidos = [contato for contato in self.contatos if contato.nome == nome]
        for contato in contatos_removidos:
            self.contatos.remove(contato)

    def buscar_contato(self, nome):
        return [contato for contato in self.contatos if contato.nome == nome]

    def listar_contatos(self):
        for contato in self.contatos:
            print(contato)


def exibir_menu():
    print("\nAgenda Telefônica")
    print("1. Adicionar Contato")
    print("2. Remover Contato")
    print("3. Buscar Contato")
    print("4. Listar Contatos")
    print("5. Sair")


if __name__ == "__main__":
    minha_agenda = Agenda()

    while True:
        exibir_menu()
        opcao = input("Escolha uma opção: ")

        if opcao == "1":
            nome = input("Nome do contato: ")
            telefone = input("Telefone do contato: ")
            contato = Contato(nome, telefone)
            minha_agenda.adicionar_contato(contato)
            print(f"Contato {nome} adicionado à agenda.")

        elif opcao == "2":
            nome = input("Nome do contato a ser removido: ")
            minha_agenda.remover_contato(nome)
            print(f"Contato {nome} removido da agenda.")

        elif opcao == "3":
            nome = input("Nome do contato a ser buscado: ")
            contatos_encontrados = minha_agenda.buscar_contato(nome)
            if contatos_encontrados:
                print("Contatos encontrados:")
                for contato in contatos_encontrados:
                    print(contato)
            else:
                print(f"Contato {nome} não encontrado na agenda.")

        elif opcao == "4":
            print("\nLista de Contatos:")
            minha_agenda.listar_contatos()

        elif opcao == "5":
            print("Saindo da Agenda Telefônica. Até logo!")
            break

        else:
            print("Opção inválida. Por favor, escolha uma opção válida.")