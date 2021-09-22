#include <stdio.h>

/*
문제 : N(N <= 15)개의 알파벳으로 이루어진 문자열을 만들려고 한다. 각 번째의 문자열들은 주어지는 N개의 문자열 가운데
하나로만 만들 수 있고, 최종적으로 만들어진 문자열에는 겹치는 알파벳이 있어서는 안 된다.
이때, 사전순으로 S번째부터 F(S, F <= 22 * 10^6, F - S <= 2000)번째까지의 문자열을 출력한다.
주어지는 N개의 문자열은 이미 사전순으로 정렬되어서 나온다.

해결 방법 : 주어지는 문자열들이 이미 정렬되어 나오기 때문에, 문자열을 순서대로 찾아가며 백트래킹의 형태로 문자열을 만든다.
이때 나온 문자들은 배열로 관리해 좀더 빠르게 확인할 수 있도록 한다. F번째 문자열까지 만들었다면 그 때 부터는
S번째까지 문자열들을 출력한다. S번째를 넘어가면 프로그램을 종료한다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : USACO 2006N B1번
*/

char codes[32][32], rfid[32];
int chk[32];
int n, s, f, cnt = 1;

void track(int x) {
    if (x == n) {
        if (s <= cnt && cnt <= f) {
            printf("%s\n", rfid);
        }
        cnt++;
    }
    for (int i = 0; codes[x][i]; i++) {
        if (chk[codes[x][i] - 'A']) continue;
        chk[codes[x][i] - 'A'] = 1;
        rfid[x] = codes[x][i];
        track(x + 1);
        if (cnt > f) return;
        chk[codes[x][i] - 'A'] = 0;
    }
}

int main(void) {
    scanf("%d %d %d", &n, &s, &f);
    for (int i = 0; i < n; i++) {
        scanf("%s", codes[i]);
    }
    track(0);
    return 0;
}