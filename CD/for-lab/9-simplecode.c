/*
 * Simple code generator
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  puts("Enter number of statements");
  scanf("%i", &n);
  char stmts[n][32];
  puts("Enter prods:");
  for(int i=0; i<n; i++){
    scanf("%s", stmts[i]);
  }
  int reg=0;
  for(int i=0; i<n; i++) {
    char op[4];
    switch(stmts[i][3]) {
      case '+': strcpy(op, "ADD"); break;
      case '-': strcpy(op, "SUB"); break;
      case '*': strcpy(op, "MUL"); break;
      case '/': strcpy(op, "DIV"); break;
      default: printf("Unknown op: %c\n", stmts[i][3]);exit(0);
    }
    printf("MOV %c R%i\n", stmts[i][2], reg);
    printf("%s %c R%i\n", op, stmts[i][4], reg);
    printf("MOV R%i %c\n", reg, stmts[i][0]);
    reg++;
  }
}