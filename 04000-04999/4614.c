#include <stdio.h>
#include <string.h>

/*
문제 : 길이가 최대 80인 지형이 문자열 형태로 주어진다. 이때, 이 지형의 무작위한 지점에 공을 떨어뜨렸을 때,
공이 구멍 또는 지형 밖으로 빠져나갈 확률을 백분율로 구한다.
구멍인 지점에 공이 떨어지면 공은 바로 빠져나가고, 평지에 멈추면 공은 빠져나가지 않고 멈춘다.
산비탈에 떨어지면 그 방향으로 구멍 또는 지형 밖 또는 다른 산비탈이나 벽이 나올 때 까지 굴러간다.
벽에 떨어지면 각각 1/2의 확률로 왼쪽 또는 오른쪽으로 굴러간다.

해결 방법 : 모든 지점에 대해 해당 지점에 공이 떨어졌을 때 공이 빠져나가는지 멈추는지를 확인해본다.
특히 벽인 지역의 경우 양방향에 대해 확인해봐야 한다. 그 다음으로, 빠져나간 횟수를 전체 지형의 크기로 나누면
빠져나가는 경우의 기댓값을 구할 수 있고, 이에 100을 곱해 백분율 형태로 만들 수 있다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : MidC 2006 B번
*/

char pach[128];

int main(void) {
    int holes, len;
    double prob;
    while (1) {
        scanf("%s", pach);
        if (pach[0] == '#') break;
        len = strlen(pach);
        holes = 0;
        for (int i = 0; i < len; i++) {
            if (pach[i] == '.') holes += 2;
            else if (pach[i] == '_') continue;
            else if (pach[i] == '/') {
                for (int j = i - 1;; j--) {
                    if (j < 0 || pach[j] == '.') {
                        holes += 2;
                        break;
                    }
                    else if (pach[j] == '\\' || pach[j] == '|') break;
                }
            }
            else if (pach[i] == '\\') {
                for (int j = i + 1;; j++) {
                    if (j >= len || pach[j] == '.') {
                        holes += 2;
                        break;
                    }
                    else if (pach[j] == '\\' || pach[j] == '|') break;
                }
            }
            else if (pach[i] == '|') {
                for (int j = i - 1;; j--) {
                    if (j < 0 || pach[j] == '.') {
                        holes++;
                        break;
                    }
                    else if (pach[j] == '\\' || pach[j] == '|') break;
                }
                for (int j = i + 1;; j++) {
                    if (j >= len || pach[j] == '.') {
                        holes++;
                        break;
                    }
                    else if (pach[j] == '\\' || pach[j] == '|') break;
                }
            }
        }
        prob = holes * 100;
        prob /= len * 2;
        printf("%d\n", (int)prob);
    }
    return 0;
}