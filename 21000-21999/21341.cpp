#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <set>
using namespace std;

/*
문제 : N * N(N <= 100000) 크기의 보드에서 두 사람이 말을 움직여 상대 말을 잡는 게임을 한다.
한 사람은 한 턴에 N가지 이동 가운데 하나를 골라 이동하는 것을 2회 하거나, 상대 말이 없는 곳으로 워프할 수 있다.
또는, 그 자리에 그대로 있는 것도 가능하다. 이때, 현재 턴인 사람이 다음 턴에 이기는지, 지는지, 둘 다 아니라면
어떻게 이동해야 지지 않는지 구한다.
각 이동은 특정한 방향으로 특정한 칸만큼 이동하는 것을 말하며, 보드 밖으로 이동하는 것은 불가능하다.

해결 방법 : 모든 이동을 살펴보기에는 N이 매우 크기 때문에 잡으려는 말을 잡을 수 있는 위치와
잡는 말이 이동할 때의 위치를 각각 구한 다음 중복되는 것이 있는지 확인하여 갈 수 있는지 구한다.
만약 A에서 B로 이동 가능하다면 해당 턴에 상대 말을 잡을 수 있다는 뜻이므로 이긴다.
반대로, B에서 모든 칸으로 이동 가능하다면 어떻게 이동해도 잡히므로 지게 된다.
그런데, N이 4 이상인 경우 그러한 상황은 일어나는 것이 불가능해진다. 또한, N이 커질 수록 B가 한번에 이동 가능한 칸 수는
N^2 / 2에 수렴하기 때문에 전체 칸의 약 절반 정도만 이동 가능하게 된다.
따라서, N이 작은 경우에는 직접 구해주고, 큰 경우에는 무작위로 잡히지 않을 때 까지 이동해서 잡히지 않는 곳의 위치를 찾으면 된다.

주요 알고리즘 : 밋 인 더 미들, 무작위화

출처 : NWERC 2020 E번
*/

int a[2], b[2], pos[103000][2], rpos[103000][2], board[1024][1024];
set<pair<int, int>> st;

int main(void) {
    int n, r = 0, rx = 0, ry = 0, t = 0;
    srand((unsigned)time(NULL));
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2020\\nwerc2020all\\endgame\\data\\secret\\60-random.in", "r", stdin);
    scanf("%d", &n);
    scanf("%d %d", &a[0], &a[1]);
    scanf("%d %d", &b[0], &b[1]);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        rpos[i][0] = -pos[i][0];
        rpos[i][1] = -pos[i][1];
    }
    if (n <= 1000) {
        for (int i = 0; i < n; i++) {
            if (b[0] + pos[i][0] < 1 || b[0] + pos[i][0] > n) continue;
            if (b[1] + pos[i][1] < 1 || b[1] + pos[i][1] > n) continue;
            board[b[0] + pos[i][0]][b[1] + pos[i][1]] = 1;
            for (int j = 0; j < n; j++) {
                if (b[0] + pos[i][0] + pos[j][0] < 1 || b[0] + pos[i][0] + pos[j][0] > n) continue;
                if (b[1] + pos[i][1] + pos[j][1] < 1 || b[1] + pos[i][1] + pos[j][1] > n) continue;
                board[b[0] + pos[i][0] + pos[j][0]][b[1] + pos[i][1] + pos[j][1]] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[0] + pos[i][0] < 1 || a[0] + pos[i][0] > n) continue;
            if (a[1] + pos[i][1] < 1 || a[1] + pos[i][1] > n) continue;
            for (int j = 0; j < n; j++) {
                if (a[0] + pos[i][0] + pos[j][0] < 1 || a[0] + pos[i][0] + pos[j][0] > n) continue;
                if (a[1] + pos[i][1] + pos[j][1] < 1 || a[1] + pos[i][1] + pos[j][1] > n) continue;
                if (b[0] == a[0] + pos[i][0] + pos[j][0] && b[1] == a[1] + pos[i][1] + pos[j][1]) {
                    printf("Alice wins");
                    return 0;
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == b[0] && j == b[1]) continue;
                if (!board[i][j]) {
                    printf("tie %d %d", i, j);
                    return 0;
                }
            }
        }
        printf("Bob wins");
    }
    else {
        for (int i = 0; i < n; i++) {
            if (b[0] + rpos[i][0] < 1 || b[0] + rpos[i][0] > n) continue;
            if (b[1] + rpos[i][1] < 1 || b[1] + rpos[i][1] > n) continue;
            st.insert(pair<int, int>(b[0] + rpos[i][0], b[1] + rpos[i][1]));
        }
        for (int i = 0; i < n; i++) {
            if (a[0] + pos[i][0] < 1 || a[0] + pos[i][0] > n) continue;
            if (a[1] + pos[i][1] < 1 || a[1] + pos[i][1] > n) continue;
            if (st.find(pair<int, int>(a[0] + pos[i][0], a[1] + pos[i][1])) != st.end()) {
                printf("Alice wins");
                return 0;
            }
        }
        while (1) {
            srand(rand() * n + a[0]);
            a[0] = (rand() * 32768LL + rand()) % n + 1;
            a[1] = (rand() * 32768LL + rand()) % n + 1;
            if (a[0] == b[0] && a[1] == b[1]) continue;
            st.clear();
            t = 0;
            for (int i = 0; i < n; i++) {
                if (a[0] + rpos[i][0] < 1 || a[0] + rpos[i][0] > n) continue;
                if (a[1] + rpos[i][1] < 1 || a[1] + rpos[i][1] > n) continue;
                st.insert(pair<int, int>(a[0] + rpos[i][0], a[1] + rpos[i][1]));
            }
            for (int i = 0; i < n; i++) {
                if (b[0] + pos[i][0] < 1 || b[0] + pos[i][0] > n) continue;
                if (b[1] + pos[i][1] < 1 || b[1] + pos[i][1] > n) continue;
                if (st.find(pair<int, int>(b[0] + pos[i][0], b[1] + pos[i][1])) != st.end()) {
                    t = 1;
                    break;
                }
            }
            if (!t) {
                printf("tie %d %d", a[0], a[1]);
                break;
            }
        }
    }
    return 0;
}