#include <stdio.h>
#define INF 1012345678

/*
문제 : R * C(R, C <= 20) 크기의 slitherlink 퍼즐을 문제에 주어진 전략대로 푼다.
문제에 주어진 전략으로 풀 수 있는 경우만 주어진다.

해결 방법 : 문제에 주어진 전략을 그대로 구현하면 된다.

주요 알고리즘 : 구현

출처 : MidC 2007 C번
*/

char res[128][128];
int dxy1[4][2] = { {2, 0}, {0, 0}, {0, 4}, {2, 4} };
int dxy2[4][2] = { {2, -4}, {-2, -4}, {-2, 4}, {2, 4} };

void drawline(int x, int y, int d, char c) {
    //(x, y)에 주어진 수를 기준으로 선을 긋는다. d = 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽. c: 그을 선의 종류
    if (d & 1) {
        if (c == '-') {
            for (int i = -1; i <= 1; i++) res[x][y - d * 2 + 4 + i] = c;
        }
        else res[x][y - d * 2 + 4] = c;
    }
    else if (c == '-') {
        for (int i = -1; i <= 1; i++) res[x + d - 1][y + i] = c;
    }
    else res[x + d - 1][y] = c;
}

int findline(int x, int y, int h, int w, int d, char c) {
    //(x, y)의 d방향의 선이 c인지 검사한다. d = 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽.
    if (d & 1) {
        if (x >= h || y - d * 2 + 4 >= w || x <= 1 || y - d * 2 + 4 <= 1) return (c == 'x');
        return (res[x][y - d * 2 + 4] == c);
    }
    else {
        if (x + d - 1 >= h || y >= w || x + d - 1 <= 1 || y <= 1) return (c == 'x');
        return (res[x + d - 1][y] == c);
    }
}

int finished(int r, int c) {
    //모든 선의 형태를 확인하였는지 구한다.
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < 4; k++) {
                if (findline(i * 2 + 3, j * 4 + 4, r * 2 + 3, c * 4 + 3, k, ' ')) return 0;
            }
        }
    }
    return 1;
}

void checkasell(int x, int y) {
    //한 칸에서 체크할 수 있는 것들을 체크한다.
    int checked = 0, elimed = 0;
    if (res[x][y] == '0') {
        for (int i = 0; i < 4; i++) drawline(x, y, i, 'x');
    }
    for (int i = 0; i < 4; i++) {
        checked += findline(x, y, INF, INF, i, i & 1 ? '|' : '-');
        elimed += findline(x, y, INF, INF, i, 'x');
    }
    if (checked + elimed == 4) return; //이미 할 수 있는 것들을 종료한 경우
    if (res[x][y] - '0' == checked) {
        //체크 가능한 것들을 모두 체크했다면 나머지는 전부 지움
        for (int i = 0; i < 4; i++) {
            if (!findline(x, y, INF, INF, i, i & 1 ? '|' : '-')) drawline(x, y, i, 'x');
        }
    }
    if ('4' - res[x][y] == elimed) {
        //지울 수 있는 것들을 모두 지웠다면 나머지는 전부 체크함
        for (int i = 0; i < 4; i++) {
            if (!findline(x, y, INF, INF, i, 'x')) drawline(x, y, i, i & 1 ? '|' : '-');
        }
    }
}

void checktwothree(int x, int y, int d) {
    //인접한 2개의 3을 체크한다.
    if (d == 0) {
        if (res[x][y] != '3' || res[x][y + 4] != '3') return;
        drawline(x, y, 3, '|');
        drawline(x, y, 1, '|');
        drawline(x, y + 4, 1, '|');
    }
    else {
        if (res[x][y] != '3' || res[x + 2][y] != '3') return;
        drawline(x, y, 0, '-');
        drawline(x, y, 2, '-');
        drawline(x + 2, y, 2, '-');
    }
}

