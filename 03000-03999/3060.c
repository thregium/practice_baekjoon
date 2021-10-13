#include <stdio.h>

/*
문제 : 6마리의 돼지가 원형으로 있고, 매일 먹이의 생산량이 주어진다. 각 돼지들이 처음 먹는 먹이의 양이 각각 주어지면,
먹이가 모자라게 되는 첫 날을 구한다. 먹이는 누적되지 않는다. 각 날에 돼지들은 전날 먹은 먹이의 양에 더해
전날 양 옆과 반대쪽에 있는 돼지의 먹이의 양 합만큼 먹는다.

해결 방법 : 문제에 주어진대로 구현한다. 모듈로 연산을 이용하면 쉽게 구할 수 있다.

주요 알고리즘 : 구현, 시뮬레이션
*/

long long feed[1024][6];

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < 6; i++) {
            scanf("%lld", &feed[1][i]);
        }
        for (int i = 1;; i++) {
            if (i == 1024) return 1;
            if (feed[i][0] + feed[i][1] + feed[i][2] + feed[i][3] + feed[i][4] + feed[i][5] > n) {
                printf("%d\n", i);
                break;
            }
            for (int j = 0; j < 6; j++) {
                feed[i + 1][j] = feed[i][j] + feed[i][(j + 1) % 6] + feed[i][(j + 3) % 6] + feed[i][(j + 5) % 6];
            }
        }
    }
    return 0;
}