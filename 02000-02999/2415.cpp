#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
using namespace std;

/*
문제 : N(N <= 1500)개의 점이 좌표평면상에 있다. 직사각형을 이루는 4개의 서로 다른 점 가운데
넓이가 가장 넓은 것의 넓이를 구한다. 각 점의 좌표는 절댓값 10^8 이하 정수이다.

해결 방법 : 3008번과 마찬가지로 각 점에 대해 그 점과의 상대적인 좌표를 저장하고,
이 값들을 각도 순서대로 정렬해 나가면서 각이 90도인 쌍들을 투 포인터 알고리즘으로 찾아나간다.
그러한 쌍들에 대해 반대쪽 4번째 점이 있는 지 찾고, 그러하다면 넓이의 최댓값을 갱신해 나간다.
최종적으로 나온 넓이의 최댓값이 답이 된다.

주요 알고리즘 : 기하학, 정렬, 투 포인터, 해시셋

출처 : BtOI 2009 4번
*/

long long pos[1536][2], npos[1536][2];
unordered_set<long long> h;

int cmp1(const void* a, const void* b) {
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

long long sqr(long long x) {
    return x * x;
}

long long ccwz(long long bx, long long by, long long cx, long long cy) {
    return llabs((bx * cy) - (by * cx));
}

int main(void) {
    int n, e2 = -1;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            npos[j - (j > i)][0] = pos[j][0] - pos[i][0];
            npos[j - (j > i)][1] = pos[j][1] - pos[i][1];
            if (pos[j][0] == pos[i][0] && pos[j][1] == pos[i][1]) {
                return 1;
            }
            h.insert(npos[j - (j > i)][0] * (1LL << 32) + npos[j - (j > i)][1]);
        }
        qsort(npos, n - 1, sizeof(long long) * 2, cmp1);
        e2 = -1;
        for (int s = 0, e = 0; s < n - 1; s++) {
            while (npos[e][0] * npos[s][0] + npos[e][1] * npos[s][1] >= 0 && npos[e][0] * npos[s][1] - npos[e][1] * npos[s][0] >= 0) {
                if (npos[e][0] * npos[s][0] + npos[e][1] * npos[s][1] == 0) {
                    if (e2 >= 0) {
                        for (int i = e; i <= e2; i++) {
                            if (npos[i][0] * npos[s][0] + npos[i][1] * npos[s][1] != 0) continue;
                            if (h.find((npos[s][0] + npos[i][0]) * (1LL << 32) + npos[s][1] + npos[i][1]) != h.end()) {
                                if (ccwz(npos[s][0], npos[s][1], npos[i][0], npos[i][1]) > r) {
                                    r = ccwz(npos[s][0], npos[s][1], npos[i][0], npos[i][1]);
                                }
                            }
                        }
                        //r += e2 - e;
                    }
                    else {
                        e2 = e;
                        while (e2 < n - 1 && npos[e2][0] * npos[s][0] + npos[e2][1] * npos[s][1] == 0 && npos[e2][0] * npos[s][1] - npos[e2][1] * npos[s][0] >= 0) {
                            if (h.find((npos[s][0] + npos[e2][0]) * (1LL << 32) + npos[s][1] + npos[e2][1]) != h.end()) {
                                if (ccwz(npos[s][0], npos[s][1], npos[e2][0], npos[e2][1]) > r) {
                                    r = ccwz(npos[s][0], npos[s][1], npos[e2][0], npos[e2][1]);
                                }
                            }
                            e2++;
                        }
                    }
                    break;
                }
                else e2 = -1;
                e = (e + 1) % (n - 1);
                if (e == s) break;
            }
        }

        while (h.size()) h.erase(h.begin());
    }

    printf("%lld", r);
    return 0;
}