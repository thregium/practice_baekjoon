#include <stdio.h>

/*
���� : N(N <= 200)������ �ڿ����� ��� M(M <= 10000)������ ���� ���� �� ���� ������ �����ϰ� 3���� �̴� ������ �������� ���Ѵ�.

�ذ� ��� : 3���� ���� �̾ƺ��� ���� ���� �� ���� ������ �����ϰ� ������ ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : BtOI 2011 2��
*/

int mix[256][256];

int main(void) {
    int n, m, a, b, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        mix[a][b] = 1;
        mix[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (mix[i][j]) continue;
            for (int k = j + 1; k <= n; k++) {
                if (mix[i][k] || mix[j][k]) continue;
                r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}