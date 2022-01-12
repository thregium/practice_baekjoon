#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 40)개의 단어가 있을 때, 순서대로 단구를 이루는 단어의 집합이 있는 지 찾고, 있다면 그 시작점을,
없다면 -1을 출력한다. 단어는 10자 이하의 소문자로 이루어져 있고, 단구는 단어를 차례로 1개 이상씩 연결하며
5, 7, 5, 7, 7개의 문자를 이루어야 한다.

해결 방법 : 각 단어의 길이를 배열에 추가한 다음, 모든 시작점에 대해 단구를 만들어 본다.
단구를 만들 때에는 현재 단어의 길이와 만들어야 할 문구의 번째를 확인하며 현재 문구의 길이가
목표치와 같다면 다음 문구로 넘어가고, 그보다 많다면 탐색을 종료한다. 마지막 문구에 도달한 단구가 있다면
그 시작점을 출력하면 되고, 모든 시작점에 대해 불가능하다면 -1을 출력하면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : JDC 2015 B번
*/

char buff[16];
int ln[64];
int tk[5] = { 5, 7, 5, 7, 7 };

int main(void) {
    int n, r = 0, cnt;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            ln[i] = strlen(buff);
        }
        for (int i = 0; i < n; i++) {
            r = 0, cnt = 0;
            for (int j = i; j < n; j++) {
                cnt += ln[j];
                if (cnt == tk[r]) {
                    cnt = 0;
                    r++;
                }
                else if (cnt > tk[r]) break;
                if (r == 5) {
                    printf("%d\n", i + 1);
                    break;
                }
            }
            if (r == 5) break;
        }
        if (r < 5) printf("-1\n");
    }
    return 0;
}