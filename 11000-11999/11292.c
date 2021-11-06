#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 50)명의 이름(소문자, 10자 이하)과 키(소숫점 아래 2자리까지)가 주어질 때, 가장 키가 큰 사람들의 이름을
순서대로 출력한다.

해결 방법 : 현재까지 키가 가장 큰 사람의 이름을 배열에 순서대로 저장해두고, 가장 큰 키와 그러한 사람의 수를
갱신해주면서 확인한다. 각 수는 정수형으로 바꾸어 비교하되 실수 오차에 유의한다.
만약 현재 받은 사람이 가장 큰 키와 같다면 가장 큰 사람의 수를 1 늘리고, 배열 맨 뒤에 이름을 추가한다.
더 크다면 가장 큰 사람의 수를 1로 초기화하고 배열에 그 사람의 이름만 넣어둔 다음 가장 큰 키도 갱신해주면 된다.
모든 사람의 정보를 받으면 현재의 가장 큰 사람의 배열을 출력한다.

주요 알고리즘 : 구현

출처 : NZPC 2015 A번
*/

char bestname[64][16], buf[16];

int main(void) {
    int n, best, bcnt, heint;
    double height;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        best = -1;
        bcnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s %lf", buf, &height);
            heint = height * 100 + 0.1;
            if (heint == best) {
                strcpy(bestname[bcnt++], buf);
            }
            else if (heint > best) {
                strcpy(bestname[0], buf);
                bcnt = 1;
                best = heint;
            }
        }
        if (best < 0) return 1;
        for (int i = 0; i < bcnt; i++) {
            printf("%s ", bestname[i]);
        }
        printf("\n");
    }
    return 0;
}