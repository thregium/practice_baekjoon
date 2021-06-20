#include <stdio.h>

/*
���� : N���� ����� M(N, M <= 50)���� ��Ƽ�� �ִ�. ������ �ƴ� ����̳� ������ �ƴ� ����� ���� ��Ƽ�� ���� ���,
�׷��� ������ ���� ��Ƽ�� ���� ��� ���� ������ ����鿡�� ������ ���� �������� �Ϸ��� �� ��, �������� �ص� �Ǵ� ��Ƽ�� ���� ���Ѵ�.

�ذ� ��� : �������� �ص� �Ǵ� ��Ƽ�� ���� ������ �ƴ�(�Ǵ� �˰� ��/��) ������� ���� ��Ƽ�̴�.
������ �ƴ� ����̳� �˰� �� ����� ������ �ƴ� ������ ���� ��Ƽ�� �ִ� ��츦 �������� ������ ���� ������ �ƴ� ����鿡�� ����ϴ� �÷������� ������
Ž���� ������ ����. �� ��Ƽ�� ������ �����ص� ���� �ٽ� �׷��� ������� ���� ��Ƽ�� ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����
*/

int truth[64], parties[64][64], heard[64][64];
int n;

void participate(int x) {
    for (int i = 1; i <= n; i++) {
        if (!heard[x][i]) continue;
        if (truth[i]) continue;
        truth[i] = 1;
        participate(i);
    }
}

int main(void) {
    int m, t, x, r = 0;
    scanf("%d %d", &n, &m);
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &x);
        truth[x] = 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &parties[i][0]);
        for (int j = 1; j <= parties[i][0]; j++) {
            scanf("%d", &parties[i][j]);
        }
        for (int j = 1; j <= parties[i][0]; j++) {
            for (int k = 1; k <= parties[i][0]; k++) {
                heard[parties[i][j]][parties[i][k]] = 1;
                heard[parties[i][k]][parties[i][j]] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (truth[i]) participate(i);
    }
    for (int i = 0; i < m; i++) {
        t = 1;
        for (int j = 1; j <= parties[i][0]; j++) {
            if (truth[parties[i][j]]) {
                t = 0;
                break;
            }
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}