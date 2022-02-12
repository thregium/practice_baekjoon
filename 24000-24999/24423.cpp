#include <stdio.h>
#include <map>
using namespace std;

/*
문제 : H * W(H, W <= 10^9) 크기의 칸이 있고, 딸기 N개가 이 범위의 칸들 가운데 각각 있다.
각 딸기가 있는 칸이 주어지면, 이 칸들 가운데 3 * 3 범위에서 딸기가 가장 많은 곳의 딸기 개수를 구한다.
딸기는 같은 칸에 여러 개 있을 수 있다.

해결 방법 : 먼저 맵에 딸기가 있는 칸에 대해 딸기의 개수를 저장한다. 
그리고 각 딸기가 있는 칸마다 그 주변 3 * 3 범위에 대해 해당 칸을 중심으로 하여 딸기 개수를 센 다음,
그 중 가장 많은 것을 고르면 된다.

주요 알고리즘 : 자료 구조, 맵

출처 : JOIG 2022 4번
*/

int pos[65536][2];
map<pair<int, int>, int> m;

int main(void) {
    int h, w, n, x, y, c, r = 0;
    scanf("%d %d%d", &h, &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        if (m.find(make_pair(pos[i][0], pos[i][1])) == m.end()) {
            m.insert(make_pair(make_pair(pos[i][0], pos[i][1]), 1));
        }
        else m[make_pair(pos[i][0], pos[i][1])]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                x = pos[i][0] + j, y = pos[i][1] + k;
                if (x + j < 1 || y + k < 1 || x + j > h || y + k > w) continue;
                c = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (m.find(make_pair(x + dx, y + dy)) != m.end()) {
                            c += m[make_pair(x + dx, y + dy)];
                        }
                    }
                }
                if (c > r) r = c;
            }
        }
    }
    printf("%d", r);
    return 0;
}