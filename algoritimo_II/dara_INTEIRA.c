#include <stdio.h>

// Definição da estrutura para armazenar a data
typedef struct {
    int dia, mes, ano;
} data;

// Funções para definir e obter os componentes da data individualmente
void setdia(data *d, int _dia) {
    d->dia = _dia;
}

void setmes(data *d, int _mes) {
    d->mes = _mes;
}

void setano(data *d, int _ano) {
    d->ano = _ano;
}

int getdia(data *d) {
    return d->dia;
}

int getmes(data *d) {
    return d->mes;
}

int getano(data *d) {
    return d->ano;
}

// Função para definir a data como um todo
void setdata(data *d, int _dia, int _mes, int _ano) {
    d->dia = _dia;
    d->mes = _mes;
    d->ano = _ano;
}

// Função para definir a data a partir de um valor inteiro de 6 ou 8 dígitos
void setdata_inteira(data *d, int _inteira) {
    int dia, mes, ano;

    // Verificação se o valor de data fornecido é válido
    if (_inteira < 100000|| _inteira > 99991231) {
        printf("Valor de data inválido.\n");
        return;
    }

    if (_inteira < 1000000) {
        dia = _inteira / 10000;  // Os 2 primeiros dígitos representam o dia
        mes = (_inteira % 10000) / 100;  // O próximo dígito representa o mês
        ano = _inteira % 100;  // Os 2 últimos dígitos representam o ano
    } else {
        dia = _inteira / 1000000;  // Os 2 primeiros dígitos representam o dia
        mes = (_inteira % 1000000) / 10000;  // Os próximos 2 dígitos representam o mês
        ano = _inteira % 10000;  // Os 4 últimos dígitos representam o ano
    }

    // Atribuição dos componentes extraídos à estrutura de data fornecida
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
}

int main(void) {
    int i, inteira;
    data d[2];

    // Loop para obter as datas inteiras e definir as datas correspondentes
    for (i = 0; i < 2; i++) {
        printf("Data inteira[%d]: ", i);
        scanf("%d", &inteira);
        setdata_inteira(&d[i], inteira);
    }

    // Impressão das datas definidas
    printf("1aData: %d-%d-%d\n", getdia(&d[0]), getmes(&d[0]), getano(&d[0]));
    printf("2aData: %d-%d-%d\n", getdia(&d[1]), getmes(&d[1]), getano(&d[1]));

    return 0;
}
