#include <stdio.h>

/*
문제 : M * N 크기 격자에서 칠해진 칸들을 2개의 겹치지 않는 직사각형으로 나눌 수 있는지 구하고,
가능하다면 나누는 방법을 출력한다.

해결 방법 : 먼저 세로 방향으로 최대한 넓게 한 다음 가로 방향으로 넓게 하는 방식으로 직사각형을 나누어 본다.
탐색 순서도 세로->가로 순으로 해야 한다. 만약 직사각형이 없거나 1칸만 있는 경우에는 나눌 수 없다.
직사각형 하나지만 2칸 이상이라면 세로든 가로든 2칸 이상인 방향을 나누면 된다.
직사각형 2개인 경우에는 구한 대로 출력하면 되고, 3개 이상이라면 다시 가로->세로 순으로 나누어본다.
탐색 순서도 가로->세로로 바꾸어야 한다. 여기서 직사각형 2개로 나누어진다면 나누는 것이 가능하고,
여기서도 3개 이상이라면 나누는 것이 불가능하다.

주요 알고리즘 : 그리디 알고리즘, 케이스 워크, 구성적

출처 : ROI 2004H H번
*/

char pict[256][256];
int rect[256][256];

void printrect(int m, int n) {
    //직사각형 출력
    printf("YES\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rect[i][j] == 0) printf(".");
            else printf("%c", rect[i][j] + 'a' - 1);
        }
        printf("\n");
    }
}

int main(void) {
    int m, n, cnt = 0, startx = 0, starty = 0, sizex = 0, sizey = 0, tmp;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s", pict[i]);
    }
    //세로 -> 가로
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pict[i][j] != '#') continue;
            if (rect[i][j]) continue;
            sizex = 0, sizey = 0, cnt++;
            startx = i, starty = j;
            for (int ii = i; ii < m && pict[ii][j] == '#' && rect[ii][j] == 0; ii++) {
                sizex++; //높이 확인
            }
            for (int jj = j; jj < n; jj++) {
                tmp = 0;
                for (int ii = i; ii < i + sizex; ii++) {
                    if (pict[ii][jj] != '#' || rect[ii][jj] != 0) tmp = 1;
                }
                if (tmp) break;
                sizey++; //너비 확인
            }
            for (int ii = i; ii < i + sizex; ii++) {
                for (int jj = j; jj < j + sizey; jj++) {
                    rect[ii][jj] = cnt;
                }
            }
        }
    }
    if (cnt == 0) {
        printf("NO"); //직사각형이 없을 때
        return 0;
    }
    else if (cnt == 1) {
        //1개인 경우
        if (sizex > 1) {
            for (int i = starty; i < starty + sizey; i++) rect[startx][i] = 2;
            printrect(m, n);
        }
        else if (sizey > 1) {
            for (int i = startx; i < startx + sizex; i++) rect[i][starty] = 2;
            printrect(m, n);
        }
        else printf("NO");
        return 0;
    }
    else if (cnt == 2) {
        printrect(m, n); //2개라면 그대로 출력
        return 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) rect[i][j] = 0; //직사각형 초기화
    }
    cnt = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            //가로 -> 세로
            if (pict[i][j] != '#') continue;
            if (rect[i][j]) continue;
            sizex = 0, sizey = 0, cnt++;
            for (int jj = j; jj < n && pict[i][jj] == '#' && rect[i][jj] == 0; jj++) {
                sizey++; //너비 확인
            }
            for (int ii = i; ii < n; ii++) {
                tmp = 0;
                for (int jj = j; jj < j + sizey; jj++) {
                    if (pict[ii][jj] != '#' || rect[ii][jj] != 0) tmp = 1;
                }
                if (tmp) break;
                sizex++; //높이 확인
            }
            for (int ii = i; ii < i + sizex; ii++) {
                for (int jj = j; jj < j + sizey; jj++) {
                    rect[ii][jj] = cnt;
                }
            }
        }
    }
    if (cnt > 2) printf("NO");
    else printrect(m, n);
    return 0;
}