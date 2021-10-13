#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ���� ���׸� �� ����� �־��� ��, �� ���� ������ ���Ѵ�. �����/���ڽ� ���� ������� �ʰ�
���������� ������ ���Ѵ�. ������ ������ ���� ������ �ű��, ���� ������ �������� ����ŭ �и���.

�ذ� ��� : ���� ��⸦ ���� Ȯ���ϸ� �̱� ������ ���� 3���� �߰��ϰ�, ��� ��� ���� 1������ �� ���� �߰��Ѵ�.
�� ����, ���� ������ ������ �����ϰ�, ������ ���� �ű� ����, �ٽ� �� ��ȣ ������� �����ؼ�
�� ���� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : JOI 2012�� 2��
*/

int wp[128][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, a, b, c, d;
    scanf("%d", &n);
    for (int i = 0; i < (n * (n - 1)) >> 1; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (c > d) wp[a][0] += 3;
        else if (c < d) wp[b][0] += 3;
        else {
            wp[a][0]++;
            wp[b][0]++;
        }
    }
    for (int i = 1; i <= n; i++) wp[i][1] = i;
    qsort(wp + 1, n, sizeof(int) * 3, cmp1);
    wp[1][2] = 1;
    for (int i = 1; i <= n; i++) {
        if (wp[i][0] == wp[i - 1][0]) wp[i][2] = wp[i - 1][2];
        else wp[i][2] = i;
    }
    qsort(wp + 1, n, sizeof(int) * 3, cmp2);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", wp[i][2]);
    }
    return 0;
}