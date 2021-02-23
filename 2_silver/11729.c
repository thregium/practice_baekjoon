#include <stdio.h>

int move[1048576][2];
int mp = 0;

int hanoi(int n, int a, int b) {
     if (n == 1) {
          move[mp][0] = a;
          move[mp][1] = b;
          mp++;
          return 1;
     }
     int x = hanoi(n - 1, a, 6 - (a + b));
     move[mp][0] = a;
     move[mp][1] = b;
     mp++;
     int y = hanoi(n - 1, 6 - (a + b), b);
     return  x + y + 1;
}

int main(void) {
     int k, m;
     scanf("%d", &k);
     m = hanoi(k, 1, 3);
     printf("%d\n", m);
     for (int i = 0; i < mp; i++) printf("%d %d\n", move[i][0], move[i][1]);
     return 0;
}