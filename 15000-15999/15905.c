#include <stdio.h>
#include <stdlib.h>

/*
���� : N(5 <= N <= 66) ���� Ǭ ���� ���� ���Ƽ�� �־��� ��, 6�� ������ �ο� ��� 5���� Ǭ ���� ���� ���� ��� ���� ���Ѵ�.

�ذ� ��� : ���� ������ ������ ��, 6�� ���Ͽ��� 5���� Ǭ ���� ���� ���� ��� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : shake! 2018 A��
*/

int part[128][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &part[i][0], &part[i][1]);
    }
    qsort(part, n, sizeof(int) * 2, cmp1);
    for (int i = 5; i < n; i++) {
        if (part[i][0] == part[4][0]) r++;
    }
    printf("%d", r);
    return 0;
}