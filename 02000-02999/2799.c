#include <stdio.h>

/*
���� : M * N(M, N <= 100) ũ���� â�� ���°� �־��� ��, ����ε��� ���� ������ ���� �� �з��� ������ ����Ѵ�.

�ذ� ��� : �� â������ ���� ���̸� Ȯ���ϰ�, �� ���� �迭�� ���Ѵ�. ��� â���� Ȯ���ϰ� �迭�� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : COCI 11/12#6 2��
*/

char blind[512][512];
int cnt[5];

int main(void) {
    int m, n, t;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m * 5 + 1; i++) {
        scanf("%s", blind[i]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            t = 0;
            for (int k = 0; k < 4; k++) {
                if (blind[i * 5 + 1 + k][j * 5 + 1] == '*') t++;
            }
            cnt[t]++;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", cnt[i]);
    }
    return 0;
}