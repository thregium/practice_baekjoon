#include <stdio.h>
#include <malloc.h>

/*
���� : �ǹ� w�� ����� �¸��ϴ� ������ �ִٰ� �Ѵ�. �׷��� ��� �ǹ� y�� ���� ���ؼ��� �����ϴ� �ǹ� x�� ��� ����� �Ѵ�.
�ǹ��� ���ÿ� �Ǽ� �����ϰ�, �ǹ��� ���� ���̿� ��ü�Ǵ� �ð��� ���ٰ� �����ϰ�, ������ �ǹ��� ���� �ð��� �Ǽ� ���� ��Ģ�� �־��� �� w�� ���µ� �ɸ��� �ּ� �ð��� ���Ѵ�.

�ذ� ��� : w�� ���µ� �ɸ��� �ð��� w�� ���� �ǹ����� ���µ� �ɸ��� �ð� ��� ���� �� �ð� + w�� ���µ� �ɸ��� �ð��̴�.
�̸� �̿��� w�� ���� �ǹ����� ���� �ǹ��� ���� ������ ���� Ž���� �� �ִ��� ���� w�� ���µ� �ɸ��� �ð��� ���� �� �ִ�.

�ֿ� �˰��� : �׷��� Ž��, ���̳��� ���α׷���
*/

typedef struct building {
     int d;
     int c;
     int prevs;
     int nexts;
     struct building* prev[1024];
     struct building* next[1024];
} building;

building* allb[1024];

int build(building* w) {
     if (w->c >= 0) return w->c;
     int t = 0;
     for (int i = 0; i < w->prevs; i++) {
          if(build(w->prev[i]) > t) t = build(w->prev[i]);
     }
     return w->c = t + w->d;
}

int main(void) {
     int t, n, k, x, y, w;
     scanf("%d", &t);
     for (int tt = 0; tt < t; tt++) {
          for (int i = 0; i < 1024; i++) {
               //if (!tt) {
                    building* bt;
                    bt = calloc(1, sizeof(building));
                    allb[i] = bt;
               //}
               allb[i]->c = -1;
          }
          scanf("%d %d", &n, &k);
          for (int i = 1; i <= n; i++) {
               scanf("%d", &allb[i]->d);
          }
          for (int i = 1; i <= k; i++) {
               int a, b;
               scanf("%d %d", &x, &y);

               allb[x]->next[allb[x]->nexts] = allb[y];
               allb[x]->nexts++;
               allb[y]->prev[allb[y]->prevs] = allb[x];
               allb[y]->prevs++;
          }
          scanf("%d", &w);
          printf("%d\n", build(allb[w]));
          for (int i = 0; i < 1024; i++) free(allb[i]);
     }
     //for (int i = 0; i < 1024; i++) free(allb[i]);
     return 0;
}