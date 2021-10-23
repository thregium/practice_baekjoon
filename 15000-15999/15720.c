#include <stdio.h>
#include <stdlib.h>

/*
���� : B���� ���ſ� C���� ���̵� �޴�, D���� ����(B, C, D <= 1000)�� ������ �־��� ��, ��� �޴��� ������ ��µ� �ʿ��� ���ݰ�,
���ΰ��� ��µ� �ʿ��� ������ ���Ѵ�. ���ΰ��� ����, ���̵� �޴�, ���Ḧ ������ ��, �ش��ϴ� �޴��� 10% ������ �ִ� ���̴�.
���󰡴� ��� 10000�� ������ 100�� ����̴�. ����, �� �޴��� 1������ ��� �Ѵ�.

�ذ� ��� : ���󰡴� �״�� ��ü�� ���� ���ϸ� �ȴ�.
���ΰ��� ��쿡�� ���� �� ������ ���ݰ�, �� ���̵� �޴��� ����, �� ������ ������ ������������ �����Ѵ�.
�� ����, B, C, D ��� ���� ���� �� ��ŭ�� ��Ʈ �޴��� ���. �ش��ϴ� �޴����� ������ 90% ������ �ȴ�.
�� ���� �޴����� ���� �״�� �� ���� ������ Ȯ���ϸ� ���ΰ��̴�.

�ֿ� �˰��� : ����, ����, �׸��� �˰���

��ó : �߾Ӵ� 2018R 2��
*/

int burg[1024], side[1024], bev[1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int b, c, d, e, r1 = 0, r2 = 0;
    scanf("%d %d %d", &b, &c, &d);
    for (int i = 0; i < b; i++) {
        scanf("%d", &burg[i]);
    }
    for (int i = 0; i < c; i++) {
        scanf("%d", &side[i]);
    }
    for (int i = 0; i < d; i++) {
        scanf("%d", &bev[i]);
    }
    e = small(b, small(c, d));
    qsort(burg, b, sizeof(int), cmp1);
    qsort(side, c, sizeof(int), cmp1);
    qsort(bev, d, sizeof(int), cmp1);
    for (int i = 0; i < b; i++) {
        r1 += burg[i];
        if (i < e) r2 += burg[i] / 10 * 9;
        else r2 += burg[i];
    }
    for (int i = 0; i < c; i++) {
        r1 += side[i];
        if (i < e) r2 += side[i] / 10 * 9;
        else r2 += side[i];
    }
    for (int i = 0; i < d; i++) {
        r1 += bev[i];
        if (i < e) r2 += bev[i] / 10 * 9;
        else r2 += bev[i];
    }
    printf("%d\n%d", r1, r2);
    return 0;
}