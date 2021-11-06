#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 1000)���� ���� �ִ�. Ml(Ml <= 10000)���� �� ���� ���� �Ÿ� D_i(D_i <= 10^6) ���� �־�� �ϰ�,
Md(Md <= 10000)���� �� ���� ���� �Ÿ� D_j(D_j <= 10^6) ���� �־�� �Ѵٰ� �� ��,
��� ���� ��ȣ ������ ���ʷ� ������ ���� ����� �ִ��� ���ϰ�, �ִٸ� �� �� 1���� N�� ���� ���� �� ���� �Ÿ��� ���Ѵ�.
����� ���ٸ� -1�� ����ϰ�, ������ �ָ� ���� �� �ִٸ� -2�� ����Ѵ�.

�ذ� ��� : ��� ������ ���� �� �ִ� ��ǥ�� ������ ���� �����Ѵ�. 1�� ���� 0 - 0, ������ ������ 0 - ���Ѵ��̴�.
�� �ڷδ� ������ ���� ��ȣ�� �� �ֺ��� Ȯ���ϸ� ��ǥ�� ������ ������ ������. ���� ������� �ϴ� ���̶��
���� ���� �ּڰ��� ���� ���� �ִ��� ������ �� �ְ�, �־�� �ϴ� ���̶�� ���� ���� �ִ񰪰� ���� ���� �ּڰ���
������ �� �ִ�. �� ����, �׷� ���� �յڷ� ������ �޴� �ٸ� ���鵵 �������ش�.

�̸� �����ϵ�, �� �� �����δ� ���������� ������ �޴� ��츦 �˾Ƴ� �� ���� ������ N������ �̸� �ݺ��Ѵ�.
��, N�� �ѵ��� ������ ��ӵȴٸ� ������ ������ ��ӵǱ� ������ ����� ���� ������ -1�� ����ؾ� �Ѵ�.
�ݺ��� ���� N�� ���� �ִ��� ����ϵ� ���Ѵ��� ���� -2�� ����ϵ��� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ����-����

��ó : USACO 2005D G3��
*/

int love[1024][1024], hate[1024][1024], range[1024][2];

int main(void) {
    int n, ml, md, a, b, d, r = 1, t = 0;
    //freopen("E:\\PS\\Olympiad\\USA\\3_Gold\\2005_12\\USACO 2005 December\\alldec05\\layout.10.in", "r", stdin);
    scanf("%d %d %d", &n, &ml, &md);
    for (int i = 0; i < ml; i++) {
        scanf("%d %d %d", &a, &b, &d);
        love[a][b] = d;
    }
    for (int i = 0; i < md; i++) {
        scanf("%d %d %d", &a, &b, &d);
        hate[a][b] = d;
    }
    for (int i = 2; i <= n; i++) range[i][1] = INF;
    while (r > 0 && t <= 1000) {
        //N + 1�� �ݺ�
        r = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (love[i][j]) {
                    //������� �ϴ� ���� ���
                    if (range[j][1] > range[i][1] + love[i][j]) {
                        //���� �ִ� ����
                        range[j][1] = range[i][1] + love[i][j];
                        for (int k = j - 1; k >= 1; k--) {
                            if (range[k][1] > range[j][1]) range[k][1] = range[j][1];
                        }
                        r = 1;
                    }
                    if (range[i][0] < range[j][0] - love[i][j]) {
                        //���� �ּڰ� ����
                        range[i][0] = range[j][0] - love[i][j];
                        for (int k = i + 1; k <= n; k++) {
                            if (range[k][0] < range[i][0]) range[k][0] = range[i][0];
                        }
                        r = 1;
                    }
                }
                if (hate[i][j]) {
                    //�־�� �ϴ� ���
                    if (range[j][0] < range[i][0] + hate[i][j]) {
                        //���� �ּڰ� ����
                        range[j][0] = range[i][0] + hate[i][j];
                        for (int k = j + 1; k <= n; k++) {
                            if (range[k][0] < range[j][0]) range[k][0] = range[j][0];
                        }
                        r = 1;
                    }
                    if (range[i][1] > range[j][1] - hate[i][j]) {
                        //���� �ִ� ����
                        range[i][1] = range[j][1] - hate[i][j];
                        for (int k = i - 1; k >= 1; k--) {
                            if (range[k][1] > range[i][1]) range[k][1] = range[i][1];
                        }
                        r = 1;
                    }

                }
            }
        }
        t++;
    }
    if (t > n) printf("-1");
    else if (range[n][1] >= INF) printf("-2");
    else printf("%d", range[n][1]);
    return 0;
}