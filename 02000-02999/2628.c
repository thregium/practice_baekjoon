#include <stdio.h>
#include <stdlib.h>

/*
���� : ���̸� ���μ��� ���μ����� �ڸ��� ��ġ�� �־��� ��, ���� ū ������ ũ�⸦ ���Ѵ�.

�ذ� ��� : �� ���ο� ���ο��� ���� ���� ������ ���ϰ�, �� ���� ���ϸ� �ȴ�.
���� ���� ������ �ڸ��� ��ġ�� ������ ����, ��ġ�� ���� ������ ���� ū ���� ���� ���� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : ���� 2001 ��1��
*/

int vers[256], hors[256];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int w, h, n, horn = 1, vern = 1, d, p, horr = 0, verr = 0;
    scanf("%d %d", &w, &h);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &d, &p);
        if (d) vers[vern++] = p;
        else hors[horn++] = p;
    }
    hors[horn++] = h;
    vers[vern++] = w;
    qsort(hors, horn, sizeof(int), cmp1);
    qsort(vers, vern, sizeof(int), cmp1);
    for (int i = 1; i < horn; i++) {
        if (hors[i] - hors[i - 1] > horr) horr = hors[i] - hors[i - 1];
    }
    for (int i = 1; i < vern; i++) {
        if (vers[i] - vers[i - 1] > verr) verr = vers[i] - vers[i - 1];
    }
    printf("%d", horr * verr);
    return 0;
}