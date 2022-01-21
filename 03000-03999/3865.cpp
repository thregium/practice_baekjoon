#include <stdio.h>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
문제 : N(N <= 100)개의 학회가 있고, 각 학회에 속한 학회원들이 주어진다. 학회원은 사람일 수도 있고,
다른 학회일 수도 있다. 이때, 첫 번째 학회에 속한 사람의 수를 구한다. 학회원과 사람의 이름은
15자 이하의 소문자로 이루어진 문자열이며, 학회가 아니라면 사람이다.
또한, 하나의 학회는 최대 10개의 학회원을 가지며, 순환적인 포함관계를 갖지 않는다.

해결 방법 : 먼저 학회원들의 관계를 파싱을 통해 구한다. 각 학회마다 해당 학회에 속하는 학회원들을
해시맵과 해시셋을 통해 연결시켜둔다. 그 다음, 첫 번째 학회에서 속하는 학회원들을 재귀적으로 확인해 나가며
그 학회의 학회원들을 구한다. 학회가 아닌 학회원(사람)을 만날 때 마다 그 개수를 센 다음,
그 값을 출력하면 된다. 방문 처리를 해줘야 한다.

주요 알고리즘 : 문자열, 파싱, 해시맵, 해시셋, 플러드필

출처 : Tokyo 2010 A번
*/

char buff[1024];
unordered_set<string> vis;
unordered_map<string, unordered_set<string>> u;

int dfs(string s) {
    int r = 0;
    vis.insert(s);
    if (u.find(s) == u.end()) return 1;
    for (string i : u[s]) {
        if (vis.find(i) == vis.end()) r += dfs(i);
    }
    return r;
}

int main(void) {
    int n, p;
    string f, s, t;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        f = "";
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            s = "", t = "", p = 0;
            for (int j = 0; buff[j] != '.'; j++) {
                if (buff[j] == ':') {
                    p = 1;
                    u.insert(make_pair(s, unordered_set<string>()));
                    if (i == 0) f = s;
                    continue;
                }
                else if (buff[j] == ',') {
                    u[s].insert(t);
                    t = "";
                    continue;
                }
                if (p == 0) s += buff[j];
                else t += buff[j];
            }
            u[s].insert(t);
        }

        printf("%d\n", dfs(f));
        vis.clear();
        u.clear();
    }
    return 0;
}