#define ERRO_LISTA -99999

typedef struct nolista {
	int chave;
	struct nolista *proximo;
	struct nolista *anterior;
} nolista, lista;

/* OPERAÇÕES BÁSICAS : ATRIBUTOS ********************************************/

void inicializa_lista (lista *l) {
	l->proximo = NULL;
	l->anterior = NULL;
}

void settrue_lista (lista *l) {;}
void setfalse_lista (lista *l) {;}
void setprimeiro_lista (lista *l, nolista *no) {;}
void setproximo_lista (nolista *no, nolista *proximo) {;}
void setultimo_lista (lista *l, nolista *no) {;}

int isvazia_lista (lista *l) {
	if (l->proximo == NULL) return 1;
	return 0;
}

int ischeia_lista (lista *l) { return 0; }
int isoperacao_lista (lista *l) { return 0; }

/* ENDEREÇOS PARA CONSULTA **************************************************/

nolista *addressprimeiro_lista (lista *l) { return NULL; }
nolista *addressultimo_lista (lista *l) { return NULL; }
nolista *addressproximo_lista (nolista *no) { return NULL; }
nolista *addressanterior_lista (lista *l, nolista *no) { return NULL; }
nolista *addresschave_lista (lista *l, int chave) { return NULL; }
nolista *addressno_lista (lista *l, int noPosicao) { return NULL; }
nolista *addressnoanterior_lista (lista *l, int noposicao) { return NULL; }

/* OPERAÇÕES PARA ALOCAÇÃO DO NÓ E LIGAÇÃO NA LISTA *************************/

nolista *alocano_lista (lista *l, nolista *proximo, nolista *anterior, int chave) {;}
void setinicio_lista (lista *l, nolista *noInserir) {;}
void setfim_lista (lista *l, nolista *noInserir, nolista *ultimoNo) {;}
void setno_lista (lista *l, nolista *noInserir, nolista *noAnterior) {;}

/* OPERAÇÕES DE CONSULTA ****************************************************/

int getchave_lista (lista *l, nolista *no) { return 0; }

int getinicio_lista (lista *l) {
	if (!isvazia_lista (l)) {
		l = l->proximo;
		return (l->chave);
	}
	 return ERRO_LISTA;
}

int getfim_lista (lista *l) { return 0; }
int getchaveno_lista (lista *l, int no) { return 0; }
int getnochave_lista (lista *l, int chave) { return 0; }
int gettamanho_lista (lista *l) { return 0; }
int getquantidade_lista (lista *l, int chave) { return 0; }
int getnoinsercaoordenada_lista (lista *l, int chave) { return 0; }

/* OPERAÇÕES DE INSERÇÃO ****************************************************/

void insere_lista (lista *l, nolista *noProximo, nolista *noAnterior, int chave) {;}

void insereinicio_lista (lista *l, int chave) {
	nolista *noAtual = l->proximo;
	nolista *noAlocado = (nolista *) malloc (sizeof(nolista));
	if (noAlocado) {
		noAlocado->chave = chave;
		noAlocado->proximo = l->proximo;
		noAlocado->anterior = NULL;
		if (!isvazia_lista (l)) {
			noAtual->anterior = noAlocado;
			if (l->proximo == l->anterior)
				l->anterior = noAlocado;
		}
		else {
			l->anterior = l->proximo;
		}
		l->proximo = noAlocado;
	}
}

void inserefim_lista (lista *l, int chave) {;}
void insereno_lista (lista *l, int chave, int noposicao) {;}
void insereordenado_lista (lista *l, int chave) {;}

/* OPERAÇÕES DE REMOÇÃO *****************************************************/

void retirano_lista (lista *l, nolista *noRemover, nolista *noProximo, nolista *noAnterior) {;}
void removeaddress_lista (lista *l, nolista *noRemover) {;}
void removeinicio_lista (lista *l) {;}
void removefim_lista (lista *l) {;}
void removeno_lista (lista *l, int noposicao) {;}
void removechave_lista (lista *l, int chave) {;}
void remove_lista (lista *l, int chave) {;}
void remocao_lista (lista *l, int chave) {;}

/* OUTRAS OPERAÇÕES *********************************************************/

void libera_lista (lista *l) {;}
void liberano_lista (nolista *no) {;}
void removerecursivo_lista (lista *l) {;}
void removeajusta_lista (lista *l) {;}
void inverte_lista (lista *l) {;}

/* OPERAÇÕES COMPLEMENTARES *************************************************/

void inversao_lista (lista *l) {;}

void exibeestrutura_lista (lista *l) {
	nolista *noAtual = l->proximo;
	int no = 1;
	printf ("\n&Lista: %x   &PrimeiroNo': %x  &UltimoNo': %x\n", &(*l), l->proximo, l->anterior);
	if (!isvazia_lista (l)) {
		printf ("                                   ");
		printf ("\nNo' &No'   Anterior Proximo Chave");
		printf ("\n--  ------ -------- ------- -----\n");
		do {
			printf ("%2d %7x  %7x %7x ", no, noAtual, noAtual->anterior, noAtual->proximo);
			printf ("%5d\n", noAtual->chave);
			noAtual = noAtual->proximo;
			no++;
		} while (noAtual);
	}
}

