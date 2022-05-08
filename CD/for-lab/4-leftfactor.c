/*
 * perform left factoring on a single production
 * A->abcDEf|abcRt|abcD
 */
#include <stdio.h>
#include <string.h>

int main() {
  char inp[50];
  puts("Enter production:");
  gets(inp);
  int np=0;
  for(int i=0; i<strlen(inp); i++)
    np=np+(inp[i]=='|');
  int id=1;
  int arr[np+1];
  arr[0]=3;
  for(int i=0; i<strlen(inp); i++) {
    if(inp[i] == '|') {
      arr[id] = i+1;
      id++;
    }
  }
  puts("");
  printf("%c->", inp[0]);
  int off = 0;
  while (1) {
    char m = inp[arr[0]+off];
    int all = 1;

    for(int i = 0; i < np+1; i++) {
      if(m != inp[arr[i] + off]){
        all = 0;
        break;
      }
    }
    if(!all) break;
    putchar(m);
    off++;
  }
  printf("%c'\n", inp[0]);
  printf("%c'->",inp[0]);
  for(int i=0; i<np+1; i++) {
    // printf("%i: %c", arr[i]+off, inp[arr[i]]+off);
    int tmp = off;
    while(inp[arr[i]+tmp] != '|' && inp[arr[i]+tmp]) {
      putchar(inp[arr[i]+tmp]);
      tmp += 1;
    }
    if(i != np) putchar('|');
  }
  puts("");
}