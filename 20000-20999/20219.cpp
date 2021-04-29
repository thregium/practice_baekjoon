#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)명의 학생이 두 반으로 나누어져 있다. 같은 반의 학생들은 서로를 싫어하는 경우가 없지만,
다른 반의 학생들중에는 싫어하는 경우가 있다. 그러한 쌍이 M(M <= 200000)개 주어질 때, 두 반을 합친 상태에서
서로 싫어하는 학생이 없으면서 가장 많은 쌍을 만들 때의 쌍의 수를 구한다.

해결 방법 : 문제 설명에서 서로 싫어하는 학생의 쌍을 간선으로 본다면, 이 그래프는 이분 그래프가 된다.
여기서 같은 반의 학생들끼리는 싫어하는 경우가 없으므로 양쪽 반에서 최대 1명을 제외한 나머지는 전부 쌍을 지을 수 있다.
이때, 양쪽 반에서 1명씩 남는 경우에는 양쪽 반의 모든 쌍이 서로를 싫어하는 경우에는 1명씩을 남겨야 한다.
하지만 그 외에는 어떠한 경우에도 가능한 모두에게 쌍을 지어줄 수 있다.

주요 알고리즘 : 그래프 이론, BFS, 이분 그래프

출처 : BAPC 2020P G번
*/

int vis[103000];
int n, m;
vector<int> cnw[103000];
queue<pair<int, int>> q;

int bfs(int x) {
    int a = 0, b = 0, c = 0, d;
    q.push(pair<int, int>(x, 0));
    vis[x] = 2;
    b++;
    while (q.size()) {
        x = q.front().first;
        d = q.front().second;
        q.pop();
        for (int i = 0; i < cnw[x].size(); i++) {
            if (!vis[cnw[x][i]]) {
                q.push(pair<int, int>(cnw[x][i], d + 1));
                if (d & 1) {
                    vis[cnw[x][i]] = 2;
                    b++;
                }
                else {
                    vis[cnw[x][i]] = 1;
                    a++;
                }
            }
            c++;
        }
    }
    if (a + b == n) {
        //모든 학생에 대해 조사한 경우(모두가 관계로 연결된 경우)
        if ((a & b & 1) && (long long)a * b * 2 == c) {
            //양쪽 부분이 모두 홀수이고 양쪽 사이에 모든 간선이 이어진 경우
            return (n - 1) >> 1;
        }
        else return (n >> 1); //가장 많은 쌍을 만들 수 있다.
    }
    else return (n >> 1); //가장 많은 쌍을 만들 수 있다.
}

int main(void) {
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        cnw[a].push_back(b);
        cnw[b].push_back(a);
    }
    printf("%d", bfs(1));
    return 0;
}