#include <stdio.h>

/*
문제 : N개의 카드를 오름차순으로 배치하고 맨 앞의 카드는 버리고 그 다음 카드는 맨 뒤로 보내는 행동을 계속 반복할 때 마지막으로 남는 카드는 무엇인지 구한다.

해결 방법 : 큐를 이용해 카드를 버리는 것과 맨 뒤로 보내는 것을 구현한다.

주요 알고리즘 : 자료구조, 큐
*/

int q[1048576];
int front = 0, rear = 0;

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) q[i] = i + 1;
     rear = n;
     while (rear > front + 1) {
          front++;
          q[rear] = q[front];
          rear++;
          front++;
     }
     printf("%d", q[front]);
     return 0;
}