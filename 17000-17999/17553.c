#include <stdio.h>
#include <stdlib.h>
#define CON 186947453825714673 //����� ū �ڿ��� �� �ƹ��ų� �ϳ� ���

/*
���� : N(N <= 10000)���� ���� �־��� ��, �� ����� ���� �ٸ� �� ���� ��Ƽ� ��� �� �ʿ� �� ����� ������
��Ȯ�� �ݾ����� ������ ���� ��ġ�� ���Ѵ�. ��, N�� Ȧ���� ��� �� ���� ���� ���ʿ��� ��Ȯ�� ���� �Ÿ���ŭ �������� �Ѵ�.
�� ���� ��ǥ�� ������ 10^9 ������ �����̰�, ����� ��ǥ�� ������ 10^18 ������ �������� �Ѵ�.

�ذ� ��� : X��ǥ -> Y��ǥ ������ ������ ���� ��Ȯ�� ��� ����(¦���� ��� ��� 2�� �� ���� ��ġ)�� �ִ� ���� �̴´�.
Ȧ���� ��� �̸� ����ϸ� \���⿡�� �ִ��� ���������� ���� ���°� �Ǹ� ��Ȯ�� �������� ���� �� �ִ�. �̸� ��ǥ�� ǥ���ϸ�
�ش� ���� ��ǥ�� (x, y), C�� �ſ� ū ����(10^9�� �Ѵ�)�� ���� �� (x - C, y - 1)�� (x + C, y + 1)�� �Ǹ� �ȴ�.
¦���� ��쿡�� �ش� ��ġ���� �ſ� �ణ�� �Ʒ��� �������� �ϴµ�, (x - C, y - 1)�� (x + C, y)�� ����θ� �ȴ�.

�ֿ� �˰��� : ������, ����

��ó : BAPC 2019P L��
*/

int points[103000][2];

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int bx = *(int*)b;
    if (ax != bx) return ax > bx ? 1 : -1;
    int ay = *((int*)a + 1);
    int by = *((int*)b + 1);
    return ay > by ? 1 : ay == by ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }
    qsort(points, n, sizeof(int) * 2, cmp1);
    if (n & 1) {
        printf("%lld %lld\n", points[n >> 1][0] - CON, points[n >> 1][1] - 1LL);
        printf("%lld %lld", points[n >> 1][0] + CON, points[n >> 1][1] + 1LL);
    }
    else {
        printf("%lld %lld\n", points[n >> 1][0] - CON, points[n >> 1][1] - 1LL);
        printf("%lld %lld", points[n >> 1][0] + CON, (long long)points[n >> 1][1]);
    }
    return 0;
}