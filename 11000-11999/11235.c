#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 1000)명의 사람이 후보자에게 투표했다. 가장 많이 투표된 사람을 출력한다.
여럿인 경우 사전순으로 모두 출력한다. 투표된 사람의 이름은 20자 이하의 대문자로 이루어져 있다.

해결 방법 : 각 투표를 사전순으로 정렬한 다음, 각 투표된 사람을 사전순으로 중복 횟수를 세서 정리하고,
그 중 중복 횟수가 가장 많은 사람과 같은 사람들을 다시 차례로 출력하면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : SEUSA 2014D2 F번
*/

typedef struct cand {
    char name[32];
    int cnt;
} cand;

char vote[1024][32];
cand cd[1024];

int main(void) {
    int n, cp = 0, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", vote[i]);
    }
    qsort(vote, n, sizeof(char) * 32, strcmp);
    for (int i = 0; i < n; i++) {
        if (i == 0 || strcmp(vote[i], vote[i - 1])) {
            cd[cp].cnt = 1;
            strcpy(cd[cp++].name, vote[i]);
        }
        else cd[cp - 1].cnt++;
    }
    for (int i = 0; i < cp; i++) {
        if (cd[i].cnt > best) best = cd[i].cnt;
    }
    for (int i = 0; i < cp; i++) {
        if (cd[i].cnt == best) {
            printf("%s\n", cd[i].name);
        }
    }
    return 0;
}