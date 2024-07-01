/*
Qual o valor de Y no final do programa? Tente primeiro descobrir e depois verifique no computador o resultado.


int main() {
int y, *p, x;
y = 0;
p = &y;
x = *p;
x = 4;
(*p)++;

(*p) += x;
printf ("y = %d\n", y);
return(0);
}
*/

int main()

{
    int y, *p, x;

    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;

    (*p) += x;

    printf("y = %d\n", y);

    return (0);
}

// O resultado final é 5