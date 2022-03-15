#include <stdio.h>
#include <string.h>

/*
문제 : 80자 이하의 문자로 이루어진 줄이 1개 이상 주어진다. 이때, 각 줄에서 연속한 공백의 길이가
짝수인 경우를 비트 1, 홀수인 경우를 비트 0으로 하고, 이후 앞에서부터 5개 비트씩 잘라가며
문제에 주어진 변환표를 이용해 문자열로 변환한 결과를 출력한다.
남는 비트는 0으로 채운다.

해결 방법 : 문제에 주어진 것들을 구현한다.

주요 알고리즘 : 문자열, 파싱, 구현

출처 : MidC 2008 H번
*/

char bit[103000], mess[128];

int main(void) {
    int p, s;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\2008\\mcpc2008\\steg\\in.txt", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\2008\\mcpc2008\\steg\\out_t.out", "w", stdout);
    while (1) {
        p = 0;
        while (1) {
            fgets(mess, 100, stdin);
            if (mess[0] == '#') return 0;
            else if (mess[0] == '*') break;

            if (mess[strlen(mess) - 1] == '\n') mess[strlen(mess) - 1] = '\0';
            s = 0;
            for (int i = 0; mess[i]; i++) {
                if (mess[i] == ' ') s++;
                else {
                    if (s > 0 && (s & 1)) bit[p++] = 0;
                    else if (s > 0) bit[p++] = 1;
                    s = 0;
                }
            }
            if (s > 0 && (s & 1)) bit[p++] = 0;
            else if (s > 0) bit[p++] = 1;
        }
        for (int i = 0; i < (p + 4) / 5; i++) {
            s = 0;
            for (int j = 0; j < 5; j++) {
                s += bit[i * 5 + j] * (1 << (4 - j));
                bit[i * 5 + j] = '\0';
            }
            if (s == 0) printf(" ");
            else if (s <= 26) printf("%c", 'A' + s - 1);
            else if (s == 27) printf("'");
            else if (s == 28) printf(",");
            else if (s == 29) printf("-");
            else if (s == 30) printf(".");
            else if (s == 31) printf("?");
        }
        printf("\n");
    }
    return 0;
}