#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 250000)개의 직사각형을 적당히 회전하면서 이으며, 모든 직사각형이 순서대로 너비가 감소하도록 할 때
만들 수 있는 직사각형 높이의 최댓값을 구한다. 항상 그렇게 만들 수 있는 경우만 주어진다.

해결 방법 : 각 직사각형의 길이가 전부 다르다면 큰것부터 항상 정렬하여 너비가 감소하도록 만들 수 있다.
따라서, 직사각형의 길이가 겹치는 경우에 대해서만 신경쓰면 되는데, 이는 그래프 이론을 이용해 해결 가능하다.
각 직사각형의 한 변의 길이가 정점이 되고, 각 직사각형을 이루는 두 변의 길이를 이은 것이 간선이 된다.
각 정점들은 좌표압축을 통해 범위를 줄여준다.

이제 이 간선들의 방향을 정한다. 도착하는 정점을 가로로 둔다면, 모든 정점은 진입 간선이 2개 이하가 되어야 한다.
(너비가 같은 직사각형이 있어서는 안된다.) 그런데, 그렇게 만들 수 있는 경우만 주어지는데 이러한 그래프는 2가지 뿐이다.
하나는 트리이고, 다른 하나는 트리에 하나의 간선이 더 붙은 형태이다.

트리에 간선이 추가된 형태인 경우에는 모든 간선으로 한번씩 진입해야 하므로 모든 정점의 차수에서 1을 뺀 값을
높이로 해주면 되고,
트리인 경우에는 하나의 간선에는 진입하지 않아도 되므로 트리+1인 경우에서 가장 높은 정점의 높이를 더해주면 된다.

주요 알고리즘 : 그래프 이론, DFS

출처 : NCPC 2016 H번
*/

int irons[262144][2], weights[524288][3], ntw[524288], vis[524288];
vector<int> ed[524288];
long long r = 0, edc = 0, vtc = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void dfs1(int x) {
    //연결요소의 정점수와 간선 수를 통해 트리/그래프 여부 확인
    vis[x]++;
    vtc++;
    edc += ed[x].size();
    for (int y : ed[x]) {
        if (vis[y] == 0) {
            dfs1(y);
        }
    }
}

void dfs2(int x) {
    //트리인 경우(가장 높은것에서 출발)
    vis[x]++;
    for (int y : ed[x]) {
        if (vis[y] == 1) {
            r += weights[ntw[x]][1];
            dfs2(y);
        }
    }
}

void dfs3(int x) {
    //트리가 아닌 경우(모든 정점에 대해 진입차수 - 1개를 곱해줌)
    vis[x]++;
    r += weights[ntw[x]][1] * (ed[x].size() - 1);
    for (int y : ed[x]) {
        if (vis[y] == 1) {
            dfs3(y);
        }
    }
}

int main(void) {
    int n, mw = 1;
    //freopen("E:\\PS\\ICPC\\Europe\\NCPC\\2016\\ncpc2016-packages\\tower\\data\\secret\\25.cycle.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &irons[i][0], &irons[i][1]);
        weights[i << 1][0] = (i << 1);
        weights[i << 1][1] = irons[i][0];
        weights[(i << 1) + 1][0] = (i << 1) + 1;
        weights[(i << 1) + 1][1] = irons[i][1];
    }
    qsort(weights, n * 2LL, sizeof(int) * 3, cmp2);
    weights[0][2] = 1;
    ntw[1] = weights[0][0];
    for (int i = 1; i < (n << 1); i++) {
        if (weights[i][1] == weights[i - 1][1]) weights[i][2] = weights[i - 1][2];
        else {
            weights[i][2] = weights[i - 1][2] + 1;
            ntw[weights[i][2]] = weights[i][0];
            mw++;
        }
    }
    qsort(weights, n * 2LL, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        ed[weights[i << 1][2]].push_back(weights[(i << 1) + 1][2]);
        ed[weights[(i << 1) + 1][2]].push_back(weights[i << 1][2]);
    }
    for (int i = mw; i > 0; i--) {
        if (vis[i] == 2) continue;
        edc = 0, vtc = 0;
        dfs1(i);
        if (edc < vtc * 2) {
            dfs2(i);
        }
        else {
            dfs3(i);
        }
    }
    printf("%lld", r);
    return 0;
}