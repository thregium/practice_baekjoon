#include <stdio.h>
#include <stdlib.h>

/*
���� : ���ﰢ�� ����� ���� �ﰢ����� ������ ������� ��ȣ�� �ٿ���.
A��° �ﰢ������ B(A, B <= 10^9)��° �ﰢ������ ���� �ִܰŸ��� ���Ѵ�.

�ذ� ��� : �� ������ ��ġ�� Ư���� ����, ��츦 ������ �ذ��Ѵ�.

�ֿ� �˰��� : ����, ���̽� ��ũ
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int a, b, ax = 0, ay = 0, bx = 0, by = 0, res;
    scanf("%d %d", &a, &b);
    if (a > b) swap(&a, &b);
    for (int i = 1;; i++) {
        if (i * i >= a) {
            ax = i - 1;
            ay = a - (i - 1) * (i - 1) - ax - 1;
            break;
        }
    }
    for (int i = 1;; i++) {
        if (i * i >= b) {
            bx = i - 1;
            by = b - (i - 1) * (i - 1) - bx - 1;
            break;
        }
    }

    res = bx - ax;
    if ((ax + ay) & 1) ax--;
    if (abs(ay - by) > bx - ax) res += abs(ay - by);
    else res += bx - ax - ((bx + by) & 1);
    printf("%d", res);
    return 0;
}