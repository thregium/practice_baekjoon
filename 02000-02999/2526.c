#include <stdio.h>

/*
���� : N(N <= 1000)���� �����Ͽ� N * N % P(P <= 97) ������ �ݺ��� �� ����� ����Ŭ�� ���̸� ���Ѵ�.

�ذ� ��� : P�� ���� �����Ƿ� ���� ���� ���ؼ� �˾ƺ��� �ȴ�.

�ֿ� �˰��� : ����, ����, �׷��� �̷�

��ó : ���� 2012�� ��2��
*/

int order[1024];

int main(void) {
    int n, p, x;
    scanf("%d %d", &n, &p);
    x = n;
    for (int i = 1;; i++) {
        if (order[x]) {
            printf("%d", i - order[x]);
            return 0;
        }
        order[x] = i;
        x = (x * n) % p;
    }
    return 0;
}