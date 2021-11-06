#include <stdio.h>
#include <stdlib.h>

/*
���� : J(J <= 1000)���� ������ ���� �� �ִ� N(N <= 1000)���� ���ڰ� �־�����. �� ���ڿ��� �� ������ ũ�⸸ŭ
������ ���� �� �ִٸ�, ��� ������ ��� ���� �ּ� �� ���� ���ڰ� �ʿ����� ���Ѵ�.

�ذ� ��� : ���� ū ���ں��� ��� ���� �����̴�. ���� ��� ������ ũ�⸦ ������������ ������ ����,
ū �ͺ��� ���ʷ� ���ڿ� ������ ��� ������ ��� �Ǵ� ���� ���� ���� ã���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : Thai 2015B J��
*/

int box[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, j, n, r, c, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &j, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &r, &c);
            box[i] = r * c;
        }
        qsort(box, n, sizeof(int), cmp1);
        s = 0;
        for (int i = 0; i < n; i++) {
            if (s >= j) {
                printf("%d\n", i);
                break;
            }
            else s += box[i];
        }
        if (s < j) return 1;
    }
    return 0;
}