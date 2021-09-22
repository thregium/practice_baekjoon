#include <stdio.h>

/*
문제 : 두 자연수 A, B(A, B <= 10^9)가 주어질 때, A^B의 마지막 자리를 구한다.

해결 방법 : A의 끝자리에 따라 B가 반복하기 때문에 경우를 나누어 처리하면 된다.

주요 알고리즘 : 수학, 정수론, 케이스 워크

출처 : PA 2005 0-1번
*/

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    switch (a % 10) {
    case 0:
        printf("0");
        break;
    case 1:
        printf("1");
        break;
    case 2:
        switch (b % 4) {
        case 0:
            printf("6");
            break;
        case 1:
            printf("2");
            break;
        case 2:
            printf("4");
            break;
        case 3:
            printf("8");
            break;
        }
        break;
    case 3:
        switch (b % 4) {
        case 0:
            printf("1");
            break;
        case 1:
            printf("3");
            break;
        case 2:
            printf("9");
            break;
        case 3:
            printf("7");
            break;
        }
        break;
    case 4:
        if (b % 2) printf("4");
        else printf("6");
        break;
    case 5:
        printf("5");
        break;
    case 6:
        printf("6");
        break;
    case 7:
        switch (b % 4) {
        case 0:
            printf("1");
            break;
        case 1:
            printf("7");
            break;
        case 2:
            printf("9");
            break;
        case 3:
            printf("3");
            break;
        }
        break;
    case 8:
        switch (b % 4) {
        case 0:
            printf("6");
            break;
        case 1:
            printf("8");
            break;
        case 2:
            printf("4");
            break;
        case 3:
            printf("2");
            break;
        }
        break;
    case 9:
        if (b % 2) printf("9");
        else printf("1");
    }
    return 0;
}