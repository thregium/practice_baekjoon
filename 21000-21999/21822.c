#include <stdio.h>

/*
문제 : N * M(N, M <= 1000) 크기의 배열에 '.', 'C', 'G'가 있다. 가능한 많은 'C'의 쌍을 지을 때,
지을 수 있는 'C' 쌍의 수를 구한다. 쌍을 짓기 위해서는 두 'C'가 하나의 'G'와 상하좌우로 인접해 있어야 하고,
이미 쌍을 지은 'G'는 다시 사용할 수 없다.

해결 방법 : 각 'G'는 한 번씩만 사용 가능하기 때문에 'G'를 기준으로 쌍을 짓는 것이 편하다.
'G'와 인접한 'C'가 둘 이상인 'G'의 수를 세 주면 대부분의 경우 쌍을 지을 수 있다. 그런데, 여기서
GC CG
CG GC
위의 두 형태로 이루어진 경우는 똑같은 'C'끼리만 인접하기 때문에 쌍을 2개 모두 지을 수 없고,
한 개의 쌍만 지을 수 있다. ('C'나 'G'가 더 많다면 반드시 쌍을 모두 지을 수 있게 된다.)(?)
따라서, 위 두 경우에 'G'에 인접한 'C'가 없는 것의 개수를 세고 결괏값에서 해당하는 모양의 개수를 빼면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 그래프 이론?

출처 : USACO 2021O B3번
*/

char pas[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, m, r = 0, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", pas[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pas[i][j] != 'G') continue;
            c = 0;
            for (int k = 0; k < 4; k++) {
                if (pas[i + dxy[k][0]][j + dxy[k][1]] == 'C') c++;
            }
            if (c >= 2) r++;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (pas[i][j] == 'C' && pas[i][j + 1] == 'G' && pas[i + 1][j] == 'G' && pas[i + 1][j + 1] == 'C') {
                if (pas[i - 1][j + 1] != 'C' && pas[i][j + 2] != 'C' && pas[i + 1][j - 1] != 'C' && pas[i + 2][j] != 'C') r--;
            }
            else if (pas[i][j] == 'G' && pas[i][j + 1] == 'C' && pas[i + 1][j] == 'C' && pas[i + 1][j + 1] == 'G') {
                if (pas[i - 1][j] != 'C' && pas[i][j - 1] != 'C' && pas[i + 1][j + 2] != 'C' && pas[i + 2][j + 1] != 'C') r--;
            }
        }
    }
    printf("%d", r);
    return 0;
}