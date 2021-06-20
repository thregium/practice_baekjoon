#include <stdio.h>

/*
문제 : N명의 사람과 M(N, M <= 50)개의 파티가 있다. 진실을 아는 사람이나 진실을 아는 사람과 같은 파티에 가는 사람,
그러한 사람들과 같은 파티에 가는 사람 등을 제외한 사람들에게 가능한 많이 거짓말을 하려고 할 때, 거짓말을 해도 되는 파티의 수를 구한다.

해결 방법 : 거짓말을 해도 되는 파티의 수는 진실을 아는(또는 알게 된/될) 사람들이 없는 파티이다.
진실을 아는 사람이나 알게 된 사람은 진실을 아는 사람들과 같은 파티에 있는 경우를 간선으로 연결한 다음 진실을 아는 사람들에서 출발하는 플러드필을 돌려서
탐색된 정점과 같다. 각 파티의 정보를 저장해둔 다음 다시 그러한 사람들이 없는 파티의 수를 세면 된다.

주요 알고리즘 : 그래프 이론, 플러드필
*/

int truth[64], parties[64][64], heard[64][64];
int n;

void participate(int x) {
    for (int i = 1; i <= n; i++) {
        if (!heard[x][i]) continue;
        if (truth[i]) continue;
        truth[i] = 1;
        participate(i);
    }
}

int main(void) {
    int m, t, x, r = 0;
    scanf("%d %d", &n, &m);
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &x);
        truth[x] = 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &parties[i][0]);
        for (int j = 1; j <= parties[i][0]; j++) {
            scanf("%d", &parties[i][j]);
        }
        for (int j = 1; j <= parties[i][0]; j++) {
            for (int k = 1; k <= parties[i][0]; k++) {
                heard[parties[i][j]][parties[i][k]] = 1;
                heard[parties[i][k]][parties[i][j]] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (truth[i]) participate(i);
    }
    for (int i = 0; i < m; i++) {
        t = 1;
        for (int j = 1; j <= parties[i][0]; j++) {
            if (truth[parties[i][j]]) {
                t = 0;
                break;
            }
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}