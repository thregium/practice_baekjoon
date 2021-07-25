#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 50000)���� ���� �������� �ִ�. �� ���� 10^9 ������ �ڿ����̰�, ������ �ִ� ��ġ�� 10^9 ������ �ڿ����̴�.
�̶�, ��� ������ ������ �����ϴ� ���� �� ���� ª�� ������ ã�´�.

�ذ� ��� : ����, ��� ������ ��ǥ �����Ͽ� 50000 ������ ���� �ٿ��ش�. ���� �� �����͸� ���� ���ʿ������� ������ ������
��� ������ ������ ������ �� ���� ������ ������. �׸��� ��� ���� �����ϴ� ���, �������� ������ ������ ������.
�̸� �ݺ��Ͽ� ��� ������ ã��, �� �� ���� ª�� ���� ���ϸ� �ȴ�.
�̶�, �� ���� ������ ������ �����ϴ����� ī��Ʈ �迭�� ���� ���� �� �ִ�. ���ο� ���� �� �� ������ 1���� �Ǿ��ٸ�
���ο� ������ ���� ���̰�, ������ 0���� �پ��� �ش� ������ ����� ���̴�.

�ֿ� �˰��� : �� ������, ����, �� ����

��ó : USACO 2011N S2��
*/

int cows[65536][3], cnt[65536];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c, r = INF, lo = 0, hi = 0, t = 1;
    //freopen("E:\\PS\\Olympiad\\USA\\Silver\\2011_11\\lineup\\I.12", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cows[i][0], &cows[i][1]);
    }
    qsort(cows, n, sizeof(int) * 3, cmp2);
    cows[0][2] = 1;
    for (int i = 1; i < n; i++) {
        if (cows[i][1] == cows[i - 1][1]) cows[i][2] = cows[i - 1][2];
        else cows[i][2] = cows[i - 1][2] + 1;
    }
    c = cows[n - 1][2];
    qsort(cows, n, sizeof(int) * 3, cmp1);
    cnt[cows[0][2]]++;
    while (hi < n) {
        if (t == c) {
            if (cows[hi][0] - cows[lo][0] < r) r = cows[hi][0] - cows[lo][0];
            cnt[cows[lo][2]]--;
            if (cnt[cows[lo][2]] == 0) t--;
            lo++;
        }
        else {
            cnt[cows[++hi][2]]++;
            if (cnt[cows[hi][2]] == 1) t++;
        }
    }
    printf("%d", r);
    return 0;
}