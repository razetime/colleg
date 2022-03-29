#include <stdio.h>
#include <string.h>

void first(char n, char g[][32], int l) {
    for(int i=0; i<l; i++) {
        if(g[i][0] == n) {
            if(g[i][2] <= 'Z' && g[i][2] >= 'A') {
                first(g[i][2], g, l);
            } else {
                printf("%c  ", g[i][2]);
            }
        }
    }
}

void follow(char n, char g[][32], int l) {
    for(int i=0; i<l; i++) {
        int ind;
        for(int j=2; j<strlen(g[i]); j++) {
            if(g[i][j] == n) {
                if(g[i][j+1] <= 'Z' && g[i][j+1] >= 'A') {
                    first(g[i][j+1], g, l);
                } else if(g[i][j+1] != '\0') {
                    printf("%c ",g[i][j+1]);
                } else {
                    follow(g[i][0], g, l);
                }
            }
        }
    }
}

int main() {
    int n;
    puts("No. of productions: ");
    scanf("%i", &n);
    puts("Enter productions(max size: 32): ");
    char g[2][32] = {
        "A=n",
        "B=AxC"
    };
    
/*    for(int i=0; i<n; i++) {
        scanf("%s",g[i]);
    }
*/    puts("Enter symbol:");
    char fc;
    scanf(" %c",&fc);
    puts("First:");
    first(fc, g, n);
    puts("\nFollow:");
    follow(fc,g,n);
    puts("");
    return 0;
}
