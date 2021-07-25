#include <stdio.h>
#include <stdlib.h>

/*
���� : �� ����� ���� A, B(A, B <= 10000)���� ī�带 ���� �ִ�. �� ����� ���� ī�带 �ִ� �� ���̳� ���� �������� ���Ѵ�.
�� ��� ���� �ִ� ī�峪 �̹� ��ȯ�ߴ� ī��� ��ȯ�� �� ����.

�ذ� ��� : �� ����� ������ ���� ���� ī���� ������ ����. �� ī���� ������ �� ����� ��ȯ�� �� �ִ� ī���� ���̰�,
����, �� �� �� ���� ���� ��ȯ ������ Ƚ���̴�. ��밡 �ش� ī�带 ���� �ִ����� ���� �� �̺� Ž���� ���� ���� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, ����, �̺� Ž��

��ó : Brasil 2009 C��
*/

int alice[10240], beatriz[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int a, b, ap, bp;
    int* key;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2009\\troca.in", "r", stdin);
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0) break;
        for (int i = 0; i < a; i++) {
            scanf("%d", &alice[i]);
        }
        for (int i = 0; i < b; i++) {
            scanf("%d", &beatriz[i]);
        }
        qsort(alice, a, sizeof(int), cmp1);
        qsort(beatriz, b, sizeof(int), cmp1);
        ap = 0;
        bp = 0;
        for (int i = 0; i < a; i++) {
            if (i > 0 && alice[i] == alice[i - 1]) continue;
            key = &alice[i];
            if (bsearch(key, beatriz, b, sizeof(int), cmp1)) continue;
            else ap++;
        }
        for (int i = 0; i < b; i++) {
            if (i > 0 && beatriz[i] == beatriz[i - 1]) continue;
            key = &beatriz[i];
            if (bsearch(key, alice, a, sizeof(int), cmp1)) continue;
            else bp++;
        }
        if (ap > bp) printf("%d\n", bp);
        else printf("%d\n", ap);
    }
    return 0;
}