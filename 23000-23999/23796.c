#include <stdio.h>

/*
문제 : 8 * 8 크기의 판에 2 이상 2^30 이하의 2의 거듭제곱 또는 0이 있다.
이때, 2048의 룰이 적용된다면 판을 주어진 방향으로 기울였을 때 게임 판의 상태를 출력한다.
새로운 수는 추가되지 않는다.

해결 방법 : 판을 기울이는 반대 방향으로 확인해 나가며 수들을 밑에서부터 쌓아나간다.
현재 보는 수가 마지막으로 확인한 수와 같다면 수를 합친 후 확인한 수를 없애고, 다르다면 마지막으로 확인한
수를 쌓은 다음 현재 수를 마지막으로 확인한 수로 바꾼다. 확인한 수가 없다면 현재 수를 마지막으로 확인한
수에 임시 저장해둔다. 판의 끝에 가면 현재 확인한 수를 쌓아둔 다음 나머지 칸들은 0으로 채운다.
이를 각 방향마다 구현하면 된다.

주요 알고리즘 : 구현, 투 포인터

출처 : 성균관대 2021 B번
*/

long long area[8][8];

int main(void) {
    long long cnt, l, ln;
    char d;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%lld", &area[i][j]);
        }
    }
    scanf(" %c", &d);
    if (d == 'U') {
        for (int i = 0; i < 8; i++) {
            l = 0, ln = 0;
            for (int j = 0; j < 8; j++) {
                if (area[j][i] && ln == 0) ln = area[j][i];
                else if (ln > 0 && area[j][i] == ln) {
                    area[l++][i] = ln * 2;
                    ln = 0;
                }
                else if (area[j][i]) {
                    area[l++][i] = ln;
                    ln = area[j][i];
                }
            }
            area[l++][i] = ln;
            while (l < 8) area[l++][i] = 0;
        }
    }
    else if (d == 'L') {
        for (int i = 0; i < 8; i++) {
            l = 0, ln = 0;
            for (int j = 0; j < 8; j++) {
                if (area[i][j] && ln == 0) ln = area[i][j];
                else if (ln > 0 && area[i][j] == ln) {
                    area[i][l++] = ln * 2;
                    ln = 0;
                }
                else if (area[i][j]) {
                    area[i][l++] = ln;
                    ln = area[i][j];
                }
            }
            area[i][l++] = ln;
            while (l < 8) area[i][l++] = 0;
        }
    }
    else if (d == 'D') {
        for (int i = 0; i < 8; i++) {
            l = 7, ln = 0;
            for (int j = 7; j >= 0; j--) {
                if (area[j][i] && ln == 0) ln = area[j][i];
                else if (ln > 0 && area[j][i] == ln) {
                    area[l--][i] = ln * 2;
                    ln = 0;
                }
                else if (area[j][i]) {
                    area[l--][i] = ln;
                    ln = area[j][i];
                }
            }
            area[l--][i] = ln;
            while (l >= 0) area[l--][i] = 0;
        }
    }
    else {
        for (int i = 0; i < 8; i++) {
            l = 7, ln = 0;
            for (int j = 7; j >= 0; j--) {
                if (area[i][j] && ln == 0) ln = area[i][j];
                else if (ln > 0 && area[i][j] == ln) {
                    area[i][l--] = ln * 2;
                    ln = 0;
                }
                else if (area[i][j]) {
                    area[i][l--] = ln;
                    ln = area[i][j];
                }
            }
            area[i][l--] = ln;
            while (l >= 0) area[i][l--] = 0;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%lld ", area[i][j]);
        }
        printf("\n");
    }
    return 0;
}