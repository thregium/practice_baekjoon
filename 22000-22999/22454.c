#include <stdio.h>

/*
���� : N(N <= 100)���� �˰� �ִ� ���� �ٸ� ����� ����������, ���������� ����� ����� ����� �־��� ��,
�� �� ���������� ������ ����� �������� Ȯ���ϰ� �����ϴٸ� �� ����� ��ȣ�� ����Ѵ�.
�ڽ��� ���������� �������� �ʾҰ�, �˰� �ִ� �ٸ� ����� ���������� �� �Ϻ� �Ǵ� ���θ� �����Ѵ�.

�ذ� ��� : �� ����� ���� ������ �˰� �ִ� �� ���θ� �迭�� �����Ѵ�. �� ������� ����� �������� ��θ�
�˰� �ִ� �� Ȯ���ϰ� �׷��� ����� ���� ���Ѵ�. 1���� ��쿡�� �� ����� ��ȣ�� ����ϰ�, �� �ܿ��� -1�� ����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : JAG 2012D A��
*/

int know[128][128], leak[128];

int main(void) {
    int n, m, x, t;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2012D\\domestic-2012-judge-data\\judge\\A\\A1", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &x);
                know[i][x] = 1;
            }
        }
        scanf("%d", &m);
        x = -1;
        for (int i = 0; i < m; i++) {
            scanf("%d", &leak[i]);
        }
        for (int i = 1; i <= n; i++) {
            t = 1;
            for (int j = 0; j < m; j++) {
                if (!know[i][leak[j]]) t = 0;
            }
            if (t) {
                if (x < 0) x = i;
                else x = 0;
            }
        }
        printf("%d\n", x ? x : -1);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) know[i][j] = 0;
        }
    }
    return 0;
}