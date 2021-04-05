#include <stdio.h>
#include <string.h>

/*
문제 : 큐에서 몇 개의 원소들을 원하는 순서대로 뽑으려고 한다. 이 때 할 수 있는 행동이 원소 뽑기, 큐 왼쪽이나 오른쪽으로 1칸 회전 뿐일 때
회전을 최소한으로 사용해 원소들을 뽑기 위해 필요한 회전의 수를 구한다.

해결 방법 : 덱을 이용해 원하는 큐 회전을 구현한다. 덱의 맨 뒤에서 원소를 뽑아 맨 앞으로 집어넣으면 왼쪽 회전, 맨 앞에서 뽑아 맨 뒤로 집어넣으면 오른쪽 회전이다.
양쪽 회전 가운데 더 빠르게 원하는 원소를 얻을 수 있는 방향으로 회전을 한다. 양쪽이 같은 경우는 회전 이후 상태가 같으므로 아무거나 뽑아도 상관 없다.

주요 알고리즘 : 자료구조, 덱
*/

int d[2048], p[64];
int front = 1024, rear = 1024;

int main(void) {
     int n, m, x = 0, a = 0, c = 0;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < m; i++) scanf("%d", &p[i]);
     for (int i = 1; i <= n; i++) {
          d[rear] = i;
          rear++;
     }
     
     while (m > a) {
          for (int i = front; i < rear; i++) {
               if (d[i] == p[a]) {
                    x = i - front;
                    break;
               }
          }
          if (x == 0) {
               front++;
               a++;
          }
          else if (x <= (rear - front) / 2) {
              //뒤쪽 회전
               d[rear] = d[front];
               front++;
               rear++;
               c++;
          }
          else {
              //앞쪽 회전
               d[front - 1] = d[rear - 1];
               front--;
               rear--;
               c++;
          }
     }
     printf("%d", c);
     return 0;
}