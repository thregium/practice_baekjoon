#include <stdio.h>

/*
문제 : 문제에 주어진 규칙대로 노래를 부를 때, N(N <= 10^6)번째 단어가 무엇인지 구한다.

해결 방법 : 14번마다 노래가 반복하는 것을 알 수 있다. 따라서 14로 나눈 나머지에 따라 경우를 나누어 처리하면 된다.
truru...의 경우에는 14로 나눈 몫을 통해 개수를 알아낼 수 있고, 5개 이상인지 여부도 또 확인하면 된다.

주요 알고리즘 : 구현, 케이스 워크

출처 : UCPC 2018 J번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    switch ((n - 1) % 14) {
    case 0:
    case 12:
        printf("baby");
        break;
    case 1:
    case 13:
        printf("sukhwan");
        break;
    case 4:
        printf("very");
        break;
    case 5:
        printf("cute");
        break;
    case 8:
        printf("in");
        break;
    case 9:
        printf("bed");
        break;
    case 2:
    case 6:
    case 10:
        if ((n - 1) / 14 < 3) {
            printf("tu");
            for (int i = -2; i < (n - 1) / 14; i++) {
                printf("ru");
            }
        }
        else printf("tu+ru*%d", (n - 1) / 14 + 2);
        break;
    case 3:
    case 7:
    case 11:
        if ((n - 1) / 14 < 4) {
            printf("tu");
            for (int i = -1; i < (n - 1) / 14; i++) {
                printf("ru");
            }
        }
        else printf("tu+ru*%d", (n - 1) / 14 + 1);
        break;
    }
    return 0;
}