#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
���� : N(N <= 50)���� ������� ���� �ڽ��� ���� ������ ���� �ִ�. �� ����� ������ ��� ���� �־�����
��� ���� ������ ������ �� �ɸ��� �ð��� ���Ѵ�. �� ����� ������ ��� ���� �� �� �������
���� �������� �����ִ� ���� �����ϰ�, ���� ������ �ٽ� �����ִ� ���� �ݺ��� �� ������� ���� ����ָ� �ȴ�.

�ذ� ��� : �� ������ �� ����� ���� �� �ִ� ���� �������� Ȯ���Ѵ�. �̸� ������ ��� ����� ���� �ִٸ�
���� ���� �������� �����Ѵ�. �̸� �� ������ �ݺ��ϸ� �� ����� ��� ���� ������ ������ �Ǵ� ���� ã��,
�� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : DP

��ó : JAG 2005D F��
*/

int day[32][64], mp[32][64][64];

int main(void) {
    int n, m, d, tc = 0;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2005D\\data\\F\\input\\F1", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2005D\\data\\F\\output\\F1_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &d);
                day[d][i] = 1;
            }
            for (int j = 1; j <= n; j++) mp[0][i][j] = 0;
            mp[0][i][i] = 1;
        }
        d = 0;
        for (int i = 1; i <= 30; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) mp[i][j][k] = mp[i - 1][j][k];
            }
            for (int j = 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if (day[i][j] && day[i][k]) {
                        for (int l = 1; l <= n; l++) {
                            mp[i][j][l] |= mp[i][k][l];
                            mp[i][k][l] |= mp[i][j][l];
                        }
                    }
                }
                d = 0;
                for (int k = 1; k <= n; k++) d += mp[i][j][k];
                if (d == n) {
                    printf("%d\n", i);
                    break;
                }
            }
            if (d == n) break;
        }
        if (d != n) printf("-1\n");

        for (int i = 1; i <= 30; i++) {
            for (int j = 1; j <= 50; j++) day[i][j] = 0;
        }
        tc++;
    }
    return 0;
}