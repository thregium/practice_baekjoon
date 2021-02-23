#include <stdio.h>

/*
���� : ���� A�� *2�� �ϰų� ���� �ڿ� 1�� �߰��ϴ� �ൿ�� �Ͽ� B�� ���� �� �ִ� �ּ����� �ൿ ���� ���Ѵ�.

�ذ� ��� : �ʺ� �켱 Ž���� ���� �ּ����� �ൿ ���� ���Ѵ�. x * 2�� x * 10 + 1�� ���� ť�� �ְ�, ť���� ������� ������ ����� ���� �ʺ� �켱 Ž���� �����Ѵ�.
�̶� ť�� �ൿ ���� ���� ����ְ�, x�� b�� ���� ��� Ž���� �����ϰ� �׶��� �ൿ ���� ����Ѵ�. x�� b���� ū ���� ť���� �ٸ� ���� ���� �ٽ� Ž���Ѵ�.

�ֿ� �˰��� : �׷���, �ʺ� �켱 Ž��
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