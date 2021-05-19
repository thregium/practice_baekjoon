#include <stdio.h>

/*
문제 : 쿠로사와 다이아와 쿠로사와 루비가 N * N(N <= 2000) 크기의 초콜릿을 가지고 각자의 턴마다 다음과 같은 행동을 할 수 있다.
1. 소수 * 소수 크기의 초콜릿을 가져온다.(해당 부분에 전부 초콜릿이 있어야 한다.) 2. 1 * 1 크기의 초콜릿을 가져온다.
마지막 초콜릿을 가져오는 사람이 이긴다면 누가 이기게 되는지 구한다. 단, 루비가 선공이고, 처음에 주어지는 초콜릿에 없는 부분이 있을 수 있다.

해결 방법 : 2 * 2 크기의 초콜릿을 가져오는 경우가 없다고 가정하면 항상 홀수개의 초콜릿을 가져오게 된다.
따라서, 홀수개인 경우에는 항상 루비, 짝수개인 경우에는 항상 다이아가 이기게 된다.
그런데 2 * 2 크기의 초콜릿을 가져올 수 있다면 각 턴의 홀짝성이 바뀌기 때문에 홀수개일 때는 다이아, 짝수개일 때는 루비가 이기게 될 것이다.

이제 2 * 2 크기의 초콜릿을 가져올 수 있는지 확인하면 된다. 우선 짝수개일 때에는 루비가 선공이므로 2 * 2인 부분이 있기만 한다면 루비가 이길 것이고,
아니라면 다이아가 이길 것이다. 홀수개인 경우에는 루비가 모든 2 * 2인 부분을 홀짝성을 바꾸지 않고 지울 수 있다면 이길 수 있다.
즉, 2 * 2가 아닌 크기의 초콜릿을 가져와서 모든 2 * 2 초콜릿을 지우면 되는데, 비교적 쉽게 해결하는 방법으로는 모든 2 * 2 초콜릿의 위치 중
X, Y 좌표의 최대, 최솟값을 각각 저장하는 것이다. 그 다음, 최솟값 또는 + 1부터 최댓값 또는 -1까지의 초콜릿을 확인하면
모든 2 * 2 초콜릿들이 1칸 이하로 남으므로 모든 2 * 2 초콜릿을 지울 수 있는 후보가 되고, 이제 이 후보들이 실제로 유효한지만 확인하면 된다.

주요 알고리즘 : 게임 이론

출처 : GNY 2020 F번
*/

int n;
char choco[2048][2048], sieve[2048];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int has2by2(int oxs, int oxe, int oys, int oye) {
    if (oxs > oxe) return 0;
    int xs, xe, ys, ye, t;
    for (int i = 0; i < 16; i++) {
        xs = oxs + (i & 1);
        xe = oxe - ((i & 2) >> 1);
        ys = oys + ((i & 4) >> 2);
        ye = oye - ((i & 8) >> 3);
        if (xs > xe || ys > ye || (xe - xs) != (ye - ys)) continue;
        if (sieve[xe - xs + 1] || xe - xs + 1 == 2) continue;
        t = 0;
        for (int x = xs; x <= xe; x++) {
            for (int y = ys; y <= ye; y++) {
                if (choco[x][y] == 'X') {
                    t = 1;
                    break;
                }
            }
        }
        if (t) continue;
        return 0;
    }
    return 1;
}

int main(void) {
    int cnt = 0, xs = 3331, xe = 0, ys = 3331, ye = 0, two = 0;
    for (int i = 2; i <= 2000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 2000; j += i) {
            sieve[j] = 1;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", choco[i]);
        for (int j = 0; j < n; j++) {
            if (choco[i][j] == '-') {
                cnt++;
                if (i && j && choco[i][j - 1] == '-' && choco[i - 1][j] == '-' && choco[i - 1][j - 1] == '-') {
                    xs = small(xs, i - 1);
                    xe = big(xe, i);
                    ys = small(ys, j - 1);
                    ye = big(ye, j);
                }
            }
        }
    }

    two = has2by2(xs, xe, ys, ye);
    if (cnt & 1) {
        printf("%s", two ? "DIA" : "RUBY");
    }
    else {
        printf("%s", xs > xe ? "DIA" : "RUBY");
    }
    
    return 0;
}