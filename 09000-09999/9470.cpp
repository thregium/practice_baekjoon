#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : M(M <= 1000)개의 정점으로 이루어진 그래프에서 strahler 순서를 구한다. 전체 그래프의 순서는
M번 정점의 순서와 같다.

해결 방법 : 위상 정렬을 이용한다. 진입 차수가 0이 되는 시점에서 이전 정점들의 strahler 순서를 통해 그 정점의
순서를 구한다. 모든 전점의 순서를 확인했으면 M번 정점의 strahler 순서를 출력하면 된다.

주요 알고리즘 : 그래프 이론, 위상 정렬

출처 : GNY 2013 C번
*/

int ins[1024], sth[1024];
vector<int> ed[1024], edr[1024];
queue<int> q;

int main(void) {
    int t, k, m, p, a, b, c;
    //freopen("E:\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2013\\c.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &k, &m, &p);
        for (int i = 0; i < p; i++) {
            scanf("%d %d", &a, &b);
            ed[a].push_back(b);
            edr[b].push_back(a);
            ins[b]++;
        }
        for (int i = 1; i <= m; i++) {
            if (ins[i] == 0) {
                q.push(i);
                sth[i] = 1;
            }
        }
        while (q.size()) {
            a = q.front();
            q.pop();
            for (int i : ed[a]) {
                ins[i]--;
                if (ins[i] == 0) {
                    b = -1, c = 0;
                    for (int j : edr[i]) {
                        if (sth[j] > b) {
                            b = sth[j];
                            c = 1;
                        }
                        else if (sth[j] == b) c++;
                    }
                    if (c <= 0) return 1;
                    else if (c == 1) sth[i] = b;
                    else sth[i] = b + 1;
                    q.push(i);
                }
            }
        }
        printf("%d %d\n", k, sth[m]);

        for (int i = 0; i <= m; i++) {
            sth[i] = 0;
            ins[i] = 0;
            ed[i].clear();
            edr[i].clear();
        }
    }
    return 0;
}