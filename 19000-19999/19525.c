#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
문제 : 150 * 150 이하 크기의 정사각형 형태의 격자에 대해 어떠한 네 점도 직사각형을 이루지 않도록
점을 1700개 이상 뽑는 방법을 출력한다.

해결 방법 : 같은 사선상의 점들을 뽑으면 직사각형을 이루지 않게 된다. 이를 가장 긴 사선부터 차례로 뽑되,
직사각형을 이루지 않도록 뽑으면 1608개를 뽑을 수 있다. 여기에 약간의 랜덤성을 추가하면 대부분의 경우
이보다 낮게 나오지만 가끔씩 이보다 높은 개수가 나오게 된다. 1700개 이상이 되면
그때의 뽑는 방법을 출력하고 이를 이용하면 된다.

주요 알고리즘 : 그리디 알고리즘, 구성적, 무작위화, 전처리

출처 : Petro 2016S9 G번
*/

char res[256][256];

int main(void) {
    int n = 150, r = 0, sel, best, cnt, ok, rr = 0;
    for (int tt = 0;; tt++) {
        r = 0, rr = 0;
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) res[i][j] = '.';
        }
        while (r + rr < n * n) {
            sel = -1, best = -1;
            for (int i = 0; i < n * 2 - 1; i++) {
                cnt = 0;
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < n; jj++) {
                        if (ii + jj != i) continue;
                        if (res[ii][jj] != '.') ok = 0;
                        else cnt++;
                    }
                }
                if (cnt > best) {
                    if (rand() % 100 > 50) continue;
                    best = cnt;
                    sel = i;
                }
            }
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < n; jj++) {
                    if (ii + jj != sel) continue;
                    r++;
                    res[ii][jj] = 'O';
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int ii = i + 1; ii < n; ii++) {
                        for (int jj = j + 1; jj < n; jj++) {
                            if ((res[i][j] == 'O') + (res[i][jj] == 'O') + (res[ii][j] == 'O') + (res[ii][jj] == 'O') == 3) {
                                if (res[i][j] == '.') res[i][j] = '*';
                                else if (res[i][jj] == '.') res[i][jj] = '*';
                                else if (res[ii][j] == '.') res[ii][j] = '*';
                                else if (res[ii][jj] == '.') res[ii][jj] = '*';
                                else rr--;
                                rr++;
                            }
                        }
                    }
                }
            }
        }
        printf("%d %d\n", r, rr);
        if (r < 1660) continue;
        for (int i = 0; i < n; i++) {
            printf("%s\n", res[i]);
        }
        if (r >= 1700) break;
    }
    return 0;
}