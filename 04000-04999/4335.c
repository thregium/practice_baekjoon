#include <stdio.h>

/*
문제 : 1에서 10까지의 수로 업다운 게임을 하였다. 이때, 답을 맞출 때 마다 답을 맞출 때 까지 답변이 일관적이었는지 구한다.

해결 방법 : 지금까지의 답변을 저장해둔 다음, 답을 맞출 때 마다 지금까지의 답변과 현재 수를 비교한다.
만약 현재 수 이하에서 지금보다 높다는 답변이 나오거나 이상에서 낮다는 답변이 나온 적이 있다면 일관적이지 않은 것이다.
그러한 답변이 나온 적이 없다면 일관적인 것이다. 답변이 끝나면 기록의 위치를 0번으로 초기화시킨다.

주요 알고리즘 : 구현, 수학

출처 : Waterloo 2003_07_05 E번
*/

char buff[16], buff2[16];
int game[1024][2];

int main(void) {
    int n, p = 0, t;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s %s", buff, buff2);
        game[p][0] = n;
        if (buff[0] == 'r') {
            t = 0;
            for (int i = 0; i < p; i++) {
                if ((game[i][0] <= n && game[i][1] >= 0) || (game[i][0] >= n && game[i][1] <= 0)) t = 1;
            }
            if (t) printf("Stan is dishonest\n");
            else printf("Stan may be honest\n");
            p = 0;
        }
        else if (buff2[0] == 'h') game[p++][1] = 1;
        else if (buff2[0] == 'l') game[p++][1] = -1;
        else return 1;
        if (p > 1000) return 1;
    }
    return 0;
}