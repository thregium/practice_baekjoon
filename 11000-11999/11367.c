#include <stdio.h>

/*
문제 : 이름과 점수가 주어질 때, 이름과 등급을 출력한다. (등급표 생략)

해결 방법 : 이름을 그대로 출력한 후 등급표에 맞게 등급을 출력한다.

주요 알고리즘 : 구현

출처 : UVaH 2014 C번
*/

char a[16];

int main(void) {
    int n, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", a, &b);
        printf("%s ", a);
        if (b >= 97) printf("A+");
        else if (b >= 90) printf("A");
        else if (b >= 87) printf("B+");
        else if (b >= 80) printf("B");
        else if (b >= 77) printf("C+");
        else if (b >= 70) printf("C");
        else if (b >= 67) printf("D+");
        else if (b >= 60) printf("D");
        else printf("F");
        printf("\n");
    }
    return 0;
}