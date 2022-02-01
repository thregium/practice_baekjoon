#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
문제 : K(K <= 50000)개의 3차원 공간상에 있는 선분의 양끝점 좌표(<= 1000, 자연수)가 주어질 때,
선분의 끝점을 연결하여 사이클이 나오는 지 여부와
2차원상에 사영했을 때 그러한 사이클이 나오는 지 여부를 각각 구한다.

해결 방법 : 각 선분의 끝점들을 정점, 그 사이 선분을 간선으로 보고 2차원과 3차원의 그래프를 만든다.
두 그래프의 사이클 여부를 플러드필을 통해 확인하면 된다.
2차원상에 사영하는 경우 같은 점이 나오는 경우가 있음에 유의한다. 또한, 좌표의 범위상
각 정점은 해시맵, 해시셋으로 관리하는 것이 좋다.

주요 알고리즘 : 그래프 이론, 플러드필, 해시셋, 해시맵

출처 : SWERC 2016 K번
*/

unordered_map<int, unordered_set<int>> edt;
unordered_map<int, unordered_set<int>> edf;
unordered_set<int> vist, visf;
int r1 = 0, r2 = 0;

void dfs1(int x, int y) {
    if (vist.find(x) != vist.end()) {
        r1 = 1;
        return;
    }
    else vist.insert(x);
    for (int i : edt[x]) {
        if (i == y) continue;
        dfs1(i, x);
    }
}

void dfs2(int x, int y) {
    if (visf.find(x) != visf.end()) {
        r2 = 1;
        return;
    }
    else visf.insert(x);
    for (int i : edf[x]) {
        if (i == y) continue;
        dfs2(i, x);
    }
}

int main(void) {
    int k, x1, y1, z1, x2, y2, z2;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
        if (edt.find((x1 << 20) + (y1 << 10) + z1) == edt.end()) {
            edt.insert(make_pair((x1 << 20) + (y1 << 10) + z1, unordered_set<int>()));
        }
        edt[(x1 << 20) + (y1 << 10) + z1].insert((x2 << 20) + (y2 << 10) + z2);
        if (edt.find((x2 << 20) + (y2 << 10) + z2) == edt.end()) {
            edt.insert(make_pair((x2 << 20) + (y2 << 10) + z2, unordered_set<int>()));
        }
        edt[(x2 << 20) + (y2 << 10) + z2].insert((x1 << 20) + (y1 << 10) + z1);
        if (edf.find((x1 << 10) + y1) == edf.end()) {
            edf.insert(make_pair((x1 << 10) + y1, unordered_set<int>()));
        }
        if ((x1 << 10) + y1 != (x2 << 10) + y2) edf[(x1 << 10) + y1].insert((x2 << 10) + y2);
        if (edf.find((x2 << 10) + y2) == edf.end()) {
            edf.insert(make_pair((x2 << 10) + y2, unordered_set<int>()));
        }
        if ((x2 << 10) + y2 != (x1 << 10) + y1) edf[(x2 << 10) + y2].insert((x1 << 10) + y1);
    }

    for (auto &i : edt) {
        if(vist.find(i.first) == vist.end()) dfs1(i.first, -1);
    }
    for (auto& i : edf) {
        if (visf.find(i.first) == visf.end()) dfs2(i.first, -1);
    }
    printf("%srue closed chains\n", r1 ? "T" : "No t");
    printf("%sloor closed chains", r2 ? "F" : "No f");
    return 0;
}