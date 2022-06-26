#include <stdio.h>

/*
���� : N(N <= 20)���� ������ M(M <= 100)���� ���� �̷���� 2-SAT ������ �ذ� �����ϴ� �� Ȯ���Ѵ�.

�ذ� ��� : ������ ���� ������ ���� ������ ��� ��츦 �õ��غ��鼭 �ذ� �����ϴ� �� Ȯ���ϸ� �ȴ�.

�ֿ� �˰����� : ���Ʈ ����, ��Ʈ����ŷ
*/

int x[32], c[128][2], res[32];

int main(void) {
    int n, m, r = 0, t, c1, c2;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &c[i][0], &c[i][1]);
    }
    for (int i = 0; i < (1 << n); i++) {
        t = 1;
        for (int j = 0; j < m; j++) {
            if (c[j][0] < 0) c1 = (!((i >> (-c[j][0] - 1)) & 1));
            else c1 = ((i >> (c[j][0] - 1)) & 1);
            if (c[j][1] < 0) c2 = (!((i >> (-c[j][1] - 1)) & 1));
            else c2 = ((i >> (c[j][1] - 1)) & 1);
            if (!(c1 || c2)) {
                t = 0;
                break;
            }
        }
        if (t) {
            r = 1;
            for (int j = 0; j < n; j++) res[j] = ((i >> j) & 1);
            break;
        }
    }
    if (!r) printf("0");
    else {
        printf("1\n");
        //for (int i = 0; i < n; i++) printf("%d ", res[i]);
    }
    return 0;
}