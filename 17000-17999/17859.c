#include <stdio.h>
#include <stdlib.h>

/*
���� : A * B(7 <= A, B <= 100) ũ���� ���̸� ���� ���� �� �ִ� ���� ��� ���� ū 3���� ���ڸ� ����.
�� ���ڿ� 1 * 1 * 1 ũ���� ������ ���� �� ���� ������ ������ ū �ͺ��� ������� C, D, E(<= 10^9)��� �� ��,
���� ������ ������ [F, G](F < G <= 10^9) �������� �����ϴٸ� �� ������ ã�Ƽ� ����Ѵ�.

�ذ� ��� : ���� ū ������ ũ��� �۾ƾ� 25�̴�(1 * 5 * 5). ����, (G - F)�� ������ ���� ū ������
ũ�� ������ Ž���� �������� �ð� ���� ���ư���. ���� ū 3���� ���ڴ� ������ ��� ������ ũ�⸦ ����� ��
������������ �����ϸ� ã�� �� �ִ�.

�ֿ� �˰��� : ����, ������, ���Ʈ ����

��ó : ECNA 2019 H��
*/

int box[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int a, b, c, d, e, f, g, bcnt = 0;
    scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
    for (int i = 1;; i++) {
        if (a - 2 * i <= 0 || b - 2 * i <= 0) break;
        box[i - 1] = i * (a - 2 * i) * (b - 2 * i);
        bcnt = i;
    }
    qsort(box, bcnt, sizeof(int), cmp1);
    for (int i = c; i <= g; i += box[0]) {
        if (i < f) continue;
        if (i % box[1] == d && i % box[2] == e) {
            printf("%d", i);
            return 0;
        }
    }
    return 1;
}