#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
문제 : H * W(H <= 10, W <= 20) 크기의 격자에 문자들이 쓰여 있다. 이때, 이 문자열의 임의의 위치에서
상하좌우대각선으로 직선으로 움직여 만들 수 있는 2자 이상의 문자열 가운데 2회 이상 나타난
가장 긴 문자열을 구한다. 그러한 문자열이 여럿인 경우 사전순으로 가장 빠른 것을 구한다.
직선으로 움직이며 배열의 범위를 벗어나면 환형으로 이어진다. 또한, 처음 시작한 위치로 되돌아오기
전까지만 문자열을 만들 수 있다. 그러한 것이 없다면 0을 출력한다.

해결 방법 : 각 점에서 8개 각 방향에 대해 만들 수 있는 만큼 문자열을 만든다.
문자열을 만들며 각 문자열을 등장 횟수와 함께 해시맵에 저장한다. 이미 해시맵에 있는 경우
등장 횟수를 1 늘리면 된다. 이를 반복한 다음, 2회 이상 나타난 가장 긴 문자열을
해시맵에서 찾아서 출력하면 된다.

주요 알고리즘 : 문자열, 해시맵, 브루트 포스

출처 : Fukuoka 2011 B번
*/

char pat[16][32], vis[16][32];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
unordered_map<string, int> u;

void clearmat(char* s, int h, int w, int ww) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) s[i * ww + j] = 0;
    }
}

int main(void) {
    int h, w, x, y;
    string s;
    while (1) {
        scanf("%d %d", &h, &w);
        if (h == 0) break;
        for (int i = 0; i < h; i++) {
            scanf("%s", pat[i]);
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int d = 0; d < 8; d++) {
                    x = i, y = j;
                    s = "";
                    while (!vis[x][y]) {
                        vis[x][y] = 1;
                        s += pat[x][y];
                        if (s.length() > 1) {
                            if (u.find(s) == u.end()) u.insert(pair<string, int>(s, 1));
                            else u[s]++;
                        }
                        x += dxy[d][0];
                        y += dxy[d][1];
                        if (x < 0) x += h;
                        if (x >= h) x -= h;
                        if (y < 0) y += w;
                        if (y >= w) y -= w;
                    }
                    clearmat((char*)vis, h, w, 32);
                }
            }
        }

        s = "";
        for (auto i : u) {
            if (i.second > 1) {
                if (i.first.length() > s.length()) s = i.first;
                else if (i.first.length() == s.length() && s.compare(i.first) > 0) s = i.first;
            }
        }
        u.clear();
        if (s.length() < 2) printf("0\n");
        else printf("%s\n", s.c_str());
    }
    return 0;
}