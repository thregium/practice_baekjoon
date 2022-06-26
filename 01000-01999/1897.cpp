#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 1000)개의 소문자로 이루어진 80자 이하의 단어들이 주어진다.
처음 주어진 단어에서 한 글자씩 끼워넣어가며 만들 수 있는 가장 긴 단어를 구한다.

해결 방법 : 모든 문자열 쌍에 대해 그리디하게 확인하면서 이전 글자에 한 글자를 추가한 쌍을 확인하고,
그 쌍을 간선으로 연결한다. 연결이 끝나면 시작점을 찾고 거기서 플러드필을 한 후,
방문한 적 있는 것 가운데 가장 긴 것을 구하면 된다.

주요 알고리즘 : 문자열, 그래프 이론, 플러드필, 그리디 알고리즘

출처 : USACO 2003F B3번
*/

char vis[1024];
char stt[96], res[96];
char word[1024][96];
vector<int> ed[1024];

void dfs(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (!vis[i]) dfs(i);
    }
}

int main(void) {
    int n, pos, rlen = 0;
    scanf("%d %s", &n, stt);
    for (int i = 0; i < n; i++) {
        scanf("%s", word[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strlen(word[i]) + 1 != strlen(word[j])) continue;
            pos = 0;
            for (int jj = 0; word[j][jj]; jj++) {
                if (word[j][jj] == word[i][pos]) pos++;
            }
            if (word[i][pos] == '\0') ed[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!strcmp(stt, word[i])) dfs(i);
    }
    for (int i = 0; i < n; i++) {
        if (vis[i] && strlen(word[i]) > rlen) {
            rlen = strlen(word[i]);
            strcpy(res, word[i]);
        }
    }
    printf("%s", res);
    return 0;
}