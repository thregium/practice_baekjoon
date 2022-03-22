#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <unordered_set>
using namespace std;

/*
���� : 15-��� �����ǿ��� ���ϴ� ���� �ɸ� ���� �� �ִ� �� ���Ѵ�.

�ذ� ��� : ���� �ű�� ��� ��츦 �غ���. ��, �� �������� �ߺ��Ǵ� ���� ���� ó���� �Ͽ�
�ߺ��� �Ͼ�� �ʵ��� ����ȭ�� ����� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, DFS, ����

��ó : VTH 2014 J��
*/

char targ[8], peg[8][16];
int dxy[6][2] = { {0, 1}, {1, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 0} };
int res = 0;
unordered_set<string> vis;

int isvalid(int x, int y, int d) {
    int nx = x + dxy[d][0] * 2, ny = y + dxy[d][1] * 2;
    if (nx < 0 || ny < 0 || ny > nx || nx >= 5) return 0;
    if (peg[nx][ny] != '_') return 0;
    if (peg[x + dxy[d][0]][y + dxy[d][1]] == '_') return 0;
    return 1;
}

void track(int pcnt) {
    char tpeg, tpeg2;
    if (pcnt == 1) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j <= i; j++) {
                if (peg[i][j] == targ[0]) res = 1;
            }
        }
        return;
    }
    string s = "";
    for (int i = 0; i < 5; i++) s += peg[i];
    if (vis.find(s) != vis.end()) return;
    else vis.insert(s);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            if (peg[i][j] == '_') continue;
            for (int d = 0; d < 6; d++) {
                if (isvalid(i, j, d)) {
                    tpeg = peg[i][j];
                    tpeg2 = peg[i + dxy[d][0]][j + dxy[d][1]];
                    peg[i][j] = '_';
                    peg[i + dxy[d][0] * 2][j + dxy[d][1] * 2] = tpeg;
                    peg[i + dxy[d][0]][j + dxy[d][1]] = '_';
                    track(pcnt - 1);
                    if (res) return;
                    peg[i + dxy[d][0] * 2][j + dxy[d][1] * 2] = '_';
                    peg[i + dxy[d][0]][j + dxy[d][1]] = tpeg2;
                    peg[i][j] = tpeg;
                }
            }
        }
    }
}

int main(void) {
    int c;
    while (1) {
        scanf("%s", targ);
        if (targ[0] == '*') break;
        c = 0;
        for (int i = 0; i < 5; i++) {
            scanf("%s", peg[i]);
            for (int j = 0; j <= i; j++) {
                peg[i][j] = peg[i][j * 2];
                if (peg[i][j] != '_') c++;
            }
            peg[i][i + 1] = '\0';
        }
        res = 0;
        track(c);
        printf("%s\n", res ? "Possible" : "Impossible");
        vis.clear();
    }
    return 0;
}