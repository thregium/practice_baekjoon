#include <stdio.h>

/*
���� : �־��� N(N <= 500)������ �ҵ��� ��ǥ�� �־��� ��, ���� �ָ� ������ �� ���� ���Ѵ�. �Ÿ��� ��Ŭ���� �Ÿ� �����̰�,
���� �ָ� ������ ���� �����ϴ�.

�ذ� ��� : ��� ���� ���ؼ� ���� �ָ� ������ ���� ã���� �ȴ�. �� ���� �Ÿ��� ��Ÿ��� ������ �̿��Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : USACO 2009D B2��
*/

int cows[512][2];

int getdist(int a, int b) {
    return (cows[a][0] - cows[b][0]) * (cows[a][0] - cows[b][0]) + (cows[a][1] - cows[b][1]) * (cows[a][1] - cows[b][1]);
}

int main(void) {
    int n, best = 0, a = 0, b = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &cows[i][0], &cows[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (getdist(i, j) > best) {
                best = getdist(i, j);
                a = i;
                b = j;
            }
        }
    }
    printf("%d %d", a, b);
    return 0;
}