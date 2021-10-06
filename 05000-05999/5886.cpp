#include <stdio.h>
#include <string.h>
#include <queue>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
���� : �����ǿ� 3���� ������ �ִ�. �� �������� �������� �� ������ �и��� �� �ִ��� ���Ѵ�.
�� ������ ��ǥ�� X�� Y��ǥ ��� 0 �̻� 9 ������ �����̴�. �� ������ �и��� ���� �� ������ �ѷ��δ� ���簢������
���� ��ġ�� ���� ���̴�.

�ذ� ��� : ù ��° ������ ������ �ΰ� �ٸ� �������� ������� ��ġ�� ó���� ����� ���������� �� ������ Ȯ���Ѵ�.
�ٸ� �� ������ X�� Y��ǥ ���̸� ������ �ΰ� �÷������� �ϸ� �ȴ�. �� �������� �ѷ��δ� ���簢���� ��ġ�� �ʴ�����
��ǥ�� �ִ񰪰� �ּڰ��� ���ϴ� ������� ���� �� �ִ�.
�ӵ��� ������ �ϱ� ���� ���� ������ �ٷ� ����ϴ� ���� ����. ���� ó���� ����� ������ �����Ѵ�.

�ֿ� �˰��� : ����, �÷�����, ���Ʈ ����, ������ ��

��ó : USACO 2012O B4��
*/

int dist[25][25][25][25], piece[3][128][2];
char vis[25][25][25][25], chk[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n1, n2, n3, axl = INF, axh = -INF, ayl = INF, ayh = -INF, bxl = INF, bxh = -INF, byl = INF, byh = -INF,
cxl = INF, cxh = -INF, cyl = INF, cyh = -INF; //�� ������ ��ǥ�� �ּڰ�, �ִ�
queue<tuple<int, int, int, int>> q;

int boxcheck(int bx, int by, int cx, int cy) {
    //�� ���簢���� ��ġ�� �ʴ��� Ȯ���Ѵ�. ��ġ�� �ʴ´ٸ� 1�� ��ȯ�ϰ� ��ģ�ٸ� 0�� ��ȯ�Ѵ�.
    if ((bxl + bx <= axh && bxh + bx >= axl) && (byl + by <= ayh && byh + by >= ayl)) return 0;
    if ((cxl + cx <= axh && cxh + cx >= axl) && (cyl + cy <= ayh && cyh + cy >= ayl)) return 0;
    if ((bxl + bx <= cxh + cx && bxh + bx >= cxl + cx) && (byl + by <= cyh + cy && byh + by >= cyl + cy)) return 0;
    return 1;
}

int bfs(int bx, int by, int cx, int cy) {
    //BFS�� ���� ������ �����̸� �и��� �������� Ȯ���Ѵ�.
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
    //�� ��ϵ��� �Է¹����� �ִ񰪰� �ּڰ��� �̸� ã�´�.
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &piece[0][i][0], &piece[0][i][1]);
        piece[0][i][0] += 12; //�̸� ������ 12�� �����Ѵ�.
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