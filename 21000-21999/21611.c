#include <stdio.h>
#include <assert.h>

/*
���� : N * N(3 <= N < 50, N�� Ȧ��) ũ���� ���ڿ� �ҿ뵹�� ������� �������� ���� �ִ�.
�����鿡 ������ �־��� ����(����)���� �Ͽ� ���� ������ ������ ������ ���� �� ������ ��ȣ�� ���Ͽ�
���� ���� ����Ѵ�.

�ذ� ��� : �� �ҿ뵹���� ��° ���� �̸� ��ó���� ���� ���صд�.
�� ���� �̿��Ͽ� �ҿ뵹�̰� �������� ���� ������ ó�� �����ϸ�, ���߰� ��ȯ�� ���� �� �� �ִ�.
��, �� �������� �Ǽ����� �ʵ��� �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : �Ｚ SW ���� �׽�Ʈ
*/

int marb[64][64], ord[64][64], rord[2560][2], tmpmarb[2560];
int dxy1[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int dxy2[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void makeord(int n) {
    int x = n >> 1;
    int y = n >> 1;
    int d = 0, cnt = 0;
    for (int i = 0; i < n * n; i++) {
        ord[x][y] = i;
        rord[i][0] = x;
        rord[i][1] = y;
        x += dxy1[d & 3][0];
        y += dxy1[d & 3][1];
        cnt++;
        if (cnt > (d >> 1)) {
            cnt = 0;
            d++;
        }
    }
}

void blizz(int n, int d, int s) {
    int x = n >> 1;
    int y = n >> 1;
    for (int i = 1; i <= s; i++) {
        marb[x + dxy2[d][0] * i][y + dxy2[d][1] * i] = 0;
    }
}

void fallmarb(int n) {
    int lst = 1;
    for (int i = 1; i < n * n; i++) {
        if (marb[rord[i][0]][rord[i][1]]) {
            marb[rord[lst][0]][rord[lst][1]] = marb[rord[i][0]][rord[i][1]];
            lst++;
        }
    }
    for (int i = lst; i < n * n; i++) {
        marb[rord[i][0]][rord[i][1]] = 0;
    }
}

int explode(int n) {
    int res = 0, cnt = 0;
    for (int i = 1; i < n * n; i++) {
        if (marb[rord[i][0]][rord[i][1]] == marb[rord[i - 1][0]][rord[i - 1][1]]) cnt++;
        else {
            if (cnt >= 4) {
                res += marb[rord[i - 1][0]][rord[i - 1][1]] * cnt;
                for (int j = i - 1; j >= i - cnt; j--) marb[rord[j][0]][rord[j][1]] = 0;
            }
            cnt = 1;
        }
    }
    if (cnt >= 4) {
        res += marb[rord[n * n - 1][0]][rord[n * n - 1][1]] * cnt;
        for (int j = n * n - 1; j >= n * n - cnt; j--) marb[rord[j][0]][rord[j][1]] = 0;
    }
    return res;
}

void tfmarb(int n) {
    int tmplen = 1, concnt = 1;
    for (int i = 2; i < n * n; i++) {
        if (marb[rord[i][0]][rord[i][1]] == marb[rord[i - 1][0]][rord[i - 1][1]]) concnt++;
        else {
            assert(concnt <= 3);
            tmpmarb[tmplen++] = concnt;
            tmpmarb[tmplen++] = marb[rord[i - 1][0]][rord[i - 1][1]];
            concnt = 1;
        }
        if (tmplen >= n * n) break;
    }
    for (int i = 1; i < tmplen && i < n * n; i++) {
        marb[rord[i][0]][rord[i][1]] = tmpmarb[i];
    }
    for(int i = tmplen; i < n * n; i++) marb[rord[i][0]][rord[i][1]] = 0;
}

int main(void) {
    int n, m, d, s, score = 0, tscore = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &marb[i][j]);
        }
    }
    makeord(n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &d, &s);
        blizz(n, d, s);
        tscore = 1;
        while (tscore) {
            fallmarb(n);
            tscore = explode(n);
            score += tscore;
        }
        tfmarb(n);
    }
    printf("%d", score);
    return 0;
}