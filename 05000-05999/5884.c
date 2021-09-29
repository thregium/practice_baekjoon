#include <stdio.h>
#include <stdlib.h>

/*
���� : ��ǥ���� N(N <= 50000)���� ���� �־��� ��, ��� ���� �ִ� 3���� ���� �Ǵ� ���������� ���� �� �ִ��� ���Ѵ�.
���򼱰� �������� ��� �ᵵ �Ǹ�, ��ǥ�� ������ +-10^9�̴�.

�ذ� ��� : �� ������ X�� �������� ������ ��, �� X�� ��ǥ���� �ش��ϴ� ���� ������ �迭�� ���� �����Ѵ�.
�̸� �ٽ� Y�� ���⿡�� �Ȱ��� �Ѵ�. �׷��� ������ �� �迭�� ū ������� �����Ѵ�.
���� ��� ���� 3���� ���� �Ǵ� ���������� ���� �� �ִٸ� �� �迭 �� �ϳ��� ũ�Ⱑ 3 ������ ���̹Ƿ� ������ �ذ� �����ϴ�.
2���� ���򼱰� 1���� ������ �Ǵ� �� �ݴ��� ���� X�� �迭���� 2���� 2 ����, Y�� �迭���� 3���� 1 ������ ���̴�.
�̸� X�� Y�� �ٲپ �غ��� �� ��쵵 �ذ� �����ϴ�. �� ���� ��� �ϳ��� �����Ѵٸ� ���� �� �ִ� ���̰�,
��� �������� �ʴ´ٸ� ���� �� ���� ���̴�.

�ֿ� �˰��� : ������, ����

��ó : USACO 2012O B2��
*/

int pos[51200][2], hor[51200], ver[51200];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2012_04\\3lines\\20.in", "r", stdin);
    int n, c = 1, hp = 0, vp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }

    qsort(pos, n, sizeof(int) * 2, cmp1);
    for (int i = 1; i < n; i++) {
        if (pos[i][0] != pos[i - 1][0]) {
            hor[hp++] = c;
            c = 1;
        }
        else c++;
    }
    hor[hp++] = c;

    qsort(pos, n, sizeof(int) * 2, cmp2);
    c = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i][1] != pos[i - 1][1]) {
            ver[vp++] = c;
            c = 1;
        }
        else c++;
    }
    ver[vp++] = c;

    qsort(hor, hp, sizeof(int), cmp1);
    qsort(ver, vp, sizeof(int), cmp1);

    if (vp <= 3 || hp <= 3 || (ver[1] <= 2 && hor[2] <= 1) || (hor[1] <= 2 && ver[2] <= 1)) printf("1");
    else printf("0");
    return 0;
}