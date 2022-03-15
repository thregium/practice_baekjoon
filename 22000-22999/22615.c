#include <stdio.h>
#define INF 1012345678LL

/*
문제 : N(N <= 100)개의 적을 상대해야 한다. 각 적은 체력이 HP_i(HP_i <= 100000)이다.
각 적들은 M(M <= 100)가지 마법을 통해 상대 가능하다. 각 마법은 각각 마나를 M_i(M_i < 100)만큼 소모하고
적 중 하나 또는 모든 적의 체력을 D_i(D_i < 10^6)만큼 깎는다.
이때, 모든 적을 처치하기 위해 사용해야 하는 마나의 최솟값을 구한다.

해결 방법 : 각 마법을 1체와 전체 공격으로 나눈 다음, 각 종류마다 체력 감소량에 따른
최소 마나 소비량을 냅색을 통해 구해준다. 단, 이 과정에서 오버킬에 유의해야 한다.
상대의 HP 최댓값이 10만이므로 10만을 넘는 값은 10만으로 두는 것이 좋다.

그 값들을 구한 다음에는 전체 공격으로 깎는 상대의 체력의 모든 경우(0 ~ 100000)를 확인해 가면서
그 중 가장 마나를 적게 쓸 때의 마나 소모량을 찾으면 된다.
최악의 경우 값이 int 범위를 넘어갈 수 있으므로 주의한다.

주요 알고리즘 : DP, 냅색, 브루트 포스

출처 : JAG 2009S2 B번
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