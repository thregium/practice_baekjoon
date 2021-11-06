#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� ���� ���簢���� ���� H�� �ʺ� W(0 < H < W <= 100)�� �־��� ��, �ش� ũ���� ���簢������ ū ���� ���簢�� ���
���� ���� ���� ���簢���� ũ�⸦ ���Ѵ�. ũ��� �밢���� �켱���� �ϸ�, �밢���� ���̰� ���ٸ� ���̰� ū ���� �� ũ��.
���� ���̿� �ʺ�� 150 �̳��� ������ �ִ�.

�ذ� ��� : �켱 150 * 150 ���� ���� ��� ���� ���� ���簢���� �迭�� ���� ����, ũ�� ������� �����Ѵ�.
������ �������� �̺� Ž���� ���� �迭���� �ش� ���簢���� ��ġ�� ã�� ���� ���簢���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, �̺� Ž��

��ó : JDC 2013 A��
*/

int rect[16384][2];

int cmp1(const void* a, const void* b) {
    int ah = *(int*)a;
    int bh = *(int*)b;
    int aw = *((int*)a + 1);
    int bw = *((int*)b + 1);
    if (ah * ah + aw * aw != bh * bh + bw * bw) return (ah * ah + aw * aw) - (bh * bh + bw * bw);
    return ah > bh ? 1 : ah == bh ? 0 : -1;
}

int main(void) {
    int p = 0, rt[2];
    int* r;
    for (int i = 1; i < 150; i++) {
        for (int j = i + 1; j < 150; j++) {
            rect[p][0] = i;
            rect[p++][1] = j;
        }
    }
    qsort(rect, p, sizeof(int) * 2, cmp1);
    while (1) {
        scanf("%d %d", &rt[0], &rt[1]);
        if (!rt[0]) break;
        r = bsearch(rt, rect, p, sizeof(int) * 2, cmp1);
        printf("%d %d\n", *(r + 2), *(r + 3));
    }
    return 0;
}