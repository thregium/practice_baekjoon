#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 100000)명의 사람들 가운데 가장 점수가 높은 사람을 구한다. 동점인 경우 사전순으로 이름이 가장 앞선 사람을 뽑는다.
동명이인은 주어지지 않는다. 각 사람의 이름은 최대 10 이하의 소문자로 된 문자열이다.

해결 방법 : 사람들 이름과 점수를 받으며 최고점수보다 더 점수가 높은 사람이 나오거나 점수가 최고점수와 같고
이름이 사전순으로 앞선 사람이 나오면 최고점수를 받은 사람 이름을 업데이트한다. 마지막의 최고점수를 받은 사람이 답이다.

주요 알고리즘 : 문자열

출처 : 연세대 2020 A번
*/

char name[16], bestname[16];

int main(void) {
    int n, b, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", name, &b);
        if (b > best) {
            best = b;
            strcpy(bestname, name);
        }
        else if (b == best && strcmp(name, bestname) < 0) {
            strcpy(bestname, name);
        }
    }
    printf("%s", bestname);
    return 0;
}