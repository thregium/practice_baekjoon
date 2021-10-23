#include <stdio.h>
#include <stdlib.h>

/*
���� : ��ǥ��� �� N(N <= 100000)���� ���� �־��� ��, ������ �̾� ���� �� �ִ� X�� �Ǵ� Y�࿡ ������ ������ ������ ���Ѵ�.
��, ���� ������ ������ �͵� �������� �����Ѵ�. ����, �ߺ��� ������ ���� �ʴ´�.

�ذ� ��� : �� X��ǥ �Ǵ� Y��ǥ�� 2�� �̻��� ���� �ִٸ� �ش� ��ǥ������ ������ ���� �� �ִ�.
X��ǥ�� Y��ǥ�� ���������� ������ ����, �� ���� ������ ���� 2�� �̻��� ���� ������ ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ������, ����
*/

int xpos[103000], ypos[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xpos[i], &ypos[i]);
    }
    qsort(xpos, n, sizeof(int), cmp1);
    qsort(ypos, n, sizeof(int), cmp1);
    c = 1;
    for (int i = 1; i < n; i++) {
        if (xpos[i] == xpos[i - 1]) c++;
        else {
            if (c >= 2) r++;
            c = 1;
        }
    }
    if (c >= 2) r++;
    c = 1;
    for (int i = 1; i < n; i++) {
        if (ypos[i] == ypos[i - 1]) c++;
        else {
            if (c >= 2) r++;
            c = 1;
        }
    }
    if (c >= 2) r++;
    printf("%d", r);
    return 0;
}