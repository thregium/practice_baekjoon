#include <stdio.h>
// 해결 보류

int num[102400];

typedef struct bits {
     int hasnum;
     struct bits* b0;
     struct bits* b1;
} bits;

int main(void) {
     int n, t;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &t);
     }
     printf("%d", n);
     return 0;
}