# Definicao de atributos de classe

# Atributos definidos fora de qualquer metodo sao chamados de atributos de classe
#    existe somente uma copia dele compartilhada com todas instancias
#    ---> Quem controla o valor do atributo é a classe e nao um objeto em si

# Atributos definidos dentro do __init__ sao chamados de atributos de instancia
#    cada instancia possui sua propria "copia" do atributo

class Classe:
    att_cl = 10  # atributo de classe

    def __init__(self):
        self.att_inst = 100  # atributo de instancia

a = Classe()
b = Classe()

print(a.att_cl)  #imprime 10
print(b.att_cl)  #imprime 10

Classe.att_cl = 5   # altera o valor do atributo da classe
                    # lembrando que quem controla o valor do atributo eh a classe
                    #    e nao um objeto em si

print(a.att_cl)  #imprime 5
print(b.att_cl)  #imprime 5

print(a.att_inst)  #imprime 100
print(b.att_inst)  #imprime 100

