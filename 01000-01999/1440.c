#include <stdio.h>

/*
문제 : 어떤 시각이 aa:bb:cc 형태로 주어질 때, 시, 분, 초를 바꾸어 몇 가지 방법으로 읽을 수 있는지 구한다.

해결 방법 : 각 부분을 시, 분, 초로 표현할 수 있는지 순서를 바꿔가며 확인해보면 된다.
특히, 분과 초는 표현 가능 범위가 같으므로 하나가 되면 다른 하나가 가능하기 때문에 2개로 처리하면 된다.

주요 알고리즘 : 브루트 포스
*/

int ish(int a) {
    if (a > 0 && a <= 12) return 1;
    else return 0;
}

int isms(int a) {
    if (a >= 0 && a < 60) return 1;
    else return 0;
}

int main(void) {
    int a, b, c, r = 0;
    scanf("%d:%d:%d", &a, &b, &c);
    if (ish(a) && isms(b) && isms(c)) r += 2;
    if (isms(a) && ish(b) && isms(c)) r += 2;
    if (isms(a) && isms(b) && ish(c)) r += 2;
    printf("%d", r);
    return 0;
}