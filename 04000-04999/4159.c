#include <stdio.h>
#include <stdlib.h>

/*
���� : 1422������ �պ��Ϸ� �Ѵ�. �ѹ� ������ 200��ŭ �̵��� �����ϴٸ� �̵� �������� ���Ѵ�.

�ذ� ��� : 200�� �����̸� Ȯ���Ѵ�. 200 ������ ������ �� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : Waterloo 100926 B��
*/

int oil[2048];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l, r, i, j;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &oil[i]);
        }
        for (i = 0; i < 1322;) {
            for (j = 0; j < n && (oil[j] <= i || oil[j] > i + 200); j++);
            if (j == n) break;
            i = oil[j];
        }
        if (i < 1322) printf("IMPOSSIBLE\n");
        else printf("POSSIBLE\n");
    }
    return 0;
}