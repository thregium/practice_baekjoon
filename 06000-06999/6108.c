#include <stdio.h>
#include <stdlib.h>

/*
���� : N * N(N < 100, N�� Ȧ��) ũ���� �迭�� 1000 ������ �ڿ����� ä���� �ִ�.
�̶�, �� ���� �߾Ӱ��� ���� �迭�� �߾Ӱ��� ���Ѵ�.

�ذ� ��� : �� ���� �Է¹����� �����Ѵ�. �� ���� �߾Ӱ�(N / 2��° ����)�� ���ο� �迭�� ���� ��,
���ο� �迭�� �ٽ� �����ؼ� �߾Ӱ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : USACO 2008M B3��
*/

int beauty[128], beauty2[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &beauty[j]);
        }
        qsort(beauty, n, sizeof(int), cmp1);
        beauty2[i] = beauty[n >> 1];
    }
    qsort(beauty2, n, sizeof(int), cmp1);
    printf("%d", beauty2[n >> 1]);
    return 0;
}