#include <stdio.h>

/*
���� : N + 1(N <= 50)���� ���� �������� �̷���� ������ �־�����. �̶�, ó�� �־��� ������
���� ������ ��ȣ�� ��� ����Ѵ�. ���� ������ 90�� ������ ������ ���� ������ ������ ��ġ�� ����̴�.
������ ����� �������� ��쵵 �����Ѵ�. �׷��� ��Ī�� ���� �������� �ʴ´�.

�ذ� ��� : ���� ������ �־��� ������ �������� (0, 0)���� ���߾� �д�. �׸��� 90���� ��������
4���� ���⿡ ���� ���� ������ ��ġ�ϴ� �� Ȯ���Ѵ�. 90���� ���� ������ ���� ������ ���⿡��
X��ǥ�� Y��ǥ�� ��ȯ�ϵ� �� �� �ϳ��� ������ �������� �ȴ�. �� ������ Ȯ���� ��������
�־��� ������ ������ ������ �������� �ٽ� (0, 0)���� ���� ���� �ٽ� 90���� 4������ Ȯ���Ѵ�.
�߰��� ������ ��ġ�ϴ� ���� ���Դٸ� ���� �����̰�, ������ ������ �ʾҴٸ� �ٸ� �����̴�.
���� ������ ��� �� ������ ��ȣ�� ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ������, ���Ʈ ����

��ó : JDC 2005 B��
*/

int tpl[16][2], lin[16][2], tmp[16][2];

void rot90(int m) {
    int t;
    for (int i = 1; i < m; i++) {
        t = lin[i][0];
        lin[i][0] = -lin[i][1];
        lin[i][1] = t;
    }
}

void revlin(int m) {
    for (int i = 0; i < m; i++) {
        tmp[m - i - 1][0] = lin[i][0];
        tmp[m - i - 1][1] = lin[i][1];
    }
    for (int i = 0; i < m; i++) {
        lin[i][0] = tmp[i][0] - tmp[0][0];
        lin[i][1] = tmp[i][1] - tmp[0][1];
    }
}

int arrcmp(int m) {
    for (int i = 0; i < m; i++) {
        if (tpl[i][0] - lin[i][0] || tpl[i][1] - lin[i][1]) return 1;
    }
    return 0;
}

int linecmp(int m) {
    for (int i = m - 1; i >= 0; i--) {
        tpl[i][0] -= tpl[0][0], tpl[i][1] -= tpl[0][1];
        lin[i][0] -= lin[0][0], lin[i][1] -= lin[0][1];
    }
    for (int i = 0; i < 4; i++) {
        if (!arrcmp(m)) return 1;
        rot90(m);
    }
    revlin(m);
    for (int i = 0; i < 4; i++) {
        if (!arrcmp(m)) return 1;
        rot90(m);
    }
    return 0;
}

int main(void) {
    int n, m, l;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &tpl[i][0], &tpl[i][1]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &l);
            for (int j = 0; j < l; j++) {
                scanf("%d %d", &lin[j][0], &lin[j][1]);
            }
            if (l != m) continue;
            if (linecmp(m)) printf("%d\n", i);
        }
        printf("+++++\n");
    }
    return 0;
}