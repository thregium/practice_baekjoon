#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ���� M(M <= 100)���� ī�带 ���� �ִ�. �� ī��� 100 ������ �ڿ����� ���� �ִ�.
�� ����� ���帶�� ���� �ִ� ī�� ��� ���� ū ���� ���� ī�带 ���� �� ī�带 ������.
�̶� ���� ū ���� ���� ī�带 ���� �ִ� ����� 1���� ��´�.(���� ����), ���� ������ ���� ����� ������������ ����Ѵ�.

�ذ� ��� : �� ����� ī����� ������������ �����Ѵ�. �� ����, �� ���帶�� ī����� ����
���� ū ���� ���� ����� ������ ���̰�, ���� ������ ���� ������� ã�� ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : ���ϴ� 2016 F��
*/

int card[128][128], score[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, best = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &card[i][j]);
        }
        qsort(card[i], m, sizeof(int), cmp1);
    }
    for (int i = 0; i < m; i++) {
        best = -1;
        for (int j = 0; j < n; j++) {
            if (card[j][i] > best) best = card[j][i];
        }
        for (int j = 0; j < n; j++) {
            if (card[j][i] == best) score[j]++;
        }
    }
    best = -1;
    for (int i = 0; i < n; i++) {
        if (score[i] > best) best = score[i];
    }
    for (int i = 0; i < n; i++) {
        if (score[i] == best) printf("%d ", i + 1);
    }
    return 0;
}