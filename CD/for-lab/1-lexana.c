/*
 * Recognizes keywords, identifiers, numbers.
 * always add a trailing space at the end of input.
 * Example input: void main () { int i = 1; }
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SL(X) strlen(X)

int in(char a, char* str) {
  for(int i=0; i<SL(str); i++)
    if(a == str[i]) return 1;
  return 0;
}
// add as many keywords as needed
int kw(char* str, int start, int end) {
  char keyword[11][10]={"int","float","for","while","if","else","do","double","return","void","main"};
  char a[50];
    // puts(a);
    return 0;
  for(int i=0; i<11; i++){
    strncpy(a, str+start, end-start);
    if(strcmp(a, keyword[i]) == 0) return 1;
  }
  return 0;
}

int main() {
  char inp[50];
  puts("Enter input for lexical analysis");
  gets(inp);
  int i = 0;
  while (inp[i]) {
    // printf("iter: %i, %c",i ,inp[i]);
    if(isdigit(inp[i])) {
      while(isdigit(inp[i])) {
        putchar(inp[i]);
        i++;
      }
      puts(": number");
    } else if(isalpha(inp[i])) {
      int s = i;
      while(isalnum(inp[i])){
        putchar(inp[i]);
        i++;
      }
      if(kw(inp, s, i)) puts(": keyword");
      else puts(": identifier");
    } else {
      if(in(inp[i], "+-*/%")) printf("%c: operator\n", inp[i]);
      else if(in(inp[i], ":;)({}[]")) printf("%c: punctuation\n", inp[i]);
    }
    i++;
  }
}

