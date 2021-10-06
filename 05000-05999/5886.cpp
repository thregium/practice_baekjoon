#include <stdio.h>
#include <string.h>
#include <queue>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
문제 : 격자판에 3개의 조각이 있다. 세 조각들을 움직여서 세 조각을 분리할 수 있는지 구한다.
세 조각의 좌표는 X와 Y좌표 모두 0 이상 9 이하의 정수이다. 세 조각이 분리된 것은 각 조각을 둘러싸는 직사각형들이
서로 겹치지 않을 때이다.

해결 방법 : 첫 번째 조각은 가만히 두고 다른 조각들의 상대적인 위치를 처음에 대비해 움직여가며 각 경우들을 확인한다.
다른 두 조각의 X와 Y좌표 차이를 변수로 두고 플러드필을 하면 된다. 각 조각들을 둘러싸는 직사각형이 겹치지 않는지는
좌표의 최댓값과 최솟값을 비교하는 방식으로 구할 수 있다.
속도를 빠르게 하기 위해 답이 나오면 바로 출력하는 것이 좋다. 음수 처리와 블록의 범위에 유의한다.

주요 알고리즘 : 구현, 플러드필, 브루트 포스, 기하학 등

출처 : USACO 2012O B4번
*/

int dist[25][25][25][25], piece[3][128][2];
char vis[25][25][25][25], chk[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n1, n2, n3, axl = INF, axh = -INF, ayl = INF, ayh = -INF, bxl = INF, bxh = -INF, byl = INF, byh = -INF,
cxl = INF, cxh = -INF, cyl = INF, cyh = -INF; //각 조각의 좌표별 최솟값, 최댓값
queue<tuple<int, int, int, int>> q;

int boxcheck(int bx, int by, int cx, int cy) {
    //세 직사각형이 겹치지 않는지 확인한다. 겹치지 않는다면 1을 반환하고 겹친다면 0을 반환한다.
    if ((bxl + bx <= axh && bxh + bx >= axl) && (byl + by <= ayh && byh + by >= ayl)) return 0;
    if ((cxl + cx <= axh && cxh + cx >= axl) && (cyl + cy <= ayh && cyh + cy >= ayl)) return 0;
    if ((bxl + bx <= cxh + cx && bxh + bx >= cxl + cx) && (byl + by <= cyh + cy && byh + by >= cyl + cy)) return 0;
    return 1;
}

int bfs(int bx, int by, int cx, int cy) {
    //BFS를 통해 퍼즐을 움직이며 분리가 가능한지 확인한다.
    int d = 0, valid;
    vis[bx][by][cx][cy] = 1;
    q.push(make_tuple(bx, by, cx, cy));
    while (q.size()) {
        bx = get<0>(q.front());
        by = get<1>(q.front());
        cx = get<2>(q.front());
        cy = get<3>(q.front());
        d = dist[bx][by][cx][cy];
        q.pop();
        for (int i = 0; i < 12; i++) {
            if (i == 0) bx--;
            else if (i == 1) bx++;
            else if (i == 2) by--;
            else if (i == 3) by++;
            else if (i == 4) cx--;
            else if (i == 5) cx++;
            else if (i == 6) cy--;
            else if (i == 7) cy++;
            else if (i == 8) {
                bx--;
                cx--;
            }
            else if (i == 9) {
                bx++;
                cx++;
            }
            else if (i == 10) {
                by--;
                cy--;
            }
            else if (i == 11) {
                by++;
                cy++;
            }

            if (bx > 0 && bx < 24 && by > 0 && by < 24 && cx > 0 && cx < 24 && cy > 0 && cy < 24 && !vis[bx][by][cx][cy]) {
                memset(chk, 0, 4096);
                valid = 1;
                for (int j = 0; j < n1; j++) chk[piece[0][j][0]][piece[0][j][1]] = 1;
                for (int j = 0; j < n2; j++) {
                    if (chk[piece[1][j][0] + bx][piece[1][j][1] + by]) {
                        valid = 0;
                        break;
                    }
                    chk[piece[1][j][0] + bx][piece[1][j][1] + by] = 2;
                }
                for (int j = 0; j < n3; j++) {
                    if (chk[piece[2][j][0] + cx][piece[2][j][1] + cy]) {
                        valid = 0;
                        break;
                    }
                    chk[piece[2][j][0] + cx][piece[2][j][1] + cy] = 3;
                }
                
                if(valid) {
                    if (boxcheck(bx, by, cx, cy)) {
                        return 1;
                    }
                    q.push(make_tuple(bx, by, cx, cy));
                    vis[bx][by][cx][cy] = 1;
                    dist[bx][by][cx][cy] = d + 1;
                }
            }

            if (i == 0) bx++;
            else if (i == 1) bx--;
            else if (i == 2) by++;
            else if (i == 3) by--;
            else if (i == 4) cx++;
            else if (i == 5) cx--;
            else if (i == 6) cy++;
            else if (i == 7) cy--;
            else if (i == 8) {
                bx++;
                cx++;
            }
            else if (i == 9) {
                bx--;
                cx--;
            }
            else if (i == 10) {
                by++;
                cy++;
            }
            else if (i == 11) {
                by--;
                cy--;
            }
        }
    }
    return 0;
}

int main(void) {
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2012_04\\unlock_bronze\\1.in", "r", stdin);
    scanf("%d %d %d", &n1, &n2, &n3);
    //각 블록들을 입력받으며 최댓값과 최솟값을 미리 찾는다.
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &piece[0][i][0], &piece[0][i][1]);
        piece[0][i][0] += 12; //미리 오프셋 12를 설정한다.
        piece[0][i][1] += 12;
        if (piece[0][i][0] < axl) axl = piece[0][i][0];
        if (piece[0][i][0] > axh) axh = piece[0][i][0];
        if (piece[0][i][1] < ayl) ayl = piece[0][i][1];
        if (piece[0][i][1] > ayh) ayh = piece[0][i][1];
    }
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &piece[1][i][0], &piece[1][i][1]);
        if (piece[1][i][0] < bxl) bxl = piece[1][i][0];
        if (piece[1][i][0] > bxh) bxh = piece[1][i][0];
        if (piece[1][i][1] < byl) byl = piece[1][i][1];
        if (piece[1][i][1] > byh) byh = piece[1][i][1];
    }
    for (int i = 0; i < n3; i++) {
        scanf("%d %d", &piece[2][i][0], &piece[2][i][1]);
        if (piece[2][i][0] < cxl) cxl = piece[2][i][0];
        if (piece[2][i][0] > cxh) cxh = piece[2][i][0];
        if (piece[2][i][1] < cyl) cyl = piece[2][i][1];
        if (piece[2][i][1] > cyh) cyh = piece[2][i][1];
    }

    printf("%d", bfs(12, 12, 12, 12));
    return 0;
}