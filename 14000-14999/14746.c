#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : ���� Y = c1(|c1, c2| <= 10^9)�� N(N, M <= 500000)���� ������ �̷���� ���� P��
Y = c2�� M���� ������ �̷���� ���� Q�� �־�����. P�� Q�� �� ���� ����ư �Ÿ��� ���� ���� ����
����ư �Ÿ��� �׷��� ���� ������ ���Ѵ�. P�� Q�� ��� ���� ���� �ٸ� ��ġ�� �ִ�.

�ذ� ��� : P�� Q�� ��� ���� ���� �ٸ� ��ġ�� �ֱ� ������, ���� ��ġ�� �ִ� ���� �ִ� 2���̴�.
����, ��� ������ X��ǥ ������� ������ ����, ������ ���� �� ��� ���� �ٸ� ���տ� �ִ�
���鿡 ���ؼ��� ���̸� ���鼭 ���� ã�Ƴ����� �ȴ�.

�ֿ� �˰��� : �ֵ� Ȥ?, ����

��ó : Daejeon 2017I A��
*/

int a[1048576][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai > bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, c1, c2, lw = INF, lwc = 0;
    scanf("%d %d%d %d", &n, &m, &c1, &c2);
    for (int i = 0; i < n + m; i++) {
        scanf("%d", &a[i][0]);
        if (i >= n) a[i][1] = 1;
    }
    qsort(a, n + m, sizeof(int) * 2, cmp1);
    for (int i = 1; i < n + m; i++) {
        if (a[i][1] == a[i - 1][1]) continue;
        if (a[i][0] - a[i - 1][0] < lw) {
            lw = a[i][0] - a[i - 1][0];
            lwc = 1;
        }
        else if (a[i][0] - a[i - 1][0] == lw) lwc++;
    }
    printf("%d %d", lw + abs(c1 - c2), lwc);
    return 0;
}