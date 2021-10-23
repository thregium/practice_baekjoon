#include <stdio.h>
#include <set>
#include <map>
using namespace std;

/*
문제 : H * W(H, W <= 10^9) 크기의 배열에 검은 색 픽셀이 N(N <= 100000)개 있다. 이때, 3 * 3 크기의 공간에 검은 색
픽셀이 i(i <= 9)개인 공간의 개수를 각각 구한다.

해결 방법 : H와 W에 비해 N이 작기 때문에 H와 W가 크다면 대부분은 검은 픽셀이 0개가 됨을 알 수 있다.
이를 이용해서, 검은 픽셀 주변 공간들만 색을 확인하도록 한다. 한 픽셀이 검다면 그에 영향을 받는 3 * 3 공간은
주위 3 * 3칸을 중심으로 한 칸들이다. 이 칸들 가운데 범위를 벗어나거나 이미 확인한 공간은 제외하고
다시 해당 칸을 중심으로 3 * 3 칸의 색을 확인한다. 이는 셋을 통해 쉽게 확인할 수 있다.
이를 통해 확인한 3 * 3 공간의 검은 색 픽셀의 수를 확인하고 맵에 이 곳의 좌표와 함께 저장한다.
이를 통해 중복 방문을 예방할 수 있고 픽셀의 수도 쉽게 확인이 가능해진다.
모든 픽셀에 대해 이를 끝내면 맵에 있는 칸들을 꺼내 와서 주위 검은 색 픽셀의 개수에 따라 그러한 공간의 개수를 세 준다.
그 외의 공간((H - 2) * (W - 2))은 전부 0개로 두면 된다.

주요 알고리즘 : 자료구조, 맵, 셋
*/

int pos[103000][2];
long long res[16];
int dxy[9][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {0, 0} };
set<pair<int, int>> black;
map<pair<int, int>, int> cnt;

int isvalid(int h, int w, int x, int y) {
    if (x <= 1 || y <= 1 || x >= h || y >= w) return 0;
    else return 1;
}

int main(void) {
    int h, w, n, c;
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        black.insert(pair<int, int>(pos[i][0], pos[i][1]));
    }
    int fx, fy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            fx = pos[i][0] + dxy[j][0];
            fy = pos[i][1] + dxy[j][1];
            if (!isvalid(h, w, fx, fy)) continue;
            if (cnt.find(pair<int, int>(fx, fy)) != cnt.end()) continue;
            c = 0;
            for (int k = 0; k < 9; k++) {
                fx = pos[i][0] + dxy[j][0] + dxy[k][0];
                fy = pos[i][1] + dxy[j][1] + dxy[k][1];
                if (black.find(pair<int, int>(fx, fy)) != black.end()) c++;
            }
            cnt.insert(pair<pair<int, int>, int>(pair<int, int>(fx, fy), c));
        }
    }

    res[0] = ((long long)h - 2) * (w - 2);
    for (auto i : cnt) {
        res[i.second]++;
        res[0]--;
    }
    for (int i = 0; i <= 9; i++) {
        printf("%lld\n", res[i]);
    }
    return 0;
}