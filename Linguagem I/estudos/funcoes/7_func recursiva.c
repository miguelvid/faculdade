//FATORIAL!

# include <stdio.h>

int fatorial(int x) {

int resut;

if(x == 0) {
    resut = 1;
} 
else {
    resut = x * fatorial(x - 1);
}

return resut;

}

int main() {
    
int numb, res;

scanf("%d", &numb);

res = fatorial(numb);

printf("%d", res);

 
 return 0;

}