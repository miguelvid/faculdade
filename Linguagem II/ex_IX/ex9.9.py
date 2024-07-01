# Seja o trecho de programa Caixa

# minhaConta.deposita(100 );
# minhaConta.setLimite(100 );
# minhaConta.saca(1000 );

# Suponha que o método saca da classe Conta vai ser rescrito de forma a lançar uma
# conta for negativo. Implemente a classe ContaExceção. Implemente o método saca que lança a exceção.
# E rescreva o código caixa com o devido tratamento da exceção.

def saca(conta, valor):
    if conta['saldo'] - valor < -conta['limite']:
        raise Exception("Saldo da conta negativo. Não é possível sacar.")
    conta['saldo'] -= valor

minhaConta = {'saldo': 0, 'limite': 0}

try:
    minhaConta['saldo'] += 100
    minhaConta['limite'] = 100
    saca(minhaConta, 1000)
    print("Saque realizado com sucesso.")
except Exception as erro:
    print(f"Erro: {erro}")