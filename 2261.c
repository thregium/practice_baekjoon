#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
set는 AVL 트리로 구현..?
*/

typedef struct ctree {
     int x;
     int y;
     struct ctree* left;
     struct ctree* right;
} ctree;

int dots[102400][2];
int n;
long long int dist;

long long int sqr(int a) { return (long long)a * a; }

long long int get_dist(int x1, int y1, int x2, int y2) {
     return sqr((long long)x1 - x2, 2) + sqr((long long)y1 - y2, 2);
}

int seek_last(int m) {
     int d = sqrt(dist) + dots[m][0];
     int l = m, h = n - 1;
     int z = m;
     if (d > dots[h][0] - dots[m][0]) return n - 1;
     while (1) {
          if (l == h || l + 1 == h) {
               z = l;
               break;
          }
          if (dots[(l + h) / 2][0] < d) {
               l = (l + h) / 2;
          }
          else if (dots[(l + h) / 2][0] > d) {
               h = (l + h) / 2;
          }
          else {
               z = (l + h) / 2;
               break;
          }
     }
     while (dots[z + 1] < d + 1) z++;
     return z;
}

void qs_cmp(void* a, void* b) {
     int x1, x2, y1, y2;
     x1 = *(int*)a;
     x2 = *(int*)b;
     y1 = *((int*)a + 1);
     y2 = *((int*)b + 1);

     if (x1 > x2) return 1;
     else if (x1 < x2) return -1;
     else if (y1 > y2) return 1;
     else if (y1 < y2) return -1;
     else return 0;
}

void shortest_dist(int n) {
     int mx;
     dist = get_dist(dots[0][0], dots[0][1], dots[1][0], dots[1][1]);
     for (int i = 2; i < n; i++) {
          mx = seek_last(i);
          for (int j = i + 1; j <= mx; j++) {
               if (get_dist(dots[i][0], dots[i][1], dots[j][0], dots[j][1]) < dist) dist = get_dist(dots[i][0], dots[i][1], dots[j][0], dots[j][1]);
          }
     }
}

int main(void) {
     int res;
     scanf("%d", &n);
     srand(time(NULL));
     for (int i = 0; i < n; i++) {
          //scanf("%d %d", &dots[i][0], &dots[i][1]);
          
          //dots[i][0] = rand() * 64;
          srand(rand() * (11 + 2 * i) + 23);
          dots[i][0] += rand();
          srand(rand() * (13 + 3 * i) + 29);
          //dots[i][1] = rand() * 64;
          srand(rand() * (17 + 5 * i) + 31);
          dots[i][1] += rand();
          srand(rand() * (19 + 7 * i) + 37);
          
     }
     qsort(dots, n, sizeof(int) * 2, qs_cmp);
     shortest_dist(n);
     printf("%lld", dist);
     //printf("done");
     return 0;
}