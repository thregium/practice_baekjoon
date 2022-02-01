#include <stdio.h>

/*
문제 : N(1 <= N <= 7)개의 학기를 이미 수강한 상태에서 A(A <= 150)개의 전공 학점과 B(B <= 150)개의
전체 학점이 있는 상태라면 앞으로 8번째 학기까지 졸업 요건(66개의 전공 학점과 130개의 전체 학점)을
충족시킬 수 있는 지 구한다. 앞으로 10개 학기동안 개설되는 전공 강의와 비전공 강의의 개수(<= 6)가
주어지고, 모든 강의는 3학점이다.

해결 방법 : 전공 학점은 전체 학점에 포함되기 때문에 전공 강의부터 최대한 듣고 나머지 강의를
들어야 이득이다. 또한, 휴학을 하지 않아야 하므로 8 - N번째 이후 학기는 무시할 수 있다.

주요 알고리즘 : 그리디 알고리즘

출처 : 가톨릭대 3회 E번
*/

int lect[16][2];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, a, b, x, y, c, r = 0;
    scanf("%d %d %d", &n, &a, &b);
    n = 8 - n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lect[i][0], &lect[i][1]);
        x = lect[i][0];
        y = small(6 - lect[i][0], lect[i][1]);
        a += x * 3;
        b += (x + y) * 3;
        if (a >= 66 && b >= 130) r = 1;
    }
    /*
    for (int i = 0; i < 1024; i++) {
        x = 0, y = 0, c = 0;
        for (int j = 0; j < 10; j++) {
            if ((i >> j) & 1) {
                c++;
                x += lect[j][0];
                y += small(6 - lect[j][0], lect[j][1]);
            }
        }
        if (c > n) continue;
        if (a + x * 3 >= 66 && b + (x + y) * 3 >= 130) r = 1;
    }
    */
    printf("%s", r ? "Nice" : "Nae ga wae");
    return 0;
}