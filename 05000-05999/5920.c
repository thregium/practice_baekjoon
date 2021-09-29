#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� N(N <= 20000)�� 1���� N������ �ڿ����� �̷���� ������ 5�� �־�����. �̶�, �� �������� ���� ��������
�� ���� ������ �ٸ� ��ġ�� �ű� ���̶�� �ϸ�, ������ ������ ���Ѵ�. �� �� �Ű��� ���� �ٸ� ���������� �Ű����� �ʴ´�.

�ذ� ��� : ��ü �������� �� ���� ������ ��, ���� ������ ������ �ٲ�� ���� 5���� ���� ��� ���ƾ� 2�� ���̴�.
(�� �� �� �ϳ��� �̵��ؾ� �ϹǷ�) ����, 5���� �������� ������ ��ġ�� ����� ����, �����ϸ� �� ���� ��ġ�� ���Ѵ�.
5���� �� ��� �� ���� ���� ���� �´� ������ ���� �ش� ������ ������ ���� ���ĵ� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : �ֵ� Ȥ, ����

��ó : USACO 2011D B2��
*/

int pos[5][20480], res[20480];
int n;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int r = 0;

    for (int i = 0; i < 5; i++) {
        if (pos[i][ai] > pos[i][bi]) r++;
        else r--;
    }
    return r;
}

int main(void) {
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2011_12\\photo_bronze\\I.6", "r", stdin);
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2011_12\\photo_bronze\\O_t.6", "w", stdout);
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            pos[i][x] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        res[i] = i + 1;
    }
    qsort(res, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}