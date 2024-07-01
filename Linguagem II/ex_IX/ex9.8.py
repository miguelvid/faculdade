# Crie um programa que faça a soma de dois inteiros e se a soma for maior que 50 deverá ser disparada uma exceção.
# Essa exceção deverá ser capturada por um bloco catch genérico

try:
    num1 = int(input("Digite o primeiro número inteiro: "))
    num2 = int(input("Digite o segundo número inteiro: "))
    
    resultado = num1 + num2
    
    if resultado > 50:
        raise Exception("A soma é maior que 50")
    
    print(f"A soma é {resultado}")
    
except Exception as erro:
    print(f"Erro: {erro}")