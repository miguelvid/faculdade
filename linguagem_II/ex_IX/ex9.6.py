# Crie um programa que leia um valor. Se o valor lido for um caracter deverá ser
# disparada uma exceção informando que o programa somente aceita valores inteiros. Se o valor lido for um inteiro, 
# deverá ser efetuada a seguinte análise baseada em faixas:

# – Menor ou igual a 0 (zero): disparar uma exceção com a mensagem ValorAbaixoException
# – Maior que 100 e menor que 1000 : disparar uma exceção com a mensagem ValorAltoException
# – Maior ou igual a 1000: disparar uma exceção com a mensagem ValorMuitoAltoException

try:
    valor = input("Digite um valor inteiro: ")

    if not valor.isdigit():
        raise ValueError("O programa aceita somente valores inteiros")

    valor = int(valor)

    if valor <= 0:
        raise Exception("Valor abaixo da faixa permitida")
    elif 100 < valor < 1000:
        raise Exception("Valor alto, mas dentro da faixa permitida")
    elif valor >= 1000:
        raise Exception("Valor muito alto")

except ValueError as erro:
    print(f"Erro: {erro}")
except Exception as erro:
    print(f"Erro: {erro}")