# Exemplo de como "quebrar" o encapsulamento
# i.e. sem utilizar metodos para isso

# NOTA: QUEBRAR O ENCAPSULAMENTO NAO EH UMA BOA PRATICA


class MinhaClasse:

    def set_val(self, val):
        self.val = val

    def get_val(self):
        print(self.val)

a = MinhaClasse()
b = MinhaClasse()

a.set_val(10)
b.set_val(1000)

a.value = 100    # <== Escrita direta sem o metodo. Quebrou encapsulamento!!!

a.get_val()
b.get_val()
