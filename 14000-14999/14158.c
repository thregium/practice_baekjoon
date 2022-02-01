#include <stdio.h>

/*
문제 : 문제에 주어진 형식대로 1900년부터 2100년까지 28 * 73 크기의 달력을 만들 때,
N * M(N, M <= 10) 크기의 주어진 직사각형과 일치하는 부분이 있는 연도를 오름차순으로 모두 출력한다.
항상 그러한 연도가 있는 경우만 주어진다.

해결 방법 : 1900년부터 2100년까지 차례로 달력을 문제에 주어진 방법대로 만든 다음,
각 연도마다 주어진 직사각형이 있는 지 브루트 포스로 찾는다. 있다면 그 해를 출력한다.
이를 2100년까지 반복하면 된다. 달력을 만들 때에는 좌표 지정과 윤년 처리에 주의한다.

주요 알고리즘 : 구현, 브루트 포스, 시뮬레이션

출처 : CPC 2007 D번
*/

char targ[16][16], cale[32][96];
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char* mname[] = { "", "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
"JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER" };
int mlen[13] = { 0, 7, 8, 5, 5, 3, 4, 4, 6, 9, 7, 8, 8 };

int isleap(int x) {
    if (x & 3) return 0;
    else if (x % 400 == 0) return 1;
    else if (x % 100 == 0) return 0;
    else return 1;
}

int main(void) {
    int n, m, mn = 1, dy = 1, dw = 0, wk = 0, lp, x, y, tmp, tmp2;
    //freopen("E:\\PS\\ICPC\\Europe\\CPC\\2007\\test_podaci\\kalendar\\kalendar.in.15", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CPC\\2007\\test_podaci\\kalendar\\kalendar.out_t.15", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", targ[i]);
    }
    for (int yr = 1900; yr <= 2100; yr++) {
        lp = isleap(yr);
        for (int i = 0; i < 28; i++) {
            for (int j = 0; j < 73; j++) cale[i][j] = '.';
        }
        for (int i = 1; i <= 12; i++) {
            x = ((i - 1) >> 2) * 9 + 1;
            y = ((i - 1) & 3) * 18 + 2;
            for (int j = 0; j < mlen[i]; j++) cale[x][y + j] = mname[i][j];
        }
        do {
            x = ((mn - 1) >> 2) * 9 + dw + 2;
            y = ((mn - 1) & 3) * 18 + wk * 3 + 1;
            if (dy >= 10) cale[x][y] = dy / 10 + '0';
            cale[x][y + 1] = dy % 10 + '0';

            dy++;
            dw++;
            if (dw == 7) {
                dw = 0;
                wk++;
            }
            if (((mn != 2 || lp == 0) && days[mn] < dy) || (lp == 1 && mn == 2 && dy == 30)) {
                dy = 1;
                wk = 0;
                mn++;
            }
            if (mn == 13) mn = 1;
        } while (mn != 1 || dy != 1);

        for (int i = 0; i < 28; i++) {
            //printf("%s\n", cale[i]);
        }
        tmp = 0;
        for (int i = 0; i < 28 - n + 1; i++) {
            for (int j = 0; j < 73 - m + 1; j++) {
                tmp2 = 1;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < m; l++) {
                        if (targ[k][l] != cale[i + k][j + l]) {
                            tmp2 = 0;
                            break;
                        }
                    }
                    if (!tmp2) break;
                }
                tmp |= tmp2;
                if (tmp) break;
            }
            if (tmp) break;
        }
        if (tmp) printf("%d\n", yr);
    }
    return 0;
}