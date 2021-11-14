#include <stdio.h>

/*
문제 : 1부터 N(N <= 1000)까지의 자연수로 이루어진 순열이 주어질 때, 하나의 스택만을 이용해 이 수열을 정렬할 수 있는지 구한다.

해결 방법 : 주어진 순열의 수가 현재 나와야 할 수가 아니라면 스택에 수를 넣는다. 나와야 할 수라면
그 수를 보내고 나와야 할 수를 다음 수로 바꾼다. 매번 수를 볼 때 마다 스택의 맨 위에 있는 값이
현재 나와야 할 수라면 그 값을 빼고 다음 수로 넘어가는 것을 반복한다.

위 과정이 N개의 수에 대해 끝났을 때 스택에 수가 남아있다면 정렬할 수 없는 것이고,
스택이 비었다면 정렬이 완료된 것이다.

주요 알고리즘 : 자료 구조, 스택

출처 : 인하대 2016 L번
*/

int stack[1024];
int top = 0;

int main(void) {
    int n, x, p = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == p) p++;
        else stack[top++] = x;
        while (top > 0 && stack[top - 1] == p) {
            stack[top--];
            p++;
        }
    }
    if (p > n) printf("Nice");
    else printf("Sad");
    return 0;
}