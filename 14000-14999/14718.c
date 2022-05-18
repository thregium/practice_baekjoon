#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100)명의 적 병사가 있다. 각 적 병사의 세 스탯(<= 10^6)이 주어질 때,
K(K <= N)명 이상의 적을 이기는 가장 낮은 스탯 합을 구한다. 세 스탯이 모두 적 병사의 스탯보다 높은 경우
그 적을 이길 수 있다.

해결 방법 : 정답은 3개의 스탯 조합이 모두 어떤 적의 스탯 가운데 하나일 때이다.
따라서, 브루트 포스를 통해 세 스탯을 각각 어떤 적의 스탯 가운데 하나로 맞춘 다음,
K명 이상의 적을 이기는 가장 낮은 스탯 합을 찾아서 출력하면 된다.

주요 알고리즘 : 브루트 포스

출처 : 충남대 1회 C번
*/

int stat[128][3];

int main(void) {
    int n, ks, win, res = INF;
    scanf("%d %d", &n, &ks);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &stat[i][0], &stat[i][1], &stat[i][2]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                win = 0;
                for (int l = 0; l < n; l++) {
                    if (stat[i][0] >= stat[l][0] && stat[j][1] >= stat[l][1] && stat[k][2] >= stat[l][2]) {
                        win++;
                    }
                }
                if (win >= ks) {
                    if (stat[i][0] + stat[j][1] + stat[k][2] < res) {
                        res = stat[i][0] + stat[j][1] + stat[k][2];
                    }
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}