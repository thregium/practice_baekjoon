#include <stdio.h>

/*
문제 : 요세푸스 수열은 N개의 원소들이 순서대로 있을 때 K번째 수를 계속해서 빼냈을 때의 수열이다. N과 K가 주어질 때 요세푸스 수열을 구한다.

해결 방법 : 큐를 이용해 K번째가 아닌 경우 큐의 맨 앞 원소를 맨 뒤로 보내고 K번째인 경우 큐에서 빼낸 다음 저장하는 것을 반복하여 구한다.

주요 알고리즘 : 자료구조, 큐
*/

int q[1048576], r[1024];
int front = 0, rear = 0, ri = 0;

int main(void) {
     int n, k;
     scanf("%d %d", &n, &k);
     for (int i = 0; i < n; i++) q[i] = i + 1;
     rear = n;
     while (rear > front) {
          for (int i = 0; i < k - 1; i++) {
               q[rear] = q[front];
               rear++;
               front++;
          }
          r[ri] = q[front];
          front++;
          ri++;
     }
     printf("<");
     for(int i = 0; i < n - 1; i++) printf("%d, ", r[i]);
     printf("%d>", r[n - 1]);
     return 0;
}