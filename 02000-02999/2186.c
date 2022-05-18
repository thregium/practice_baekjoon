#include <stdio.h>
#include <string.h>

/*
���� : N * M(N, M <= 100) ũ���� �����ǿ� �빮�ڵ��� �����ִ�. �׸��� ���� 80 ������ �빮�ڷ� �̷����
���ڿ��� �־��� ��, �����ǿ��� �����¿�� K(K <= 5)ĭ �̳��� ����������
�־��� ���ڿ��� ����� ����� �������� ���Ѵ�.

�ذ� ��� : �� ��ġ�� �� ��°���� �������� �����ϸ鼭 ���̳��� ���α׷����� �ϸ� �ȴ�.
K�� �����Ƿ� ���� ����ȭ�� �� �ʿ�� ����.

�ֿ� �˰��� : DP
*/

char alph[128][128], word[96];
int mem[96][128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, m, k, l, xx, yy, res = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", alph[i]);
    }
    scanf("%s", word);
    l = strlen(word);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (alph[i][j] == word[0]) mem[0][i][j] = 1;
        }
    }
    for (int wi = 1; wi < l; wi++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (alph[i][j] != word[wi]) continue;
                for (int d = 0; d < 4; d++) {
                    for (int dd = 1; dd <= k; dd++) {
                        xx = i + dxy[d][0] * dd;
                        yy = j + dxy[d][1] * dd;
                        if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                        if (alph[xx][yy] != word[wi - 1]) continue;
                        mem[wi][i][j] += mem[wi - 1][xx][yy];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res += mem[l - 1][i][j];
        }
    }
    printf("%d", res);
    return 0;
}