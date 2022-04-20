// Predictive parsing.

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int find(char *str, char ch) {
  for (int i = 0; i < strlen(str); i++)
    if (str[i] == ch)
      return i;
}

void first(char n, char g[][32], int l, char *nt, int *list) {
  if (!isupper(n)) {
    list[find(nt, n)] = 1;
    return;
  }
  for (int i = 0; i < l; i++) {
    if (g[i][0] == n) {
      if (isupper(g[i][3])) {
        first(g[i][3], g, l, nt, list);
      } else {
        list[find(nt, g[i][3])] = 1;
      }
    }
  }
}

void disp(char nt, char* t, int* b, int n, char* prod) {
  for (int i = 0; i < n; i++) {
    if(b[i]) printf("M[%c, %c] -> %s", nt, t[i], prod);
  }
}

void first_fp(int idx, char g[][32], int l, char* nt, int* list) {
    first(g[idx][3], g, l, nt, list);
}

void follow(char n, char g[][32], int l, char *nt, int *list) {
  for (int i = 0; i < l; i++) {
    int ind;
    for (int j = 2; j < strlen(g[i]); j++) {
      if (g[i][j] == n) {
        if (isupper(g[i][j + 1])) {
          first(g[i][j + 1], g, l, nt, list);
        } else if (g[i][j + 1] != '\0') {
          list[find(nt, g[i][j + 1])] = 1;
        } else {
          follow(g[i][0], g, l, nt, list);
        }
      }
    }
  }
}

int main() {
  int n;
  puts("Enter length");
  scanf("%i", &n);
  puts("Enter productions");
  char prods[n][32];
  for (int i = 0; i < n; i++) {
    scanf("%s", prods[i]);
  }
  char nt[50];
  puts("Enter terminals");
  scanf("%s", nt);

  for (int i = 0; i < n; i++) {
    int lst[50] = {0};
    first_fp(0, prods, n, nt, lst);

  }
}