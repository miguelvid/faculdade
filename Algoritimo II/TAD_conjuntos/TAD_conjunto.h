#define TAM_CONJUNTO 5 // número de membros do conjunto
#define NOT_MEMBRO -1 // valor que indica que não é um membro
typedef struct {
int memoria[TAM_CONJUNTO];
} conjunto;
/* Operação de inicialização do conjunto:
Cada célula do vetor memoria representará um membro do conjunto, quando este
membro não existir, a célula será preenchida com o valor -1 (NOT_MEMBRO) */
void inicializa_conjunto (conjunto *c) {
int x;
for (x = 0; x < TAM_CONJUNTO; x++) c->memoria[x] = NOT_MEMBRO;
}
/* Esta operação receberá como parâmetros: Um conjunto e Um membro e,
retornará 0 ou 1 (1 - caso este membro já exista no conjunto) */
int ismembro_conjunto (conjunto *c, int membro) {
int x, existe;
for (x = existe = 0; x < TAM_CONJUNTO; x++)
if (c->memoria[x] == membro) existe = 1;
return existe;
}
// Esta operação receberá como parâmetros: Um conjunto e Um membro para ser inserido
void setmembro_conjunto (conjunto *c, int membro) {
int x = 0;
if (!ismembro_conjunto (c, membro)) //verifica se já existe
while (x < TAM_CONJUNTO) {
if (c->memoria[x] < 0) {
c->memoria[x] = membro;
break;
}
x++;
}
}
/* Esta operação receberá como parâmetros: 3 conjuntos (a, b, c)
O conjunto c será inicializado e irá conter o resultado da intersecção de a com b */

void interseccao_conjunto (conjunto *a, conjunto *b, conjunto *c) {
int x = 0;
inicializa_conjunto (c);
for (x = 0; x < TAM_CONJUNTO; x++)
if (a->memoria[x] >= 0)
if (ismembro_conjunto (b, a->memoria[x]))
setmembro_conjunto (c, a->memoria[x]);

}
// Esta operação retornará 0 ou 1 (1 - caso o conjunto esteja lotado de membros)
int ischeio_conjunto (conjunto *c) {
int x, cheio = 1;
for (x = 0; x < TAM_CONJUNTO; x++)
if (c->memoria[x] == NOT_MEMBRO) cheio = 0;
return cheio;
}
/* Esta operação receberá como parâmetro um Membro e, retornará 0 ou 1
(1 - caso este membro seja um valor válido). São valores válidos para números
naturais 0, 1, 2, ... (números inteiros positivos mais o ZERO) */
int isvalido_conjunto (int membro) {
if (membro >= 0) return 1;
return 0;
}
/* Esta operação receberá como parâmetros um Membro e uma
Posição de célula do vetor do conjunto e, retornará o Membro referente
a esta posição ou -1 caso não exista membro ou a posição for inválida */
int getmembro_conjunto (conjunto *c, int posicao) {
if (posicao < TAM_CONJUNTO) return c->memoria[posicao];
return NOT_MEMBRO;
}
// Esta operação retornará o limite de membros para um conjunto
int getlimite_conjunto (void) {
return TAM_CONJUNTO;
}