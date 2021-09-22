#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 20000)������ �ҵ��� Ű�� ���� �־�����. �̶�, B(B <= 2 * 10^9) �̻��� ���̰� �Ǳ� ���� �ʿ���
�Ұ� �ּ� �� �������� ���Ѵ�.

�ذ� ��� : ���� ū �Һ��� ���ʷ� �״� ���� ���� ������ ���� �� �� �ִ�. Ű ������ ������ ���� ���� ū �Һ��� �׾Ƴ����鼭
B �̻��� ���̰� �� ������ ���� ���� �������� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : USACO 2007D B1��
*/

int heights[20480];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, b, s = 0;
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    qsort(heights, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        s += heights[i];
        if (s >= b) {
            printf("%d", i + 1);
            break;
        }
    }
    if (s < b) return 1;
    return 0;
}