#include <stdio.h>
#define FOUT 1
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 세마리의 소가 수직선 상에 있을 때, 양 끝에 있는 소를 옮겨서 두 수 사이의 정수 좌표에 놓을 수 있다.
이를 반복하여 세 소가 연속된 정수 좌표에 있도록 할 때, 필요한 최소와 최대 이동 횟수를 구한다.

해결 방법 : 먼저, 세 소가 이미 연속된 좌표상에 있다면 이동을 할 필요가 없으므로 둘 다 0회이다.
최소 이동 횟수는 두 소의 좌표가 2 차이 나는 경우가 있다면 다른 한 소를 그 두 소 사이에 넣으면 되므로 1회,
나머지 경우에는 한 소를 다른 소의 2 앞이나 뒤에 놓고 앞의 이동을 해야 하므로 2회이다.
최대 이동 횟수는 바깥에 있는 소를 다른 두 소 중 하나에 붙이는 방식으로 반복한다면 (두 소의 거리 차 중 큰 것) - 1회가 된다.

주요 알고리즘 : 수학

출처 : USACO 2019F B1번
*/

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("herding.in", "r");
        fo = fopen("herding.out", "w");
    }
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a + 1 == b && b + 1 == c) {
        printf("%d\n%d", 0, 0);
    }
    else {
        if (a + 2 == b || b + 2 == c) {
            printf("%d\n", 1);
        }
        else {
            printf("%d\n", 2);
        }
        printf("%d", b - a > c - b ? b - a - 1 : c - b - 1);
    }
    return 0;
}