#include <stdio.h>

/*
문제 : 숫자 A를 *2를 하거나 숫자 뒤에 1을 추가하는 행동을 하여 B로 만들 수 있는 최소한의 행동 수를 구한다.

해결 방법 : 너비 우선 탐색을 통해 최소한의 행동 수를 구한다. x * 2와 x * 10 + 1을 각각 큐에 넣고, 큐에서 순서대로 꺼내는 방식을 통해 너비 우선 탐색을 구현한다.
이때 큐에 행동 수도 같이 집어넣고, x와 b가 같은 경우 탐색을 종료하고 그때의 행동 수를 출력한다. x가 b보다 큰 경우는 큐에서 다른 수를 꺼내 다시 탐색한다.

주요 알고리즘 : 그래프, 너비 우선 탐색
*/

typedef struct queue {
     long long int q[131072];
     char y[131072];
     int front;
     int rear;
} queue;

queue q;

int main(void) {
     int a, b, y = 0;
     long long int x;
     q.front = 0;
     q.rear = 0;
     scanf("%d %d", &a, &b);
     x = a;
     while (1) {
          if (x == b) {
               break;
          }
          if (x > b) {
               if (q.rear - q.front) {
                    x = q.q[q.front];
                    y = q.y[q.front];
                    q.front++;
               }
               else {
                    y = -2;
                    break;
               }
               continue;
          }
          q.q[q.rear] = x * 2;
          q.y[q.rear] = y + 1;
          q.rear++;
          x = x * 10 + 1;
          y++;
     }
     printf("%d %d", y + 1, q.rear);
     return 0;
}