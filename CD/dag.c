#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define ia(X) isalpha(X)

int opno = 0;
int in(char ch, char* str) { 
  while(*str) 
    if(*str == ch) return 1;
  return 0;
}

int main() {
  puts("Enter expression:");
  char expr[50];
  scanf("%s", expr);

  char used[50] = "";
  
  printf("Index\tNode value\tLeft\tRight\n");
  for(int i = 0; i <  strlen(expr);  i++) {
    if(ia(expr[i]) && !in(expr[i], used)){
      printf("%i\t%c\tNULL\tNULL\n", expr[i], expr[i]);
    } else if(!ia(expr[i])) {
      int l = expr[i-1] == ')' ? expr[i-3] : expr[i-1];
      int r = expr[i+1] == '(' ? expr[i+3] : expr[i+1];
      printf("%i\t%c\t%i\t%i\n", opno, expr[i], l, r);
      opno++;
    }
  }

}