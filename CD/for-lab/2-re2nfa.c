/*
 * Thompson's construction
 * Does not support parentheses "()"
 * Example input: a*b+c
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void pp(int i, int j, char c) {
  printf("q%i -> q%i = %c\n", i,j,c);
}

int main() {
  char inp[50];
  puts("Enter regex:");
  gets(inp);
  int sn = 0;
  for(int i=0; i<strlen(inp); i++) {
    switch(inp[i+1]) {
      case '+':
        pp(sn, sn+1, 'E');
        pp(sn+1, sn+2, inp[i]);
        pp(sn, sn+3, 'E');
        pp(sn+3, sn+4, inp[i+2]);
        pp(sn+2, sn+5, 'E');
        pp(sn+4, sn+5, 'E');
        sn += 5;
        i += 2;
        break;
      case '*':
        pp(sn, sn+1, 'E');
        pp(sn+1, sn+2, inp[i]);
        pp(sn+2, sn+1, 'E');
        pp(sn+2, sn+3, 'E');
        pp(sn, sn+3, 'E');
        sn += 3;
        i += 1;
      default:
        pp(sn, sn+1, inp[i]);
        sn += 3;
    }
  }
}
