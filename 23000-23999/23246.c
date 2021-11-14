#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� Ŭ���̹� �������� ����, ���ǵ�, ������ ������ �־��� �� ��, ��, ���޴��� �޴� ������ ����Ѵ�.
���� ���� ���� �� -> ���� ���� ���� �� -> �� ��ȣ�� ���� ������ ������ ��������.

�ذ� ��� : ������ �־��� ���Ǵ�� �����Ѵ�.

�ֿ� �˰��� : ����, ����

��ó : Seoul 2021I I��
*/

int player[128][4];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int ax = *((int*)a + 1);
    int bx = *((int*)b + 1);
    int ay = *((int*)a + 2);
    int by = *((int*)b + 2);
    int az = *((int*)a + 3);
    int bz = *((int*)b + 3);
    if (ax * ay * az != bx * by * bz) return ax * ay * az > bx * by * bz ? 1 : -1;
    if (ax + ay + az != bx + by + bz) return ax + ay + az > bx + by + bz ? 1 : -1;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &player[i][0], &player[i][1], &player[i][2], &player[i][3]);
    }
    qsort(player, n, sizeof(int) * 4, cmp1);
    for (int i = 0; i < 3; i++) {
        printf("%d ", player[i][0]);
    }
    return 0;
}