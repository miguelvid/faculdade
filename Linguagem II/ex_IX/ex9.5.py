# Crie um programa que leia dois valores e divida o primeiro pelo segundo.
# Dispare uma exceção se o segundo valor lido for zero ou menor que zero informando ao usuário o motivo

try:
    val1 = int(input("Digite o primeiro valor: "))
    val2 = int(input("Digite o segundo valor: "))
    
    if val2 <= 0:
        raise ValueError("O segundo valor deve ser maior que zero.")
    
    resultado = val1 // val2 
    print(f"Resultado da divisão: {resultado}")
except ValueError as erro:
    print(f"Erro: {erro}")
except ZeroDivisionError:
    print("Erro: Divisão por zero não é permitida.")