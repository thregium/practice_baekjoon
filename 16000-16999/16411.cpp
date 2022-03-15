#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
문제 : 8글자의 A부터 F까지의 알파벳 가운데 하나로 이루어진 문자열이 2개 주어진다. 문제에 주어진 연산을
사용하여 앞 문자열을 뒤 문자열로 바꿀 수 있는 지 확인하고, 그러한 경우 바꾸기 위해 필요한 연산의
최소 횟수를 구한다.

해결 방법 : 가능한 문자열의 종류가 최대 약 160만개로 전부 확인 가능한 양이기 때문에
BFS를 통해 각 연산을 해보며 해시맵에 문자열 별로 필요한 연산의 횟수를 저장하고,
바꿀 수 있는 경우 연산 횟수를, 없는 경우 -1을 출력하면 된다.
구현량이 많으므로 구현에 주의한다.

주요 알고리즘 : 그래프 이론, BFS, 문자열, 해시맵, 구현

출처 : MidC 2018 G번 // SEUSA 2018D1 D번 / 2018D2 D번
*/

char buffs[16], bufft[16];
unordered_map<string, int> dist;
queue<string> q;

char rot(char c) {
    if (c == 'F') return 'A';
    else return c + 1;
}

void bfs(string s) {
    int d;
    string t;
    q.push(s);
    dist.insert(make_pair(s, 0));
    while (q.size()) {
        s = q.front();
        q.pop();
        d = dist[s];
        for (int i = 0; i < 8; i++) {
            t = s;
            if (s[i] == 'A') {
                if (i > 0) t[i - 1] = rot(s[i - 1]);
                if (i < 7) t[i + 1] = rot(s[i + 1]);
            }
            else if (s[i] == 'B') {
                if (0 < i && i < 7) t[i + 1] = s[i - 1];
            }
            else if (s[i] == 'C') {
                t[7 - i] = rot(s[7 - i]);
            }
            else if (s[i] == 'D') {
                if (i < 4) {
                    for (int j = 0; j < i; j++) t[j] = rot(s[j]);
                }
                else {
                    for (int j = i + 1; j < 8; j++) t[j] = rot(s[j]);
                }
            }
            else if (s[i] == 'E') {
                if (0 < i && i < 4) {
                    t[0] = rot(s[0]);
                    t[i << 1] = rot(s[i << 1]);
                }
                else if (4 <= i && i < 7) {
                    t[7] = rot(s[7]);
                    t[(i << 1) - 7] = rot(s[(i << 1) - 7]);
                }
            }
            else if (s[i] == 'F') {
                if (i & 1) t[i >> 1] = rot(s[i >> 1]);
                else t[(i >> 1) + 4] = rot(s[(i >> 1) + 4]);
            }

            if (dist.find(t) == dist.end()) {
                dist.insert(make_pair(t, d + 1));
                q.push(t);
            }
        }
    }
}

int main(void) {
    string s, t;
    scanf("%s%s", buffs, bufft);
    s.assign(buffs);
    t.assign(bufft);
    bfs(s);
    if (dist.find(t) == dist.end()) printf("-1");
    else printf("%d", dist[t]);
    return 0;
}