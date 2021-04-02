#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[1048576];

int main(void) {
     int m = 0;
     int a[32] = { 0, };
     scanf("%s", s);
     for (int i = 0; i < strlen(s); i++) {
          if (isupper(s[i])) {
               a[s[i] - 'A']++;
          }
          else if (islower(s[i])) {
               a[s[i] - 'a']++;
          }
     }
     for (int i = 0; i < 26; i++) {
          if (a[i] > a[m]) m = i;
     }
     for (int i = 0; i < 26; i++) {
          if (m != i && a[i] == a[m]) {
               printf("?");
               return 0;
          }
     }
     printf("%c", m + 'A');
     return 0;
}