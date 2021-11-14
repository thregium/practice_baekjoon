#include <stdio.h>
#include <string.h>

/*
문제 : 주어지는 문자열을 R * C(R, C <= 21) 크기의 행렬에 이진수로 바꾼 값을 달팽이 모양으로 저장하고
이를 행 단위로 읽은 값을 출력한다. 문자열은 행렬에 이진수로 바꾼 후 모두 들어갈 수 있는 크기로만 주어진다.
남는 칸은 0으로 넣는다.

해결 방법 : 문제에 주어진대로 구현한다. 자세한건 추가 예정

주요 알고리즘 : 구현, 시뮬레이션

출처 : GNY 2007 C번
*/

char mess[128], bin[512], arr[32][32];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int t, r, c, l, x, y, d;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &r, &c);
        getchar();
        fgets(mess, 120, stdin);
        if (mess[strlen(mess) - 1] == '\n') mess[strlen(mess) - 1] = '\0';
        l = strlen(mess);
        for (int i = 0; i < l; i++) {
            if (mess[i] == ' ') x = 0;
            else if (isupper(mess[i])) x = mess[i] - 'A' + 1;
            else return 1;
            for (int j = 0; j < 5; j++) {
                bin[i * 5 + j] = ((x >> (4 - j)) & 1) + '0';
            }
        }
        x = 0, y = 0, d = 0;
        for (int i = 0; i < r * c; i++) {
            arr[x][y] = (i < 5 * l ? bin[i] : '0');
            x += dxy[d][0];
            y += dxy[d][1];
            if (x < 0 || y < 0 || x >= r || y >= c || arr[x][y]) {
                x -= dxy[d][0];
                y -= dxy[d][1];
                d = ((d + 1) & 3);
                x += dxy[d][0];
                y += dxy[d][1];
            }
        }
        for (int i = 0; i < r; i++) {
            printf("%s", arr[i]);
        }
        printf("\n");
        memset(mess, 0, 128);
        memset(bin, 0, 512);
        memset(arr, 0, 1024);
    }
    return 0;
}