#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
문제 : N(N <= 10)가지 규칙에 따라 문자열을 바꾸어 나갈 때, 문자열 c를 d로 바꾸기 위해
필요한 최소 변경 횟수를 구한다. 각 규칙은 부분 문자열 a를 b로 바꾸는 형태로, 일부가 겹치는 경우
겹치지 않는 가장 앞 부분 문자열 a를 다음에 바꿀 위치로 한다. a의 길이는 b보다 짧으며,
모든 문자열은 10자 이내다. d로 바꿀 수 없다면 -1을 출력한다.

해결 방법 : BFS를 통해 처음 문자열에서 규칙들을 통해 만들 수 있는 모든 문자열들을
만들어 본다. 각 문자열마다 각 규칙에 대해 바뀌는 문자열을 만든 다음, 이미 방문했는 지 여부를 확인한다.
방문하지 않았다면 해당 문자열까지의 거리를 1 늘리고 큐에 넣는다.
바뀌는 문자열은 문자열의 길이가 짧으므로 나이브하게 구하면 된다.
모든 문자열을 확인했으면, d를 방문했는 지 확인하고 방문했다면 거리를, 방문하지 않았다면 -1을 출력한다.

주요 알고리즘 : 그래프 이론, BFS, 문자열

출처 : Tokyo 2009 B번
*/

char rule[16][2][16], buff[16], res[128], goal[16];
queue<string> q;
unordered_map<string, int> dist;

void bfs(string s, int n) {
    int alen, t, d;
    string r;
    q.push(s);
    dist.insert(pair<string, int>(s, 0));
    while (q.size()) {
        s = q.front();
        d = dist[s];
        q.pop();
        for (int i = 0; i < n; i++) {
            strcpy(buff, s.c_str());
            alen = strlen(rule[i][0]);
            memset(res, 0, 128);
            for (int j = 0; buff[j]; j++) {
                t = 1;
                for (int k = 0; k < alen; k++) {
                    if (buff[j + k] != rule[i][0][k]) {
                        t = 0;
                        break;
                    }
                }
                if (t) {
                    strcat(res, rule[i][1]);
                    j += alen - 1;
                }
                else res[strlen(res)] = buff[j];
            }
            if (strlen(res) > 10) continue;

            r.assign(res);
            if (dist.find(r) == dist.end()) {
                q.push(r);
                dist.insert(pair<string, int>(r, d + 1));
            }
        }
    }
}

int main(void) {
    int n;
    string s;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s %s", rule[i][0], rule[i][1]);
        }
        scanf("%s", buff);
        scanf("%s", goal);
        s.assign(buff);
        bfs(s, n);
        s.assign(goal);
        if (dist.find(s) == dist.end()) printf("-1\n");
        else printf("%d\n", dist[s]);
        
        dist.clear();
    }
    return 0;
}