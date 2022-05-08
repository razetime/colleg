// taken from record, very easy
#include <stdio.h>
#include <string.h>

struct op {
  char left[10] , right[10];
} op2[15] , prt[15];

int main() {
  int n , i , j;
  char *mat;
  printf("enter no.of.values: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("left:");
    scanf("%s",op2[i].left);
    printf("right:");
    scanf("%s",op2[i].right);
  }
  printf("\nintermediate code\n");
  for(i=0;i<n;i++)
  {
    printf("Lineno=%d\n",i+1);
    printf("%s=%s\n",op2[i].left , op2[i].right);
  } 
  printf("\nDataflow analysis");
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
      mat = strstr(op2[j].right,op2[i].left);
      if(mat)
        printf("\n%s is live at %s",op2[i].left,op2[j].right);
    }
  return 0;
}
