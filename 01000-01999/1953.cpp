#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 100)명의 사람들이 싫어하는 관계가 주어질 때, 싫어하는 사람끼리 같은 팀으로 오지 않도록
2개의 팀으로 나누는 방법을 출력한다. 나누는 방법은 반드시 존재한다.

해결 방법 : 주어진 그래프는 반드시 이분 그래프 형태이다. 따라서, 이분 그래프의 컬러링을 지정하면
그것을 각 사람이 속한 팀으로 하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 이분 그래프
*/

int color[128], ccnt[2];
vector<int> ed[128];

void dfs(int x, int c) {
    color[x] = c;
    for (int i : ed[x]) {
        if (color[i] < 0) dfs(i, !c);
    }
}

int main(void) {
    int n, m, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            ed[i].push_back(x);
            ed[x].push_back(i);
        }
        color[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] < 0) dfs(i, 0);
    }
    for (int i = 1; i <= n; i++) ccnt[color[i]]++;
    printf("%d\n", ccnt[0]);
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) printf("%d ", i);
    }
    printf("\n%d\n", ccnt[1]);
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) printf("%d ", i);
    }
    return 0;
}