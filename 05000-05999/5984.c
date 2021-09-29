#include <stdio.h>

/*
문제 : N(N <= 250)명의 사람들이 원형으로 앉아있다. 1번 사람부터 시작해서 자신의 번호만큼 시계방향으로 이동하고
그곳에 앉아있는 사람이 다시 자신의 번호만큼 이동하는 것을 반복하여 어떤 자리에 있는 사람이 2번 이동해야 할 때 까지 반복한다.
이때, 2번 이동해야 하는 사람의 자리로 온 마지막 사람은 누구인지 구한다.

해결 방법 : 각 사람이 있는 위치의 번호를 보면 해당 위치에서 출발한 사람이 가야 할 번호는 해당 번호의 2배인 곳이다.
만약 그러한 곳이 없다면 N만큼을 뺀 번호가 된다. 이를 통해 간단히 번호를 찾을 수 있으므로 나머지는 이미 이동했는지 여부를
판정하는 배열에 저장해서 이미 이동한 사람이 나오면 그 직전의 사람 번호를 출력하면 끝난다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : USACO 2011O B1번
*/

int vis[256];

int main(void) {
    int n, x = 1, y;
    scanf("%d", &n);
    while (1) {
        vis[x] = 1;
        y = (x * 2 - 1) % n + 1;
        if (vis[y]) {
            printf("%d", x);
            break;
        }
        else x = y;
    }
    return 0;
}