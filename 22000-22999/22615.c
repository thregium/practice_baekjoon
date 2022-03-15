#include <stdio.h>
#define INF 1012345678LL

/*
���� : N(N <= 100)���� ���� ����ؾ� �Ѵ�. �� ���� ü���� HP_i(HP_i <= 100000)�̴�.
�� ������ M(M <= 100)���� ������ ���� ��� �����ϴ�. �� ������ ���� ������ M_i(M_i < 100)��ŭ �Ҹ��ϰ�
�� �� �ϳ� �Ǵ� ��� ���� ü���� D_i(D_i < 10^6)��ŭ ��´�.
�̶�, ��� ���� óġ�ϱ� ���� ����ؾ� �ϴ� ������ �ּڰ��� ���Ѵ�.

�ذ� ��� : �� ������ 1ü�� ��ü �������� ���� ����, �� �������� ü�� ���ҷ��� ����
�ּ� ���� �Һ��� ������ ���� �����ش�. ��, �� �������� ����ų�� �����ؾ� �Ѵ�.
����� HP �ִ��� 10���̹Ƿ� 10���� �Ѵ� ���� 10������ �δ� ���� ����.

�� ������ ���� �������� ��ü �������� ��� ����� ü���� ��� ���(0 ~ 100000)�� Ȯ���� ���鼭
�� �� ���� ������ ���� �� ���� ���� �Ҹ��� ã���� �ȴ�.
�־��� ��� ���� int ������ �Ѿ �� �����Ƿ� �����Ѵ�.

�ֿ� �˰��� : DP, ����, ���Ʈ ����

��ó : JAG 2009S2 B��
*/

char buff1[32], buff2[16];
int hp[128], spells[128][2], spella[128][2];
int mems[103000 * 2], mema[103000 * 2];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, ms = 0, ma = 0, mp, dam;
    long long r = INF * INF, t;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &hp[i]);
        }
        ms = 0, ma = 0, r = INF * INF;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%s %d %s %d", buff1, &mp, buff2, &dam);
            if (dam > 100000) dam = 100000;
            if (buff2[0] == 'S') {
                spells[ms][0] = mp;
                spells[ms++][1] = dam;
            }
            else {
                spella[ma][0] = mp;
                spella[ma++][1] = dam;
            }
        }
        for (int i = 1; i <= 200000; i++) {
            mems[i] = INF;
            mema[i] = INF;
        }
        for (int i = 0; i < ms; i++) {
            for (int j = 0; j <= 200000; j++) {
                if (j >= spells[i][1] && mems[j - spells[i][1]] + spells[i][0] < mems[j]) {
                    mems[j] = mems[j - spells[i][1]] + spells[i][0];
                }
            }
        }
        for (int i = 0; i < ma; i++) {
            for (int j = 0; j <= 200000; j++) {
                if (j >= spella[i][1] && mema[j - spella[i][1]] + spella[i][0] < mema[j]) {
                    mema[j] = mema[j - spella[i][1]] + spella[i][0];
                }
            }
        }
        for (int i = 199999; i >= 0; i--) {
            if (mems[i + 1] < mems[i]) mems[i] = mems[i + 1];
            if (mema[i + 1] < mema[i]) mema[i] = mema[i + 1];
        }

        for (int i = 0; i <= 100000; i++) {
            if (mema[i] == INF) continue;
            t = mema[i];
            for (int j = 0; j < n; j++) {
                if (hp[j] - i > 0) t += mems[hp[j] - i];
            }
            if (t < r) r = t;
        }
        printf("%lld\n", r);
    }
    return 0;
}