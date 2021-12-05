#include <stdio.h>
#define HI 1234567898765

/*
���� : N(N <= 5)���� �ĺ��� �ְ�, �� �ĺ��� �������� ��ǥ ����� �־�����.(<= 10^6)
�̶�, �ּ� �� ���� ǥ�� ���ؾ� �ᵵ���� ���ڰ� ���� �Ǵ��� ���Ѵ�.
��, ���ºΰ� �ƴ� ���� ��찡 ���;� �ᵵ���� ���ڰ� �ƴ� ���̴�.

�ذ� ��� : N�� �ſ� �۱� ������ �� �ĺ����� �̱�� �ĺ����� ��츦 ��� Ȯ���غ���.
�� ��� ���� �߰��� ǥ�� ���� ��츦 ã���� �ȴ�. �̱�� �ĺ���� ����� ����Ŭ�� ���� �׷����� �Ǵ� ���
�ݵ�� 1���� ����� �ȴ�.
����, �� ����Ŭ ������ �߰��ؾ� �� ǥ�� ����Ŭ �ۿ��� �߰��ؾ� �� ǥ�� ���� ���� �� �ִ�.
����Ŭ ������ �߰��ؾ� �� ǥ�� ǥ�� �߰��� �� ���� ����Ŭ�� ��� �� ���� ǥ�� �����ؾ� �Ѵٴ� ������ �ִ�.
�̸� ���� �̿��ؼ� �� ǥ ������ �ش� ǥ�� ����Ŭ ������ ���� �����ϰ� �� �� �ִ��� ���Ѵ�.
����Ŭ �ܿ��� �����ϴ� ���� ���� ���� �߰��ؾ� �� ǥ �� ��� ���� ���� ������ ã���� ������ ���� �� �ִ�.

�� ���� ���ؼ� �� ū ���� �߰��ؾ� �ϴ� ǥ ���̴�. �� ���� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ����, ���Ʈ ����

��ó : SEUSA 2020 D�� // MidC 2020 C�� // PacNW 2020 K�� // SCUSA 2020 D��
*/

char cond[128][8];
int vote[128], lose[8], weight[8], vis[8];

int getres(int n, long long x) {
    long long s = 0, l = 1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            s += (weight[i] + x - 1) >> 1;
            if (weight[i] < l) l = weight[i];
        }
    }
    return (s >= x && 1 - l <= x);
}

int main(void) {
    int n, m, stt, sml, cnt, t;
    long long lo, hi, mid, res = HI;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2020\\condorcet\\data\\secret\\7002.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%s %d", cond[i], &vote[i]);
    }
    if (n != 3 && n != 4 && n != 5) return 1;
    for (int i = 0; i < (n == 3 ? 8 : n == 4 ? 81 : 1024); i++) {
        for (int j = 0, k = i; j < n; j++) {
            lose[j] = k % (n - 1);
            if (lose[j] >= j) lose[j]++;
            weight[j] = 0;
            k /= (n - 1);
        }
        t = 0;
        for (int j = 0; j < 5; j++) {
            if (lose[lose[j]] == j) t = 1;
        }
        if (t) continue;

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n - 1; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (lose[cond[j][k] - 'A'] == cond[j][l] - 'A') {
                        weight[cond[j][k] - 'A'] -= vote[j];
                    }
                    if (lose[cond[j][l] - 'A'] == cond[j][k] - 'A') {
                        weight[cond[j][l] - 'A'] += vote[j];
                    }
                }
            }
        }
        stt = 0, cnt = 0;
        for (int i = 0; i < n; i++) vis[i] = 0;
        while (!vis[stt]) {
            vis[stt] = 1;
            stt = lose[stt];
        }
        for (int i = 0; i < n; i++) vis[i] = 0;
        while (!vis[stt]) {
            vis[stt] = 1;
            stt = lose[stt];
            cnt++;
        }

        lo = 0, hi = HI;
        /*
        while (lo < hi) {
            mid = ((lo + hi) >> 1);
            if (getres(n, mid)) hi = mid;
            else lo = mid + 1;
        }
        */
        while (!getres(n, lo) && lo <= res) lo++;
        sml = 1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && weight[i] < sml) sml = weight[i];
        }
        //lo += 1 - sml;
        if (1 - sml > lo) lo = 1 - sml;

        if (lo < res) {
            res = lo;
        }
    }
    if (res == HI) return 2;
    printf("%lld", res);
    return 0;
}