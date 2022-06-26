#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
문제 : 

해결 방법 : 

주요 알고리즘 : DP, 해시맵, 해시셋

출처 : NAC 2022 J번
*/

char s[16];
int line[8][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6} };
vector<string> stk;
unordered_map<string, pair<int, int>> wins;
unordered_set<string> vis;

void track(string s, int turn) {
    if (vis.find(s) != vis.end()) return;
    else vis.insert(s);
    stk.push_back(s);
    int fin = 0;
    for (int i = 0; i < 8; i++) {
        if (s[line[i][0]] != '.' && s[line[i][0]] == s[line[i][1]] && s[line[i][0]] == s[line[i][2]]) {
            if (s[line[i][0]] == 'X') fin = 1;
            else fin = 2;
        }
    }
    if (fin) {
        wins.insert({ s, {fin == 1, fin == 2} });
        return;
    }

    string t = s;
    for (int i = 0; i < 9; i++) {
        if (s[i] == '.') {
            t[i] = ((turn & 1) ? 'O' : 'X');
            track(t, turn + 1);
            wins[s].first += wins[t].first;
            wins[s].second += wins[t].second;
            t[i] = '.';
        }
    }
    stk.pop_back();
}

int main(void) {
    int t, ocnt, xcnt, resx, reso;
    track(".........", 0);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        if (wins.find(s) != wins.end()) printf("%d %d\n", wins[s].first, wins[s].second);
        else printf("-1 -1\n");
    }
    return 0;
}