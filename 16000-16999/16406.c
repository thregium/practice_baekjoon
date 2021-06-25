#include <stdio.h>

/*
문제 : 친구와 나의 OX퀴즈 답안지와 친구가 맞은 문제의 수가 주어질 때, 내가 맞을 수 있는 문제의 최대 개수를 구한다.
단, 문제의 수는 1000개 이하이다.

해결 방법 : 친구와 내가 같게 응답한 문제의 수를 구한다. 만약 이 수가 친구가 맞은 문제의 수와 같다면 모든 문제를 맞추는 것도 가능하다.
친구가 맞은 문제의 수보다 많다면 친구가 틀린 문제는 같이 틀리게 되므로 다르게 응답한 문제 수 + 친구가 맞은 문제의 수만 맞출 수 있다.
더 적다면 친구가 맞은 문제를 다 맞출 수 없기 때문에 전체 문제에서 같이 맞출 수 없는 문제의 수를 뺀 수 만큼만 맞출 수 있다.

주요 알고리즘 : 그리디 알고리즘

출처 : PacNW 2018 A/N번 // SEUSA 2018 C번 / 2018D2 A번 // Midc 2018 B번
*/

char you[1024], fri[1024];

int main(void) {
    int k, same = 0, diff = 0;
    scanf("%d", &k);
    scanf("%s%s", you, fri);
    for (int i = 0; you[i]; i++) {
        if (you[i] == fri[i]) same++;
        else diff++;
    }
    if (k == same) printf("%d", same + diff);
    else if (k < same) printf("%d", k + diff);
    else printf("%d", same * 2 + diff - k);
    return 0;
}