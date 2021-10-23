#include <stdio.h>

/*
문제 : N * M(N, M <= 400) 크기의 컬러 이미지에 대한 R, G, B 값이 주어진다. 이때, 이 컬러 이미지를 문제에 주어진 대로
명도 값을 알아낸 후 명도에 맞게 출력할 문자를 찾아서 아스키 아트를 만든다.

해결 방법 : 문제에 주어진 식대로 명도 값을 계산하고, 그 값에 맞게 아스키 문자들을 출력하면 된다.
마지막 줄을 제외한 줄 끝은 개행한다.

주요 알고리즘 : 구현, 사칙연산

출처 : 연세대 2019 A번
*/

int main(void) {
    int n, m, r, g, b, it;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d %d %d", &r, &g, &b);
            it = r * 2126 + g * 7152 + b * 722;
            if (it < 510000) printf("#");
            else if (it < 1020000) printf("o");
            else if (it < 1530000) printf("+");
            else if (it < 2040000) printf("-");
            else printf(".");
        }
        if (i < n - 1) printf("\n");
    }
    return 0;
}