void checktwobytwo(int x, int y, int h, int w) {
    //2 * 2 영역에서 확인 가능한 것들을 추가한다.
    //3이 대각선으로 인접한 경우
    if (res[x][y] == '3' && res[x + 2][y + 4] == '3') {
        drawline(x, y, 0, '-');
        drawline(x, y, 3, '|');
        drawline(x + 2, y + 4, 1, '|');
        drawline(x + 2, y + 4, 2, '-');
    }
    else if (res[x][y + 4] == '3' && res[x + 2][y] == '3') {
        drawline(x, y + 4, 0, '-');
        drawline(x, y + 4, 1, '|');
        drawline(x + 2, y, 2, '-');
        drawline(x + 2, y, 3, '|');
    }

    int edgechecked = 0, edgeelimed = 0; //한 꼭짓점((X, Y)의 오른쪽 대각선 아래)을 기준으로 상하좌우 선에 대한 체크/제거 여부
    for (int i = 0; i < 4; i++) {
        edgechecked += findline(x + 1, y + 2, h, w, i, i & 1 ? '-' : '|');
        edgeelimed += findline(x + 1, y + 2, h, w, i, 'x');
    }
    if (edgeelimed == 3) {
        //3개가 제거된 경우 나머지 1개도 제거
        for (int i = 0; i < 4; i++) {
            if(!findline(x + 1, y + 2, h, w, i, 'x')) drawline(x + 1, y + 2, i, 'x');
        }
    }
    else if (edgechecked == 1 && edgeelimed == 2) {
        //1개가 체크되고 나머지 중 2개가 제거된 경우 나머지 1개는 체크
        for (int i = 0; i < 4; i++) {
            if (findline(x + 1, y + 2, h, w, i, ' ')) drawline(x + 1, y + 2, i, i & 1 ? '-' : '|');
        }
    }
    else if (edgechecked == 2) {
        //2개가 체크된 경우 나머지는 제거
        for (int i = 0; i < 4; i++) {
            if (findline(x + 1, y + 2, h, w, i, ' ')) drawline(x + 1, y + 2, i, 'x');
        }
    }

    for (int i = 0; i < 4; i++) {
        //가운데 중 2개가 인접하여 체크/제거된 경우 대각선에 3 또는 1이 있다면 그쪽 선을 긋거나 제거한다.
        edgechecked = 0, edgeelimed = 0;
        for (int j = 0; j < 2; j++) {
            edgechecked += findline(x + 1, y + 2, h, w, (i + j) & 3, ((i + j) & 1) ? '-' : '|');
            edgeelimed += findline(x + 1, y + 2, h, w, (i + j) & 3, 'x');
        }
        if (edgeelimed == 2 || (edgechecked == 1 && edgeelimed == 1)) {
            if (res[x + dxy1[i][0]][y + dxy1[i][1]] == '3' ||
                res[x + dxy1[i][0]][y + dxy1[i][1]] == '1') {
                drawline(x + dxy1[i][0], y + dxy1[i][1], edgeelimed == 2 ? i : ((i + 2) & 3),
                    res[x + dxy1[i][0]][y + dxy1[i][1]] == '3' ? ((i & 1) ? '|' : '-') : 'x');
                drawline(x + dxy1[i][0], y + dxy1[i][1], edgeelimed == 2 ? (i + 1) & 3 : ((i + 3) & 3),
                    res[x + dxy1[i][0]][y + dxy1[i][1]] == '3' ? ((i & 1) ? '-' : '|') : 'x');
            }
        }
    }
}

