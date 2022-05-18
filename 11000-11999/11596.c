#include <stdio.h>
#include <stdlib.h>

/*
���� : �� �ﰢ���� �� ���� ����(<= 100)�� �־��� ��, ���簢���� �߶�
�� �ﰢ���� ����� ����� �ִ� �� ���Ѵ�.

�ذ� ��� : �켱 �� �ﰢ���� ������ ����, �� �ﰢ���� �� ���� ���̰� ��� ���� ��(�յ�����) Ȯ���Ѵ�.
�� ����, �� �ﰢ���� ��� ���� �ﰢ���� �� Ȯ���Ѵ�. �� ������ ��� �����ϸ�
���ǿ� �´� ���簢���� �ְ�, �ϳ��� �������� �ʴ´ٸ� ���ǿ� �´� ���簢���� ����.

�ֿ� �˰��� : ������, ����

��ó : PacNW 2015 D/T�� // SEUSA 2015D2 K��
*/

int t1[3], t2[3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int r = 1;
    scanf("%d %d %d%d %d %d", &t1[0], &t1[1], &t1[2], &t2[0], &t2[1], &t2[2]);
    qsort(t1, 3, sizeof(int), cmp1);
    qsort(t2, 3, sizeof(int), cmp1);
    for (int i = 0; i < 3; i++) {
        if (t1[i] != t2[i]) r = 0;
    }
    if (t1[0] * t1[0] + t1[1] * t1[1] != t1[2] * t1[2]) r = 0;
    if (t2[0] * t2[0] + t2[1] * t2[1] != t2[2] * t2[2]) r = 0;

    if (r) printf("YES");
    else printf("NO");
    return 0;
}