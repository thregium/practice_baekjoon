#include <stdio.h>

/*
문제 : 10 이하의 음이 아닌 정수 A, B가 주어질 때, 일차함수 AX + B의 식과 그래프를 출력한다.
그래프의 X축 범위는 0부터 10까지이며, Y축 범위는 X가 10일 때의 값을 확인할 수 있는 가장 낮은 높이까지이다.
X축과 Y축, 그리고 정수 점에는 '*'를, 나머지 칸에는 공백을 표시하여 나타낸다.

해결 방법 : 문제에 주어진대로 구현한다. 좌표 범위를 잘 설정하면 2중 for문만으로 풀 수 있다.

주요 알고리즘 : 구현

출처 : NZPC 2015 G번
*/

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        printf("y = %dx + %d\n", a, b);
        for (int j = a * 10 + b; j >= 0; j--) {
            for (int k = 0; k <= 10; k++) printf("%c", j == a * k + b || j == 0 || k == 0 ? '*' : ' ');
            printf("\n");
        }
    }
    return 0;
}