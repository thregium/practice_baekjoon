#include <stdio.h>
#include <stdlib.h>

/*
���� : 3 * N(N <= 300)���� ���� �־��� ��, ���� ��ġ�� �ʴ� �ﰢ�� N���� ����� ����� ����Ѵ�.
��, 3���� ���� �������� �ִ� ���� �־����� �ʴ´�.

�ذ� ��� : �� ������ �������� �ִ� 2���� ���� �� �ֱ� ������ X���� �������� �����ϸ� ���� X�࿡��
���� 2�������� �ְ�, 3���� ��� �ﰢ���� ���� �� �ִ�. X�� -> Y�� ������ �����ϸ� ���� ��ġ�� �ʵ��� ��������� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ������, ������

��ó : kriii 1ȸ D��
*/

int point[1024][3];

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
    for (int i = 0; i < n * 3; i++) {
        scanf("%d %d", &point[i][0], &point[i][1]);
        point[i][2] = i + 1;
    }
    qsort(point, n * 3, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", point[i * 3][2], point[i * 3 + 1][2], point[i * 3 + 2][2]);
    }
    return 0;
}