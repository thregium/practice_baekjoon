#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 1000)개의 채팅과 당첨자의 이름이 주어질 때, 당첨자 이전의 채팅 가운데 당첨자와 같은 채팅을 한 횟수를 구한다.
한 사람당 한 번만 채팅을 했고, 각 이름과 채팅은 10자 이하의 소문자로 이루어져 있다. 또한, 당첨자는 반드시 채팅을 했다.

해결 방법 : 먼저, 당첨자가 몇 번째에 채팅을 했는지 확인한다. 또한, 그와 함께 그때 한 채팅도 같이 확인한다.
채팅을 확인한 다음에는 그 이전의 채팅 가운데 해당 채팅과 같은 것을 세고 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : 인천대 2020 B번
*/

char chat[1024][2][16], win[16], corr[16];

int main(void) {
    int n, r = 0, cnt = -1;
    scanf("%d %s", &n, win);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", chat[i][0], chat[i][1]);
    }
    for (int i = 0; i < n; i++) {
        if (!strcmp(chat[i][0], win)) {
            cnt = i;
            strcpy(corr, chat[i][1]);
        }
    }
    if (cnt < 0) return 1;
    for (int i = 0; i < cnt; i++) {
        if (!strcmp(chat[i][1], corr)) r++;
    }
    printf("%d", r);
    return 0;
}