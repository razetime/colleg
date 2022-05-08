/* 
 * eliminate left recursion for single production
 * Example input: E->E+T|T
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char inp[50];
  puts("Enter production:");
  gets(inp);
  char f = inp[0];
  if(f != inp[3]){
    puts("No left recursion");
    exit(0);
  }
  int j=0;
  while (inp[j] != '|') j++;
  printf("%c->", f);
  for(int i=j+1; i < strlen(inp); i++)
    putchar(inp[i]);
  printf("%c'\n", f);
  printf("%c'->", f);
  for(int i = 4; i < j; i++)
    putchar(inp[i]);
  printf("%c'|e\n", f);

}