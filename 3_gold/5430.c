#include <stdio.h>
#include <string.h>

/*
문제 : 수열 x가 주어질 때 연산 D는 수열의 첫 번째 원소를 버리고, R은 수열을 뒤집는다고 한다. 이때 연산의 결과를 출력한다.

해결 방법 : 수열의 맨 앞과 맨 뒤의 위치를 확인하고 R이 들어올 때 마다 방향을 바꾼다. D가 들어오면 현재 방향에서 맨 앞의 원소를 버리고, 현재 방향의 위치를 1 증가시킨다.
연산 결과는 배열의 남은 수를 방향에 맞춰 출력하면 된다.

주요 알고리즘 : 자료구조, 덱?
*/

char p[102400];
int x[102400];

int main(void) {
     int t, n, c, front, rear, dir, error;
     scanf("%d", &t);
     for (int tt = 0; tt < t; tt++) {
          scanf("%s", p);
          scanf("%d\n[", &n);
          for (int i = 0; i < n - 1; i++) {
               scanf("%d,", &x[i]);
          }
          if (n) scanf("%d]", &x[n - 1]);
          else scanf("]");
          front = 0;
          rear = n;
          dir = 0;
          error = 0;
          c = 0;

          for (int i = 0; i < strlen(p); i++) {
               if (p[i] == 'R') dir = !dir;
               if (p[i] == 'D') {
                    if (front == rear) {
                         error = 1;
                         break;
                    }
                    if (dir) {
                         rear--;
                    }
                    else {
                         front++;
                    }
               }
          }

          if (error) {
               printf("error\n");
               continue;
          }
          else {
               printf("[");
               if (dir) {
                    for (int i = rear - 1; i >= front + 1; i--) {
                         printf("%d,", x[i]);
                    }
                    if (front != rear) printf("%d]\n", x[front]);
                    else printf("]\n");
               }
               else {
                    for (int i = front; i < rear - 1; i++) {
                         printf("%d,", x[i]);
                    }
                    if (front != rear) printf("%d]\n", x[rear - 1]);
                    else printf("]\n");
               }
          }
     }
     return 0;
}