#include <stdio.h>
#include <stdlib.h>

int main() {
  int stack[100];
  int i=-1;
  do {
    puts("Enter choice:");
    puts("1. Push");
    puts("2. Pop");
    puts("3. Display");
    puts("4. Peek");
    puts("5. Exit");
    int ch;
    scanf("%i", &ch);
    switch(ch) {
      case 1: scanf("%i",&stack[++i]); break;
      case 2: if(i>=0) printf("Popped %i\n",stack[i--]); else puts("Underflow");
        break;
      case 3: printf("Full Stack: "); for(int j=0; j<=i;j++) printf("%i ", stack[j]); puts(""); break;
      case 4: if(i>=0) printf("Top: %i\n", stack[i]); else puts("Enpty stack"); break;
      case 5: exit(0); 
      default: puts("Invalid option");
    }
  } while (1);
}