/*
 * Extremely cheesy three adress code generator
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char inp[50];
  puts("Enter expression:");
  gets(inp);
  char in = 'Z';
  for(int i=0; i<strlen(inp); i++) {
    // if(inp[i] == '*' || inp[i] == '/'){
    //   printf("%c := %c%c%c\n",in, inp[i-1], inp[i], inp[i+1]);
    //   in -= 1;
    // } else 
    if (inp[i] == '+' || inp[i] == '-') {
      int hn = 0;
      if(inp[i+2] == '*' || inp[i+2] == '/') {
        printf("%c := %c%c%c\n",in, inp[i+1], inp[i+2], inp[i+3]);
        in -= 1;
        hn=1;
      }
      char next = hn ? in+1 : inp[i+1];  
      char prev = inp[i-2] == '=' ? inp[i-1] : in+hn*2;
      printf("%c := %c%c%c\n",in, prev, inp[i], next);
      in -= 1;
    }
  }
  printf("%c := %c\n", inp[0], in+1);
}