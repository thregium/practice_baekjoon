#include <stdio.h>
#include <stdlib.h>

/*
���� : B(B <= 10^9)�� �������� N(N <= 1000)���� ���� ��� �ִ��� ���� ���� ����� �Ѵ�. �� ������ 10^9 ������ ������
���ݰ� ��ۺ� ���´�. ������ 1�� �ְ�, ������ ����ؼ� ����(��ۺ� ������)�� �������� ���ι��� �� �ִٸ�
�� �� �ִ� ������ ������ ���Ѵ�.

�ذ� ��� : ��� ������ ����� ���� �ʿ��� ������ �����Ѵ�. �� ����, ��� ������ ���� ������ �ѹ��� ����غ���.
���� ������ ����� ������ B���� ũ�ٸ� �ٷ� �Ѿ�� �ƴϸ� �ٸ� �������� �� �� ���� ���.
�� �� �������� �������� �� ������ ����ϰ� �׵� ��� ���� ū ���� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����, ���Ʈ ����

��ó : USACO 2012J B1��
*/

int present[1024][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a + *((int*)a + 1);
    int bi = *(int*)b + *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, b, c, r = 0;
    long long d;
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &present[i][0], &present[i][1]);
    }
    qsort(present, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        d = (present[i][0] >> 1) + present[i][1];
        if (d > b) continue;
        c = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            d += present[j][0] + present[j][1];
            if (d > b) break;
            c++;
        }
        if (c > r) r = c;
    }
    printf("%d", r);
    return 0;
}