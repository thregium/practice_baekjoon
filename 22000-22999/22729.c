#include <stdio.h>

/*
문제 : H * W(H, W <= 50) 크기의 격자에 '.'들과 알파벳들이 있다. 각 알파벳들이 모두 직사각형 모양으로
쌓여있는 형태일 수 있는 지 구한다. '.'들은 빈 칸을 의미한다.

해결 방법 : 우선 각 알파벳들이 직사각형 형태인지부터 확인한다. 가장 X좌표와 Y좌표 범위가 넓은 범위를 구하고
그 안에 '.'이 있는 지 확인한다. '.'이 있다면 직사각형이 아니다. '.'이 없다면 그 범위 위에 있는
다른 알파벳들을 원래 알파벳과 간선으로 연결한다. 모든 간선을 연결한 다음, 위상 정렬을 시도한다.
만약 위상 정렬이 불가능한 경우(사이클이 나오는 경우)가 있다면 직사각형이 아닌 것이 있어야
쌓여있는 형태이므로 조건을 만족할 수 없다. 그 외에는 조건을 만족 가능하다.

주요 알고리즘 : 그래프 이론, 위상 정렬

출처 : JAG 2006D C번
*/

char s[64][64];
int ed[32][32], vis[32], cnt[32];

int main(void) {
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2006D\\judge-data\\C1", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2006D\\judge-data\\C1_t.out", "w", stdout);
    int t, h, w, xl, xh, yl, yh, r, tmp;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) ed[i][j] = 0;
            vis[i] = 0;
        }

        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            scanf("%s", s[i]);
        }
        r = 0;
        for (char c = 'A'; c <= 'Z'; c++) {
            xl = 99, xh = -1, yl = 99, yh = -1;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (s[i][j] == c) {
                        if (i < xl) xl = i;
                        if (i > xh) xh = i;
                        if (j < yl) yl = j;
                        if (j > yh) yh = j;
                    }
                }
            }

            for (int i = xl; i <= xh; i++) {
                for (int j = yl; j <= yh; j++) {
                    if (s[i][j] == '.') r = 1;
                    else if (s[i][j] != c) ed[c - 'A'][s[i][j] - 'A'] = 1;
                }
            }
        }
        if (r) {
            printf("SUSPICIOUS\n");
            continue;
        }

        for (int i = 0; i < 26; i++) {
            cnt[i] = 0;
            for (int j = 0; j < 26; j++) cnt[i] += ed[j][i];
        }
        while (1) {
            tmp = 0;
            for (int i = 0; i < 26; i++) {
                if (!vis[i] && cnt[i] == 0) {
                    vis[i] = 1;
                    for (int j = 0; j < 26; j++) {
                        cnt[j] -= ed[i][j];
                        tmp += ed[i][j];
                    }
                }
            }
            if (tmp == 0) break;
        }
        for (int i = 0; i < 26; i++) r |= (!vis[i]);
        printf("%s\n", r ? "SUSPICIOUS" : "SAFE");
    }
    return 0;
}