void checkthreebythree(int x, int y, int h, int w) {
    //(X, Y)를 중심으로 주위 3 * 3 영역을 살펴본다.
    int checked = 0, elimed = 0;
    for (int i = 0; i < 4; i++) {
        checked = 0, elimed = 0;
        for (int j = 0; j < 2; j++) {
            checked += findline(x + dxy2[i][0], y + dxy2[i][1], h, w, (i + j) & 3, ((i + j) & 1) ? '|' : '-');
            elimed += findline(x + dxy2[i][0], y + dxy2[i][1], h, w, (i + j) & 3, 'x');
        }
        if (elimed == 2) {
            if (res[x][y] == '3' && res[x + dxy2[(i + 2) & 3][0]][y + dxy2[(i + 2) & 3][1]] == '1') {
                //3과 1이 대각선으로 마주본 경우
                drawline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], i, 'x');
                drawline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], (i + 1) & 3, 'x');
            }
            //2의 대각선 방향으로 2칸이 지워지고, 그 옆 대각선 중 1개가 지워진 경우 다른 한 선을 긋는다.
            if (res[x][y] == '2' && findline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], h, w, (i + 1) & 3, 'x')
                && findline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], h, w, (i + 2) & 3, ' '))
                drawline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], (i + 2) & 3, (i & 1) ? '|' : '-');
            if (res[x][y] == '2' && findline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], h, w, (i + 2) & 3, 'x')
                && findline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], h, w, (i + 1) & 3, ' '))
                drawline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], (i + 1) & 3, (i & 1) ? '-' : '|');
            if (res[x][y] == '2' && findline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], h, w, (i + 3) & 3, 'x')
                && findline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], h, w, i, ' '))
                drawline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], i, (i & 1) ? '|' : '-');
            if (res[x][y] == '2' && findline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], h, w, i, 'x')
                && findline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], h, w, (i + 3) & 3, ' '))
                drawline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], (i + 3) & 3, (i & 1) ? '-' : '|');
        }
        
        else if (checked == 1 && elimed == 1) {
            //2의 대각선 방향으로 1칸이 채워지고 1칸이 지워진 상태에서 그 옆 대각선 중 1개가 지워진 경우 다른 한 선을 긋는다.
            if (res[x][y] == '2' && findline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], h, w, (i + 2) & 3, 'x')
                && findline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], h, w, (i + 1) & 3, ' '))
                drawline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], (i + 3) & 3, (i & 1) ? '-' : '|');
            if (res[x][y] == '2' && findline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], h, w, (i + 3) & 3, 'x')
                && findline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], h, w, (i + 2) & 3, ' '))
                drawline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], (i + 2) & 3, (i & 1) ? '|' : '-');
        }
        
    }
}

int main(void) {
    int r, c, x, cnt;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2007\\mcpc2007\\slink\\slink.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2007\\mcpc2007\\slink\\slink_t.out", "w", stdout);
    for (int tt = 1;; tt++) {
        scanf("%d %d", &r, &c);
        if (r == 0) break;
        cnt = 0;
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                if (i >= r * 2 + 5 || j >= c * 4 + 5) res[i][j] = '\0';
                else if (i == 0 || j == 0 || i == r * 2 + 4 || j == c * 4 + 4) res[i][j] = '#';
                else res[i][j] = ' ';
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &x);
                res[i * 2 + 3][j * 4 + 4] = '0' + x;
            }
        }

        cnt = 0;
        while (!finished(r, c)) {
            //종료시까지 반복
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    checkasell(i * 2 + 3, j * 4 + 4);
                    if (j < c - 1) checktwothree(i * 2 + 3, j * 4 + 4, 0);
                    if (i < r - 1) checktwothree(i * 2 + 3, j * 4 + 4, 1);
                    checkthreebythree(i * 2 + 3, j * 4 + 4, r * 2 + 3, c * 4 + 3);
                }
            }
            for (int i = 0; i <= r; i++) {
                for (int j = 0; j <= c; j++) {
                    //2 * 2는 바깥쪽까지 확인해야 함
                    checktwobytwo(i * 2 + 1, j * 4, r * 2 + 3, c * 4 + 3);
                }
            }
            cnt++;
            //if (cnt == 100) break;
        }
        for (int i = 1; i <= r * 2 + 3; i++) {
            for (int j = 1; j <= c * 4 + 3; j++) {
                //지운 선들을 제거하고 선들을 말끔히 이어준다.
                if (res[i][j] == 'x') res[i][j] = ' ';
                else if (res[i][j - 1] == '-' && res[i][j + 1] == '-') res[i][j] = '-';
                else if (res[i - 1][j] == '|' && res[i + 1][j] == '|') res[i][j] = '|';
                else if (res[i][j] == ' ' && (res[i][j - 1] == '-' || res[i][j + 1] == '-'
                    || res[i - 1][j] == '|' && res[i + 1][j] == '|')) res[i][j] = '+';
            }
        }

        printf("%d\n", tt);
        for (int i = 0; i < r * 2 + 5; i++) {
            printf("%s\n", res[i]);
        }
    }
    return 0;
}