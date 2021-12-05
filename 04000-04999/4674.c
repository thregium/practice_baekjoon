#include <stdio.h>
#include <string.h>

/*
문제 : 길이 70 이하의 문자열과 자연수 키 K(K <= 300)가 주어질 때, 주어진 문자열 암호를 해독한 결과를 출력한다.
암호의 답은 반드시 유일하게 주어진다.

해결 방법 : 암호의 각 자리마다 해당 자리에 대응하는 위치의 문자를 각각 넣어보며 가능한 경우의 답을 찾아나가면 된다.

주요 알고리즘 : 문자열, 수학, 브루트 포스

출처 : MidC 1998 E번
*/

const char* conv = "_abcdefghijklmnopqrstuvwxyz.";
char buff[96], res[96];

int decode(char c) {
    if (c == '_') return 0;
    else if (c == '.') return 27;
    else if (c >= 'a' && c <= 'z') return 1 + c - 'a';
    else return -1;
}

int main(void) {
    int k, n, p;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1998\\untwist\\untwist.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1998\\untwist\\untwist_t.out", "w", stdout);
    while (1) {
        scanf("%d", &k);
        if (k == 0) break;
        scanf("%s", buff);
        n = strlen(buff);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 28; j++) {
                if ((j - i + 280000) % 28 == decode(buff[i])) res[k * i % n] = conv[j];
            }
        }
        res[n] = '\0';
        printf("%s\n", res);
    }
    return 0;
}