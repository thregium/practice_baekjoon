#include <stdio.h>
#include <math.h>

/*
문제 : 6 * 6 크기의 육각형 형태의 체스판이 있다. 이 체스판에서 상대 말이 움직이지 않고 다른 말이 없다면
룩과 상대 말의 위치가 주어졌을 때 상대 말을 정확히 2회에 잡기 위해 룩을 움직이는 방법의 수를 구한다.

해결 방법 : 체스판의 각 칸에서 룩을 움직여 갈 수 있는 칸들을 모든 칸에 대해 조사한다. 좌표계상 중앙 줄을 중심으로
왼쪽과 오른쪽으로 나누어 계산해야 한다. 그 다음으로는 룩을 1회 움직여 갈 수 있는 모든 칸을 확인한다.
여기서 1회만에 상대 말의 위치로 갔다면 그 경우는 제외하고, 나머지 경우에 대해 다시 그 위치에서 1회 움직여
상대 말의 위치로 이동이 가능한지 확인한다. 이동이 가능하다면 결괏값에 1을 추가한다. 이를 반복해 나온 결괏값을 출력한다.

주요 알고리즘 : 구현, 브루트 포스

출처 : BAPC 2019P H번
*/

int size[12] = { 0, 6, 7, 8, 9, 10, 11, 10, 9, 8, 7, 6 };
int movable[16][16][256];

char buff1[8], buff2[8];

int main(void) {
    for (int i = 1; i <= 11; i++) {
        for (int j = 1; j <= size[i]; j++) {
            for (int k = 1; k <= size[i]; k++) {
                if (j == k) continue;
                movable[i][j][++movable[i][j][0]] = i * 100 + k;
            }
            if (i <= 6) {
                for (int k = 1; k <= 6; k++) {
                    if (k == i) continue;
                    if (size[k] >= j) movable[i][j][++movable[i][j][0]] = k * 100 + j;
                    if (j + (k - i) >= 1) movable[i][j][++movable[i][j][0]] = k * 100 + j + (k - i);
                }
                for (int k = 7; k <= 11; k++) {
                    if (k == i) continue;
                    if (size[k] >= j + (6 - i)) movable[i][j][++movable[i][j][0]] = k * 100 + (j + (6 - i));
                    if (j - (k - 6) >= 1) movable[i][j][++movable[i][j][0]] = k * 100 + (j - (k - 6));
                }
            }
            else {
                for (int k = 1; k <= 6; k++) {
                    if (k == i) continue;
                    if (size[k] >= j + (i - 6)) movable[i][j][++movable[i][j][0]] = k * 100 + (j + (i - 6));
                    if (j - (6 - k) >= 1) movable[i][j][++movable[i][j][0]] = k * 100 + (j - (6 - k));
                }
                for (int k = 7; k <= 11; k++) {
                    if (k == i) continue;
                    if (size[k] >= j) movable[i][j][++movable[i][j][0]] = k * 100 + j;
                    if (j + (i - k) >= 1) movable[i][j][++movable[i][j][0]] = k * 100 + j + (i - k);
                }
            }
        }
    }

    int x1, y1, x2, y2, x3, y3, r = 0;
    scanf("%s %s", buff1, buff2);
    x1 = buff1[0] - 'a' + 1;
    x2 = buff2[0] - 'a' + 1;
    if (buff1[2] != '\0') y1 = (buff1[1] - '0') * 10 + buff1[2] - '0';
    else y1 = buff1[1] - '0';
    if (buff2[2] != '\0') y2 = (buff2[1] - '0') * 10 + buff2[2] - '0';
    else y2 = buff2[1] - '0';
    for (int i = 1; i <= movable[x1][y1][0]; i++) {
        x3 = movable[x1][y1][i] / 100;
        y3 = movable[x1][y1][i] % 100;
        if (x3 == x2 && y3 == y2) continue;
        for (int j = 1; j <= movable[x3][y3][0]; j++) {
            if (movable[x3][y3][j] / 100 == x2 && movable[x3][y3][j] % 100 == y2) {
                r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}