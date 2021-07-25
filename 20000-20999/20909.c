#include <stdio.h>

/*
문제 : 정삼각형 한개를 N(N <= 1000)개의 정삼각형으로 나누는 방법을 출력한다. 단, 정삼각형의 한 변의 길이는 최대 2가지만 쓸 수 있다.

해결 방법 : 맨 밑줄을 작은 삼각형, 그 위를 큰 삼각형으로 나눈다고 하면, 큰 삼각형의 길이가 1 늘어날 때 마다 작은 삼각형의 수가
2개씩 늘어나는 것을 알 수 있다. 큰 삼각형이 1개인 경우에는 4 이상의 모든 짝수에 대해 해당 경우를 만들 수 있고,
4개인 경우(1개인 경우에서 위쪽 삼각형을 4등분한 경우)에는 7 이상의 모든 홀수에 대해 만들 수 있다.
또한, 1인 경우에는 그 자체로 두면 된다. 그 외의 경우에는 나누는 것이 불가능하다.

주요 알고리즘 : 기하학, 구성적, 케이스 워크

출처 : GCPC 2020 I번
*/

int main(void) {
    int n, x;
    scanf("%d", &n);
    if (n % 2 == 0 && n > 2) {
        printf("1 %d %d\n", n / 2 - 1, n / 2);
        printf("B 0 1 U\n");
        for (int i = 0; i < (n >> 1); i++) {
            printf("A %d 0 U\n", i);
        }
        for (int i = 0; i < (n >> 1) - 1; i++) {
            printf("A %d 1 D\n", i);
        }
    }
    else if (n > 5) {
        x = (n - 5) / 2;
        printf("2 %d %d\n", x, n - 3);
        printf("B 0 2 U\nB 0 %d U\nB 0 %d D\nB %d 2 U\n", 2 + x, 2 + x, x);
        for (int i = 0; i < (n >> 1) - 1; i++) {
            printf("A %d 0 U\n", i * 2);
        }
        for (int i = 0; i < (n >> 1) - 2; i++) {
            printf("A %d 2 D\n", i * 2);
        }
    }
    else if (n == 1) printf("1 1 1\nA 0 0 U");
    else printf("impossible");
    return 0;
}