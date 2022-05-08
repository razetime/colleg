/*
 *  Shrujan's program
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char stack[50];
int top = -1;
void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }
int prec(char x) {
    switch(x) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
    }
    return 0;
}
void infix_to_postfix(char s[]) {
    int len = strlen(s) , i , j = -1;
    char output[50];
    for (i=0; i<len; i++) {
        if (isalpha(s[i])) {
            output[++j] = s[i];
        }
        else if (s[i] == '(') {
            push(s[i]);
        }
        else if (s[i] == ')') { // handle parens
            while (stack[top] != '(') {
                output[++j] = pop();
            }
            pop();
        }
        else {
            while (prec(s[i]) <= prec(stack[top]) && top != -1) {
                output[++j] = pop();
            }
            push(s[i]);
        }
    }
    while(top != -1) {
        output[++j] = pop();
    }
    printf("\n postfix expression:\n %s" , output);
}
int main() {
    char s[50];
    printf("\n Enter an infix expression:\n ");
    scanf("%s" , s);
    infix_to_postfix(s);
    return 0;
}