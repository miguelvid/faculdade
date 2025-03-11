#define ERRO_LISTA -9999

/* OPERA��ES B�SICAS : ATRIBUTOS ********************************************/

void inicializa_lista (lista *l) {;}
void settrue_lista (lista *l) {;}
void setfalse_lista (lista *l) {;}
void setprimeiro_lista (lista *l, nolista *no) {;}
void setproximo_lista (nolista *no, nolista *proximo) {;}
void setultimo_lista (lista *l, nolista *no) {;}
int isvazia_lista (lista *l) { return 0; }
int ischeia_lista (lista *l) { return 0; }
int isoperacao_lista (lista *l) { return 0; }

/* ENDERE�OS PARA CONSULTA **************************************************/

nolista *addressprimeiro_lista (lista *l) { return NULL; }
nolista *addressultimo_lista (lista *l) { return NULL; }
nolista *addressproximo_lista (nolista *no) { return NULL; }
nolista *addressanterior_lista (lista *l, nolista *no) { return NULL; }
nolista *addresschave_lista (lista *l, int chave) { return NULL; }
nolista *addressno_lista (lista *l, int noPosicao) { return NULL; }
nolista *addressnoanterior_lista (lista *l, int noposicao) { return NULL; }

/* OPERA��ES PARA ALOCA��O DO N� E LIGA��O NA LISTA *************************/

nolista *alocano_lista (lista *l, nolista *proximo, nolista *anterior, int chave) { return NULL; }
void setinicio_lista (lista *l, nolista *noInserir) {;}
void setfim_lista (lista *l, nolista *noInserir, nolista *ultimoNo) {;}
void setno_lista (lista *l, nolista *noInserir, nolista *noAnterior) {;}

/* OPERA��ES DE CONSULTA ****************************************************/

int getchave_lista (lista *l, nolista *no) { return 0; }
int getinicio_lista (lista *l) { return 0; }
int getfim_lista (lista *l) { return 0; }
int getchaveno_lista (lista *l, int no) { return 0; }
int getnochave_lista (lista *l, int chave) { return 0; }
int gettamanho_lista (lista *l) { return 0; }
int getquantidade_lista (lista *l, int chave) { return 0; }
int getnoinsercaoordenada_lista (lista *l, int chave) { return 0; }

/* OPERA��ES DE INSER��O ****************************************************/

void insere_lista (lista *l, nolista *noProximo, nolista *noAnterior, int chave) {;}
void insereinicio_lista (lista *l, int chave) {;}
void inserefim_lista (lista *l, int chave) {;}
void insereno_lista (lista *l, int chave, int noposicao) {;}
void insereordenado_lista (lista *l, int chave) {;}

/* OPERA��ES DE REMO��O *****************************************************/

void retirano_lista (lista *l, nolista *noRemover, nolista *noProximo, nolista *noAnterior) {;}
void removeaddress_lista (lista *l, nolista *noRemover) {;}
void removeinicio_lista (lista *l) {;}
void removefim_lista (lista *l) {;}
void removeno_lista (lista *l, int noposicao) {;}
void removechave_lista (lista *l, int chave) {;}
void remove_lista (lista *l, int chave) {;}
void remocao_lista (lista *l, int chave) {;}

/* OUTRAS OPERA��ES *********************************************************/

void libera_lista (lista *l) {;}
void liberano_lista (nolista *no) {;}
void removerecursivo_lista (lista *l) {;}
void removeajusta_lista (lista *l) {;}
void inverte_lista (lista *l) {;}

/* OPERA��ES COMPLEMENTARES *************************************************/

void inversao_lista (lista *l) {;}

void exibeestrutura_lista (lista *l) {
	nolista *noAtual = addressprimeiro_lista (l);
	nolista *anterior = addressultimo_lista (l);
	int no = 1;
	printf ("\n&Lista: %x   &PrimeiroNo': %x  &UltimoNo': %x\n", &(*l), noAtual, anterior);
	if (!isvazia_lista (l)) {
		printf ("                                   Funcoes p/ Retorno de Enderecos");
		printf ("\nNo' &No'   Anterior Proximo Chave  &Anter. &Proxim &No'Ant &Chave");
		printf ("\n--  ------ -------- ------- -----  ------- ------- ------- -------\n");
		do {
			#ifdef LISTA_DUPLA //--------------------------
			anterior = addressanterior_lista (l, noAtual);
			#endif //--------------------------------------
			printf ("%2d %7x  %7x %7x ", no, noAtual, anterior, addressproximo_lista (noAtual));
			printf ("%5d  %7x", getchave_lista (l, noAtual), addressanterior_lista (l, noAtual));
			printf ("%7x %7x ", addressproximo_lista (noAtual), addressnoanterior_lista (l, no) );
			printf ("%7x\n", addresschave_lista (l, noAtual->chave));
			noAtual = noAtual->proximo;
			no++;
		} while (noAtual);
	}
}

