#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(3 <= N <= 1500)개의 점이 좌표평면 상에 있다. 이때, 좌표평면에서 만들 수 있는 직각삼각형의 개수를 구한다.
각 점의 좌표는 (-10^9 <= X, Y <= 10^9) 범위의 정수이다. 만드는 삼각형은 X, Y축에 평행하지 않아도 된다.
또한, 같은 위치에 여러 점이 주어지지는 않는다.

해결 방법 : 각 점마다 해당 점을 중심으로 각을 기준으로 하며 점들을 정렬한다.
그 후 시계방향으로 점들을 살펴보며 직각의 개수를 세면 된다. 이때, 직각인 점이 여러 개 생기는 경우에 유의한다.
또한, 배열을 1바퀴 도는 경우에도 유의해야 하며, 실수 오차가 생길 수 있으므로 정수형으로 비교해야 한다.
이를 반복하며 나오는 직각의 개수를 세서 더하면 답이 된다.

주요 알고리즘 : 기하학, 정렬, 투 포인터

출처 : COCI 07/08#2 6번
*/

long long pos[1536][2], npos[1536][2];

int cmp1(const void* a, const void* b) {
    //각을 기준으로 한 정렬
    long long ax = *(long long*)a;
    long long bx = *(long long*)b;
    long long ay = *((long long*)a + 1);
    long long by = *((long long*)b + 1);
    if ((ay < 0 || (ay == 0 && ax > 0)) && (by > 0 || (by == 0 && bx < 0))) return 1;
    else if ((ay > 0 || (ay == 0 && ax < 0)) && (by < 0 || (by == 0 && bx > 0))) return -1;
    else if (ay != 0 && by == 0) return 1;
    else if (ay == 0 && by != 0) return -1;
    else return (ax * by > bx * ay) ? 1 : (ax * by == bx * ay) ? 0 : -1;
}

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int main(void) {
    int n, r = 0, e2 = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            //다른 점들의 위치를 저장한다.
            npos[j - (j > i)][0] = pos[j][0] - pos[i][0];
            npos[j - (j > i)][1] = pos[j][1] - pos[i][1];
            if (pos[j][0] == pos[i][0] && pos[j][1] == pos[i][1]) {
                return 1;
            }
        }
        qsort(npos, n - 1, sizeof(long long) * 2, cmp1);
        e2 = -1; //직각의 마지막 점 + 1, 직각이 아니라면 음수로 둔다.
        for (int s = 0, e = 0; s < n - 1; s++) {
            //투 포인터를 시행한다.
            while (npos[e][0] * npos[s][0] + npos[e][1] * npos[s][1] >= 0 && npos[e][0] * npos[s][1] - npos[e][1] * npos[s][0] >= 0) {
                //예각 또는 직각인 경우 확인
                if (npos[e][0] * npos[s][0] + npos[e][1] * npos[s][1] == 0) {
                    //직각인 경우
                    if (e2 >= 0) r += e2 - e; //이미 직각의 개수를 확인한 경우
                    else {
                        e2 = e; //그 외에는 직각의 마지막 점인지를 확인한다.
                        while (e2 < n - 1 && npos[e2][0] * npos[s][0] + npos[e2][1] * npos[s][1] == 0 && npos[e2][0] * npos[s][1] - npos[e2][1] * npos[s][0] >= 0) {
                            e2++;
                            r++;
                        }
                    }
                    break;
                }
                else e2 = -1;
                e = (e + n) % (n - 1);
                if (e == s) break; //만약 한 바퀴를 넘어간 경우에는 현 시작점에서의 확인을 종료한다.
            }
        }
        //printf("%d ", r);
    }
    printf("%d", r);
    return 0;
}