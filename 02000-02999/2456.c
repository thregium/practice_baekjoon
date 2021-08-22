#include <stdio.h>

/*
문제 : 3명의 후보에 대한 투표 결과가 주어질 때, 1위와 그의 점수를 구한다. 점수 합이 가장 높은 사람 -> 3점을 가장 많이 받은 사람
-> 2점을 가장 많이 받은 사람 순으로 우선순위가 있고 전부 같다면 1위는 없다.

해결 방법 : 각자의 점수를 구한 후 경우의 수를 나누어 해결한다.

주요 알고리즘 : 구현, 케이스 워크

출처 : 정올 2011지 초2/고1번
*/

int counts[4][4];

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        counts[1][a]++;
        counts[1][0] += a;
        counts[2][b]++;
        counts[2][0] += b;
        counts[3][c]++;
        counts[3][0] += c;
    }
    if (counts[1][0] > counts[2][0] && counts[1][0] > counts[3][0]) printf("1 %d", counts[1][0]);
    else if (counts[2][0] > counts[1][0] && counts[2][0] > counts[3][0]) printf("2 %d", counts[2][0]);
    else if (counts[3][0] > counts[1][0] && counts[3][0] > counts[2][0]) printf("3 %d", counts[3][0]);
    else if (counts[1][3] > counts[2][3] && counts[1][3] > counts[3][3] && counts[1][0] >= counts[2][0] && counts[1][0] >= counts[3][0]) printf("1 %d", counts[1][0]);
    else if (counts[2][3] > counts[1][3] && counts[2][3] > counts[3][3] && counts[2][0] >= counts[1][0] && counts[2][0] >= counts[3][0]) printf("2 %d", counts[2][0]);
    else if (counts[3][3] > counts[1][3] && counts[3][3] > counts[2][3] && counts[3][0] >= counts[1][0] && counts[3][0] >= counts[2][0]) printf("3 %d", counts[3][0]);
    else if (counts[1][2] > counts[2][2] && counts[1][2] > counts[3][2] && counts[1][3] >= counts[2][3] && counts[1][3] >= counts[3][3] && counts[1][0] >= counts[2][0] && counts[1][0] >= counts[3][0]) printf("1 %d", counts[1][0]);
    else if (counts[2][2] > counts[1][2] && counts[2][2] > counts[3][2] && counts[2][3] >= counts[1][3] && counts[2][3] >= counts[3][3] && counts[2][0] >= counts[1][0] && counts[2][0] >= counts[3][0]) printf("2 %d", counts[2][0]);
    else if (counts[3][2] > counts[1][2] && counts[3][2] > counts[2][2] && counts[3][3] >= counts[1][3] && counts[3][3] >= counts[2][3] && counts[3][0] >= counts[1][0] && counts[3][0] >= counts[2][0]) printf("3 %d", counts[3][0]);
    else printf("0 %d", counts[1][0] >= counts[2][0] ? counts[1][0] : counts[2][0]);
    return 0;
}