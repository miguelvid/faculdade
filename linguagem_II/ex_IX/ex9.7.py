# Crie um programa que leia um data fornecida por um usuário (dia, mes e ano - podem ser lidos separadamente).
# A função deverá disparar uma exceção se o dia, mes ou ano fornecido for inválido informando uma mensagem de erro ao usuário

try:
    dia = int(input("Digite o dia: "))
    mes = int(input("Digite o mês: "))
    ano = int(input("Digite o ano: "))

    if not (1 <= mes <= 12):
        raise ValueError("Data inválida. Mês fora do intervalo (1-12).")
    
    max_day = 31 if mes in [1, 3, 5, 7, 8, 10, 12] else (30 if mes in [4, 6, 9, 11] else (29 if (ano % 4 == 0 and ano % 100 != 0) or (ano % 400 == 0) else 28))

    if not (1 <= dia <= max_day):
        raise ValueError("Data inválida. Dia fora do intervalo válido para o mês.")

    print(f"A data {dia}/{mes}/{ano} é válida.")

except ValueError as erro:
    print(f"Erro: {erro}")