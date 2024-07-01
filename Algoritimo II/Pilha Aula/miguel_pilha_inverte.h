/* 
II - Codifique na linguagem C uma função que recebe uma PILHA e inverta o conteúdo desta
PILHA, tendo como base as seguintes considerações:
*/

void invertePilha(pilha *p) {
    pilha aux;
    inicializapilha(&aux); 


    while (!pilhavazia(p)) {
        empilha(&aux, topopilha(p));
        desempilha(p);
    }

    while (!pilhaVazia(&aux)) {
        empilha(p, topopilha(&aux));
        desempilha(&aux);
    }
}