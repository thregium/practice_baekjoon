#include <stdio.h>

/*
문제 : 문서들의 우선순위와 찾을 문서가 주어진다. 큐의 맨 앞에 있는 문서가 가장 우선순위가 높은 문서라면 큐에서 꺼내고 아니라면 맨 뒤로 보낼 때,
찾을 문서는 몇 번째로 꺼내지게 되는지 구한다.

해결 방법 : 큐를 이용해 문제에 써진대로 구현한다.

주요 알고리즘 : 구현, 큐
*/

int p[16];
int q[65536];
int front = 0, rear = 0;

int main(void) {
     int t, n, m, r, o;
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          for (int j = 0; j < 10; j++) p[j] = 0;

          scanf("%d %d", &n, &m);
          for (int j = 0; j < n; j++) {
               scanf("%d", &q[j]);
               p[q[j]]++;
          }
          front = 0;
          rear = n;
          o = 1;
          while (1) {
               r = 0;
               for (int j = q[front] + 1; j < 10; j++) {
                    if (p[j]) {
                         r = 1;
                         break;
                    }
               }

               if (r) {
                    q[rear] = q[front];
                    if (m == front) m = rear;
                    front++;
                    rear++;
               }
               else {
                    if (m == front) {
                         break;
                    }
                    p[q[front]]--;
                    front++;
                    o++;
               }
          }

          printf("%d\n", o);
     }
     return 0;
}