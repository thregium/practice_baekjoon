#include <stdio.h>

/*
문제 : 10 * 10 크기의 보드에 길쭉한 형태의 말들의 위치와 방향, 길이가 주어진다. 이때 이 말들이 판을 벗어나거나 겹치지 않고
잘 놓여있는지 여부를 구한다.

해결 방법 : 각 말들을 직접 판에 놓아본다. 판에서 벗어나거나 이미 다른 말이 있는 경우 제대로 놓여 있지 않은 것이고,
그렇지 않고 모든 말을 놓을 수 있다면 제대로 놓여 있는 것이다.

주요 알고리즘 : 구현

출처 : Brasil 2020 B번
*/

int field[16][16];

int main(void) {
    int n, d, l, r, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &d, &l, &r, &c);
        if (d) {
            for (int j = 0; j < l; j++) {
                if (r + j > 10 || field[r + j][c]) {
                    printf("N");
                    return 0;
                }
                field[r + j][c] = 1;
            }
        }
        else {
            for (int j = 0; j < l; j++) {
                if (c + j > 10 || field[r][c + j]) {
                    printf("N");
                    return 0;
                }
                field[r][c + j] = 1;
            }
        }
    }
    printf("Y");
    return 0;
}