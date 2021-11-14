#include <stdio.h>
#include <string.h>

/*
문제 : 5줄에 걸쳐 현재 상태가 주어질 때, 다음 상태를 구한다. 각 상태는 도약 준비 / 도약 중 / 착석 상태로 있고,
도약 준비와 도약 중 상태는 다음에 서로 상대 상태로 바뀐다. 착석은 다음 상태에도 그대로이다.

해결 방법 : 머리의 높이를 통해 각 상태를 찾아낸 다음, 다음 상태를 찾아서 출력한다.

주요 알고리즘 : 구현

출처 : 홍익대 2021 B번
*/

char s[5][10240];
int cat[10240];
const char* nxt[3] = { ".omln", "owln.", "..oLn" };

int main(void) {
    int l;
    for (int i = 0; i < 5; i++) {
        scanf("%s", s[i]);
    }
    l = strlen(s[0]);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < 5; j++) {
            if (s[j][i] == 'o') cat[i] = j;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < l; j++) {
            printf("%c", nxt[cat[j]][i]);
        }
        printf("\n");
    }
    return 0;
}