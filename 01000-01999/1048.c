#include <stdio.h>
#define MOD 1000000007

/*
���� : N * M(N, M <= 300) ũ���� ü���ǿ� A���� L(L <= 26)��° ���ĺ����� ���ĺ� �빮�ڵ��� ���� �ִ�.
50�� ������ �빮�ڷ� �̷���� ���ڿ��� �־��� ��, �������� ������ �ش� �ܾ ����� ����� ���Ѵ�.
�������� ���� �������� 2ĭ �̻�, �ٸ��� �������� 3ĭ �̻� ������ ĭ���� ������ �� �ִ� ���̴�.

�ذ� ��� : �켱 ù ��° ���ڰ� ��ġ�ϴ� ���� ���� 1, ��ġ���� �ʴ� ���� 0���� ���� �� ���̳��� ���α׷����� �����Ѵ�.
�Ź� ��ġ�ϴ� ���� ���� �ܰ迡�� �� �� �ִ� ���� ���� ������ �ΰ�, ��ġ���� �ʴ� ���� 0���� �д�.

���⼭ �ӵ��� ���̱� ���� ���� ���� �����ؾ� �Ѵ�. ��� �� ������ ���� �������� �����ϸ�
��ü �� - ������ �� 3���� �� 3���� �� + ������ 3 * 3 ũ���� �� - ��� ���� ��� 2���� ������ ĭ�� ���� ����
���� ���� �� �ִ�. �̶� ������ ����� �ʵ��� �����ؾ� �Ѵ�.
�̸� �ݺ��Ͽ� ������ �ܰ迡 ���� ��ü ���� ���� �ȴ�.

�ֿ� �˰��� : DP, ���� ��

��ó : TCO 2009R1 3��
*/

char chess[384][384], s[64];
int mem[384][384], nmem[384][384], hsum[384][384], vsum[384][384];

int main(void) {
    int n, m, l, tot = 0;
    scanf("%d %d %d", &n, &m, &l);
    scanf("%s", s);
    for (int i = 1; i <= n; i++) {
        scanf("%s", chess[i] + 1);
        for (int j = 1; j <= m; j++) {
            //���� ���
            if (chess[i][j] == s[0]) mem[i][j] = 1;
            else mem[i][j] = 0;
            tot += mem[i][j];
            hsum[i][j] = hsum[i][j - 1] + mem[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) vsum[j][i] = vsum[j - 1][i] + mem[j][i];
    }
    
    for (int i = 1; s[i]; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (chess[j][k] != s[i]) {
                    //�ٸ� ������ ��� 0���� ó��
                    nmem[j][k] = 0;
                    continue;
                }
                nmem[j][k] = tot; //��ü

                nmem[j][k] = (nmem[j][k] + MOD - vsum[n][k]) % MOD; //��
                if (k > 1) nmem[j][k] = (nmem[j][k] + MOD - vsum[n][k - 1]) % MOD;
                if (k < m) nmem[j][k] = (nmem[j][k] + MOD - vsum[n][k + 1]) % MOD;
                nmem[j][k] = (nmem[j][k] + MOD - hsum[j][m]) % MOD; //��
                if (j > 1) nmem[j][k] = (nmem[j][k] + MOD - hsum[j - 1][m]) % MOD;
                if (j < n) nmem[j][k] = (nmem[j][k] + MOD - hsum[j + 1][m]) % MOD;

                for (int l = 0; l < 9; l++) {
                    if (j + (l % 3 - 1) >= 1 && j + (l % 3 - 1) <= n && k + (l / 3 - 1) >= 1 && k + (l / 3 - 1) <= m) {
                        nmem[j][k] = (nmem[j][k] + mem[j + (l % 3 - 1)][k + (l / 3 - 1)]) % MOD; //�ֺ� ĭ ó��
                    }
                }
                if (j > 2 && k > 2) nmem[j][k] = (nmem[j][k] + MOD - mem[j - 2][k - 2]) % MOD; //2, 2 ĭ ó��
                if (j > 2 && k < m - 1) nmem[j][k] = (nmem[j][k] + MOD - mem[j - 2][k + 2]) % MOD;
                if (j < n - 1 && k > 2) nmem[j][k] = (nmem[j][k] + MOD - mem[j + 2][k - 2]) % MOD;
                if (j < n - 1 && k < m - 1) nmem[j][k] = (nmem[j][k] + MOD - mem[j + 2][k + 2]) % MOD;

            }
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) hsum[j][k] = (hsum[j][k - 1] + nmem[j][k]) % MOD; //�� ������
        }

        tot = 0;
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                mem[k][j] = nmem[k][j];
                tot = (tot + mem[k][j]) % MOD; //���°�
                vsum[k][j] = (vsum[k - 1][j] + mem[k][j]) % MOD; //�� ������
            }
        }
    }
    printf("%d", tot);
    return 0;
}