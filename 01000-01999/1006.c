#include <stdio.h>

/*
문제 : 원의 둘레 부분을 2 * N(N <= 10000) 크기로 나누었다. 각 칸에는 10000 이하의 수들이 적혀있다.
변끼리 인접한 두 칸의 합이 W(W <= 10000)보다 작다면 두 칸을 한번에 선택할 수 있고, 아니라면 한 칸씩만 선택할 수 있다.
이 칸들을 조건에 맞게 나누기 위해 필요한 영역의 최소 개수를 구한다.

해결 방법 : 먼저 첫 번째 열과 마지막 열 사이 연결이 가능한지 확인한다. 첫 열과 마지막 열 사이 모든 가능한 연결 상태에 대해
나눌 수 있는 영역의 최소 개수를 각각 구한다. 최소 개수는 다이나믹 프로그래밍을 통해 구한다.
저장 공간에는 해당 칸까지 채운 상태에서 필요한 영역의 최소 개수를 바깥쪽, 안쪽, 전부 차있는 상태에 대해 각각 구한다.
그 다음 채워야 하는 모든 부분을 채웠을 때 해당 위치에서의 영역 개수를 가져오면 된다.
모든 상태에 대한 최소 개수 가운데 가장 작은 것이 답이 된다.

주요 알고리즘 : DP, 원형DP
*/

int wontagon[10240][2], mem[10240][3]; //0 : 바깥쪽만 차있는 경우, 1 : 양쪽 모두 차있는 경우, 2 : 안쪽만 차있는 경우

int small(int a, int b) {
    return a < b ? a : b;
}

int dp(int n, int w, int s) {
    //s == 0 : 첫 칸과 마지막 칸이 연결되지 않음, 1 : 바깥쪽만 연결됨, 2 : 안쪽만 연결됨, 3 : 양쪽 모두 연결됨
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) mem[i][j] = 987654321; //무한대로 초기화
    }

    //시작점 초기화
    mem[0][1] = 0;
    if (s & 1) mem[1][0] = 0;
    else mem[1][0] = 1;
    if (s & 2) mem[1][2] = 0;
    else mem[1][2] = 1;
    mem[1][1] = small(mem[1][0], mem[1][2]) + 1;
    if (s == 3) mem[1][1] = 0;
    if (wontagon[1][0] + wontagon[1][1] <= w) mem[1][1] = small(mem[1][1], mem[0][1] + 1);

    for (int i = 2; i <= n; i++) {
        mem[i][0] = mem[i - 1][1] + 1; //한칸
        mem[i][2] = mem[i - 1][1] + 1; //한칸

        if (wontagon[i][0] + wontagon[i - 1][0] <= w) {
            mem[i][0] = small(mem[i][0], mem[i - 1][2] + 1); //바깥쪽, 두칸
        }
        if (wontagon[i][1] + wontagon[i - 1][1] <= w) {
            mem[i][2] = small(mem[i][2], mem[i - 1][0] + 1); //안쪽, 두칸
            if (wontagon[i][0] + wontagon[i - 1][0] <= w) {
                mem[i][1] = small(mem[i][1], mem[i - 2][1] + 2); //바깥쪽 + 안쪽, 두칸 * 2
            }
        }
        mem[i][1] = small(mem[i][1], small(mem[i][0], mem[i][2]) + 1); //양쪽, 정리
        if (wontagon[i][0] + wontagon[i][1] <= w) mem[i][1] = small(mem[i][1], mem[i - 1][1] + 1); //양쪽, 두칸
    }
    
    //결괏값, 처음에 채워지지 않은 부분의 값에 연결을 통해 만들어진 영역의 수를 더한다.
    if (s == 0) return mem[n][1];
    else if (s == 1) return mem[n][2] + 1;
    else if (s == 2) return mem[n][0] + 1;
    else return mem[n - 1][1] + 2;
}

int main(void) {
    int t, n, w, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &w);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &wontagon[i][0]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &wontagon[i][1]);
        }

        if (n == 1) {
            if (wontagon[1][0] + wontagon[1][1] <= w) printf("1\n");
            else printf("2\n");
            continue;
        }

        r = dp(n, w, 0);
        if (wontagon[1][0] + wontagon[n][0] <= w) r = small(r, dp(n, w, 1));
        if (wontagon[1][1] + wontagon[n][1] <= w) {
            r = small(r, dp(n, w, 2));
            if (wontagon[1][0] + wontagon[n][0] <= w) r = small(r, dp(n, w, 3));
        }
        printf("%d\n", r);
    }
    return 0;
}