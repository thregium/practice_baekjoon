#include <stdio.h>

/*
문제 : 각 칸에 대문자들이 쓰여 있고, N(N <= 100)개의 칸으로 이루어진 돌림판이 있다.
돌림판에 같은 문자는 여러 칸에 들어갈 수 없다.
이 돌림판에 K(K <= 100)번의 회전에서 각각 멈춘 문자들이 주어지면 마지막에 멈춘 위치를 기준으로
각 칸의 문자들을 출력한다. 알 수 없는 문자의 경우 ?로 출력한다.
만약 그러한 돌림판을 만드는 방법이 없다면 ! 한 글자만 출력한다.

해결 방법 : 문자를 회전 수만큼 돌려가며 회전판에 문자를 써 넣어간다. 단, 같은 칸에 여러 문자를
넣어야 하거나 같은 문자를 여러 칸에 넣어야 하는 경우 그렇게 할 수 없으므로 !를 출력해야 한다.
그 외 경우 마지막에 도달한 위치에서 순서대로 돌려나가면 된다.

주요 알고리즘 : 문자열, 시뮬레이션

출처 : COCI 10/11#7 2번
*/

char res[32], chk[26];

int main(void) {
    int n, k, sp, tsp = 0, pos, good = 1;
    char c;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) res[i] = '?';
    for (int i = 0; i < k; i++) {
        scanf("%d %c", &sp, &c);
        tsp += sp;
        pos = (n * 103000 - tsp) % n;
        if (res[pos] != '?' && res[pos] != c) good = 0;
        if (res[pos] == '?') {
            if (chk[c - 'A']) good = 0;
            else chk[c - 'A'] = 1;
        }
        res[pos] = c;
    }
    if (!good) printf("!");
    else {
        for (int i = 0; i < n; i++) {
            printf("%c", res[(n * 103000 - tsp + i) % n]);
        }
    }
    return 0;
}