#include <stdio.h>

/*
���� : N(N <= 30)���� M(M <= 30)���� ġŲ �귣�忡 ���� ��ȣ���� �־�����. 3���� ġŲ�� ��ų ��, �������� �ִ��
���� ���� �������� ���Ѵ�. �������� �� ����� ��Ų ġŲ ��� ���� ���� ��ȣ���� ���̴�.

�ذ� ��� : 3���� ġŲ�� ��Ű�� ��� ����� �õ��� ���� �� �� ���� �������� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : ��ϴ� 2018 �߹�
*/

int good[32][32];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, r = -1, s;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &good[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                s = 0;
                for (int l = 0; l < n; l++) {
                    s += big(good[l][i], big(good[l][j], good[l][k]));
                }
                if (s > r) r = s;
            }
        }
    }
    printf("%d", r);
    return 0;
}