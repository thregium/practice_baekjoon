#include <stdio.h>

/*
문제 : N(N <= 20)명의 사람들이 각 라운드마다 손을 위 또는 아래로 한다. 만약 한 명만 다른 것을
한 다면, 그 사람을 제외하고 다시 이를 2명만 남을 때 까지 반복한다. 그 외의 경우 그대로 반복한다.
이때, 각 사람이 손을 위로 할 확률이 주어지면 2명만 남을 때까지 반복하는 횟수의 기댓값을 구한다.

해결 방법 : 각 남은 사람 목록에 대해 그때의 기댓값과 그 목록이 남을 확률을 각각 구해서 저장하며
비트마스킹 DP를 하면 된다. 각 단계마다 한 명이 탈락할 확률과 그렇지 않을 확률을 먼저 구해둔다.
각 사람이 탈락할 확률을 각각 구하고 더하면 한 명이 탈락할 확률이다.

각 다음 단계에서 기댓값은 현재 기댓값 + 1 + 1 / (1 / 탈락하지 않을 확률 - 1)과 같다.
그러나, 확률에 대한 가중 평균이 필요하기 때문에 먼저 이 값에 현재 확률 * 그 사람이 탈락할 확률을
곱한 값을 더해나간다. 그러다가 현재 값이 필요한 시점이 오면 그때 와서 현재 확률로 기댓값을 나누어 준 다음
그 값을 사용하면 된다.

이를 반복한 다음, 각 경우를 확인하면서 2명이 남은 경우 각각에 대해 기댓값과 확률을 곱한 값을 더해주면
답이 된다.

주요 알고리즘 : DP, 비트DP, 확률론

출처 : PacNW 2021 P번 // SCUSA 2021D1 A번 / 2021D2 B번 // MidC 2021 B번
*/

double meme[1048576], memp[1048576], p[32];

int main(void) {
    int n, cnt;
    double allup = 1.0, alldown = 1.0, sumnxt, sumre, probo, res = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &p[i]);
    }
    meme[(1 << n) - 1] = 0.0;
    memp[(1 << n) - 1] = 1.0;
    for (int i = (1 << n) - 1; i >= 0; i--) {
        meme[i] /= memp[i];
        sumnxt = 0.0;
        allup = 1.0, alldown = 1.0;
        for (int j = 0; j < n; j++) {
            if (!((i >> j) & 1)) continue;
            allup *= p[j];
            alldown *= (1.0 - p[j]);
        }
        for (int j = 0; j < n; j++) {
            if (!((i >> j) & 1)) continue;
            sumnxt += allup / p[j] * (1.0 - p[j]);
            sumnxt += alldown / (1.0 - p[j]) * p[j];
        }
        sumre = 1.0 - sumnxt;
        for (int j = 0; j < n; j++) {
            if (!((i >> j) & 1)) continue;
            probo = allup / p[j] * (1.0 - p[j]) + alldown / (1.0 - p[j]) * p[j];
            probo /= sumnxt;
            meme[i - (1 << j)] += (meme[i] + (1.0 + 1.0 / (1.0 / sumre - 1))) * memp[i] * probo;
            memp[i - (1 << j)] += memp[i] * probo;
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) cnt++;
        }
        if (cnt == 2) res += meme[i] * memp[i];
    }
    printf("%.9f", res);
    return 0;
}