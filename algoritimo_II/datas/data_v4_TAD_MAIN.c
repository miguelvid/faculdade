#include <stdio.h>

typedef struct {
	int dia, mes, ano;
} data;

void setdia (data *d, int _dia) {
	d->dia = _dia;
}
void setmes (data *d, int _mes) {
	d->mes = _mes;
}
void setano (data *d, int _ano) {
	d->ano = _ano;
}
int getdia (data *d) {
	return d->dia;
}
int getmes (data *d) {
	return d->mes;
}
int getano (data *d) {
	return d->ano;
}
void setdata (data *d, int _dia, int _mes, int _ano) {
	d->dia = _dia;
	d->mes = _mes;
	d->ano = _ano;
}
int main (void) {
	int i, dia, mes, ano;
	data d[2];
	for (i = 0; i < 2; i++) {
		printf ("Dia[%d]: ", i); scanf ("%d", &dia);
		printf ("Mes[%d]: ", i); scanf ("%d", &mes);
		printf ("Ano[%d]: ", i); scanf ("%d", &ano);
		//setdia (&d[i], dia);
		//setmes (&d[i], mes);
		//setano (&d[i], ano);
		setdata (&d[i], dia, mes, ano);
	}
	printf ("1aData: %d-%d-%d\n", getdia(&d[0]), getmes(&d[0]), getano(&d[0]));
	printf ("2aData: %d-%d-%d\n", getdia(&d[1]), getmes(&d[1]), getano(&d[1]));
	system ("pause");
}