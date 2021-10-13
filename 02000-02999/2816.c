#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 100)개의 채널이 있다. 500번 이내의 조작을 통해 "KBS1"이 맨 위, "KBS2"가 2번째에 있도록 한다.
커서는 처음에 1번째 채널에 있고, 커서를 아래로 1칸 옮기거나 위로 1칸 옮기거나 아래 칸과 채널을 바꾸거나(커서도 1칸 아래로),
위 칸과 채널을 바꾸는(역시 커서도 1칸 위로) 4가지 조작이 가능하다. 채널은 토러스가 아니고, 채널은 소문자와 _로 이루어진
10자 이하의 문자열이다.

해결 방법 : "KBS1"을 채널에서 찾아서 맨 위로 옮기고 다시 "KBS2"를 채널에서 찾아서 맨 위로 옮기더라도
최대 N * 4 = 400회의 조작만 하게 되므로 제한 내로 이동이 가능하다. 이를 직접 구현하면 된다.

주요 알고리즘 : 구현, 구성적

출처 : COCI 11/12#3 1번
*/

char chan[128][16], tmp[16];

void swap(int a, int b) {
    strcpy(tmp, chan[a]);
    strcpy(chan[a], chan[b]);
    strcpy(chan[b], tmp);
}

int main(void) {
    int n, cur = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", chan[i]);
    }
    while (strcmp(chan[cur], "KBS1")) {
        cur++;
        printf("1");
    }
    while (cur > 0) {
        printf("4");
        swap(cur, cur - 1);
        cur--;
    }
    while (strcmp(chan[cur], "KBS2")) {
        cur++;
        printf("1");
    }
    while (cur > 1) {
        printf("4");
        swap(cur, cur - 1);
        cur--;
    }
    return 0;
}