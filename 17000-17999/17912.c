#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 100000)���� ���� �ƴ� ����(<= 10^9)�� �־��� ��, ���� ���� ���� �� ���� ���� ��ġ�� ���Ѵ�.

�ذ� ��� : �ּڰ��� ���ϸ鼭 �ּڰ��� �ٲ� �� ���� ��ġ�� �����ص� ����, ����� ��ġ�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : Bergen 2018 L��
*/

int main(void) {
    int n, x, day = -1, best = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x < best) {
            best = x;
            day = i;
        }
    }
    if (day < 0) return 1;
    printf("%d", day);
    return 0;
}