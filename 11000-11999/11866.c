#include <stdio.h>

/*
���� : �似Ǫ�� ������ N���� ���ҵ��� ������� ���� �� K��° ���� ����ؼ� ������ ���� �����̴�. N�� K�� �־��� �� �似Ǫ�� ������ ���Ѵ�.

�ذ� ��� : ť�� �̿��� K��°�� �ƴ� ��� ť�� �� �� ���Ҹ� �� �ڷ� ������ K��°�� ��� ť���� ���� ���� �����ϴ� ���� �ݺ��Ͽ� ���Ѵ�.

�ֿ� �˰��� : �ڷᱸ��, ť
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