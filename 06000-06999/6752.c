#include <stdio.h>
#include <stdlib.h>

/*
���� : C(C <= 100)���� �Ͽ� ���� �ҿ� �ð�(<= 100000)�� �־��� ��, T(T <= 100000)�� ����
�� �� �ִ� ���� �ִ� ������ ���Ѵ�. ���� �ѹ��� �ϳ����� �� �� �ִ�.

�ذ� ��� : �ϵ��� �ð������� ������ ����, �� ������� �ð� �ȿ� ������ ��ŭ ���� �ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : CCC 2013 J4��
*/

int chore[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, c, r = 0;
    scanf("%d%d", &t, &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &chore[i]);
    }
    qsort(chore, c, sizeof(int), cmp1);
    for (int i = 0; i < c; i++) {
        t -= chore[i];
        if (t >= 0) r++;
        else break;
    }
    printf("%d", r);
    return 0;
}