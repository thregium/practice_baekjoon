#include <stdio.h>

/*
���� : N���� ī�带 ������������ ��ġ�ϰ� �� ���� ī��� ������ �� ���� ī��� �� �ڷ� ������ �ൿ�� ��� �ݺ��� �� ���������� ���� ī��� �������� ���Ѵ�.

�ذ� ��� : ť�� �̿��� ī�带 ������ �Ͱ� �� �ڷ� ������ ���� �����Ѵ�.

�ֿ� �˰��� : �ڷᱸ��, ť
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