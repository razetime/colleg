#include <stdio.h>
#include <ctype.h>
#include <string.h>

int find(char* str, char ch){
    for(int i=0; i<strlen(str); i++) {
        if(str[i] == ch) return i;
    }
}

void leading(char sym, char prods[][50], int pn, char* nt, int* L) {
    int ntn=strlen(nt);
    for(int i=0; i<2; i++){
        printf("%i ", L[i]);
    }
    puts("");
    for(int i=0; i<pn; i++) {
        if(sym == prods[i][0]){
            char c = prods[i][3];
            if(isupper(c)){
                leading(c,prods,pn,nt,L);
                if(!isupper(prods[i][4])) {
                    printf("doing thing for: %c %i\n", prods[i][4], find(nt, prods[i][4]));
                    L[find(nt, prods[i][4])] = 1;
                }
            } else {
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
    
    puts("enter symbol");
    char s;
    scanf(" %c", &s);
    leading(s, prods, n, nt,  L);
    printf("Leading(%c) -> ", s);
    for(int i=0; i<strlen(t); i++) {
        if(L[i]) putchar(t[i]);
    }
    puts("");
}
