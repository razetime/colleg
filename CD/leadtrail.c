#include <stdio.h>
#include <ctype.h>
#include <string.h>

int find(char* str, char ch){
    for(int i=0; i<strlen(str); i++) {
        if(str[i] == ch) return i;
    }
}

void pa(int arr[], int n) {
    puts("");
    for(int i=0; i<n; i++) {
        printf("%i ", arr[i]);
    }
    puts("");
}

void leading(char sym, char prods[][50], int pn, char* nt, int* L) {
    int ntn=strlen(nt);
    //printf("%i %c\n", pn, sym);
    for(int i=0; i<pn; i++) {
        if(sym == prods[i][0]){
            //puts("MAtched");
            char c = prods[i][3];
            if(isupper(c)){
                if(c != prods[i][0]) leading(c,prods,pn,nt,L);
                //pa(L, 50);
                if(!isupper(prods[i][4])) {
                    //printf("doing thing for: %s %c %i\n", nt, prods[i][4], find(nt, prods[i][4]));
                    L[find(nt, prods[i][4])] = 1;
                    //pa(L, 50);
                }
                //printf("Printing");
               // pa(L, 50);
            } else {
                L[find(nt, c)] = 1;
            }
        }
    }
}

void trailing(char sym, char prods[][50], int pn, char* nt, int* L) {
    int ntn=strlen(nt);
    for(int i=0; i<pn; i++) {
        if(sym == prods[i][0]){
            int l = strlen(prods[i])-1;
            char c = prods[i][l];
            if(isupper(c)){
                if(c != prods[i][0]) trailing(c,prods,pn,nt,L);
                if(!isupper(prods[i][l-1])) {
                    //printf("\ndoin your mom %c", prods[i][l-1]);
                    L[find(nt, prods[i][l-1])] = 1;
                    //pa(L, 50);
                }
            } else {
                //printf("\ndoin your mom %c", c);
                L[find(nt, c)] = 1;
            }
        }
    }
}


int main() {
    int n;
    puts("Enter no of productions");
    scanf("%i",&n);
    char prods[n][50];
    for(int i=0; i<n; i++){
        scanf("%s", prods[i]);
    }
    puts("Enter terminals and nterminals");
    char t[50];
    char nt[50];
    scanf("%s", t);
    scanf(" %s", nt);

    
    int L[50];
    for(int i=0; i<50; i++) L[i]=0;
    puts("enter symbol");
    char s;
    scanf(" %c", &s);
    //printf("Char: %c\n", s);
    leading(s, prods, n, t,  L);
    printf("Leading(%c) -> ", s);
    for(int i=0; i<strlen(t); i++) {
        if(L[i]) putchar(t[i]);
    }

    int TL[50];
    for(int i=0; i<50; i++) TL[i]=0;
    trailing(s, prods, n, t,  TL);
    printf("\nTrailing(%c) -> ", s);
    for(int i=0; i<strlen(t); i++) {
        if(TL[i]) putchar(t[i]);
    }
    puts("");
}
