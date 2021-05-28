#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� N(N <= 1000)�� ���� 3���� �־����� N���� ���ҵ鿡 ���� ���� 3�� �� 2��°�� ū i��° ���Ҹ� ���� ����Ѵ�.

�ذ� ��� : ������ �Է¹��� ���� ���� �����ؼ� 2��° ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : UKIEPC 2020 M��
*/

int dist[1024][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        qsort(dist[i], 3, sizeof(int), cmp1);
        printf("%d ", dist[i][1]);
    }
    return 0;
}