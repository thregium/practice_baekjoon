#include <stdio.h>
#include <stdlib.h>
#define INF 1234567890987654321

/*
문제 : N(N <= 1000)개의 가로등이 있고, 각 가로등은 각각의 위치(0 <=, <= 1000)와 전력 소모량(0 <, <= 10^8)을 갖는다.
M번째 가로등에서 출발해 1초에 1씩 움직이며 가로등을 끈다면 낭비되는 전력량을 구한다.
낭비되는 전력량은 매 초마다 켜진 가로등의 전력 소모량과 같다.

해결 방법 : 먼저 전체 가로등이 1초마다 쓰는 전력량을 구한 다음, 모든 구간에 대해 해당 구간의 가로등을 껐을 때의
1초마다 쓰는 전력량을 구해둔다. 그 다음으로는, 각 구간별로 해당 구간을 탐사하고 왼쪽 또는 오른쪽 끝에 있을 때의
최소 전력 소모량을 찾아나간다.

그러기 위해서는 먼저 M번째 가로등을 제외한 나머지 구간의 최소 전력 소모량을 무한대로 초기화한다.(M번째는 0으로 초기화)
그 다음으로는 범위를 넓혀가며 최소 전력 소모량을 구해나가면 되는데,  그 소모량은 최근 위치를 제외한 해당 구간의 범위에서
양쪽 끝 가운데 (왔을 때의 최소 소모량 + 오면서 추가되는 최소 소모량)이 더 작은 값이다.
왔을 때의 최소 소모량은 저장해둔 값과 같고, 오면서 추가되는 소모량은 그때 켜져있는 가로등의 전력 소모량 * 이동 거리이다.

이를 반복해 1 ~ N번 가로등 전체를 확인하게 되면 왼쪽 끝에서 끝날 때와 오른쪽 끝에서 끝날 때의 전력 소모량을 비교해서
더 적게 소모한 것을 출력하면 된다.

주요 알고리즘 : DP, 누적 합
*/

long long esum[1024][1024], mem[1024][1024][2];
int light[1024][2];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &light[i][0], &light[i][1]);
    }
    m = light[m][0];
    qsort(light + 1, n, sizeof(int) * 2, cmp1); //순서대로가 아닐 수 있으므로 정렬해둔다.
    for (int i = 1; i <= n; i++) esum[n][1] += light[i][1]; //전체 구간의 전력 소모량 합 계산
    for (int i = 1; i <= n; i++) {
        esum[i][i - 1] = esum[n][1];
        for (int j = i; j <= n; j++) esum[i][j] = esum[i][j - 1] - light[j][1]; //해당 구간만 불이 꺼진 경우의 전력 소모량
        if (light[i][0] != m) {
            mem[i][i][0] = INF; //M번째를 제외한 가로등의 시작 값 초기화
            mem[i][i][1] = INF;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            mem[j][i + j][0] = small(mem[j + 1][i + j][0] + esum[j + 1][i + j] * (light[j + 1][0] - light[j][0]),
                mem[j + 1][i + j][1] + esum[j + 1][i + j] * (light[i + j][0] - light[j][0])); //왼쪽 이동
            mem[j][i + j][1] = small(mem[j][i + j - 1][0] + esum[j][i + j - 1] * (light[i + j][0] - light[j][0]),
                mem[j][i + j - 1][1] + esum[j][i + j - 1] * (light[i + j][0] - light[i + j - 1][0])); //오른쪽 이동
        }
    }
    if (small(mem[1][n][0], mem[1][n][1]) >= INF || small(mem[1][n][0], mem[1][n][1]) < 0) return 1; //불가능한 상황 대비?
    printf("%lld", small(mem[1][n][0], mem[1][n][1])); //결괏값
    return 0;
}