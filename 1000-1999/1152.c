#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[1048576];

int main(void) {
     int sen = 0, is = 0;
     fgets(s, 1024000, stdin);
     if (!isspace(s[0])) is = 1;
     for (int i = 0; i < strlen(s); i++) {
          if (isspace(s[i]) && is) {
               is = 0;
               sen++;
          }
          if (!isspace(s[i]) && !is) {
               is = 1;
          }
     }
     if (is) sen++;
     printf("%d", sen);
     return 0;
}