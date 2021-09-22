#include <stdio.h>

/*
문제 : 50개의 점수가 내림차순으로 주어질 때, 이후 주어진 점수가 상대평가 등급으로 어느 등급인지 구한다.
동점은 주어지지 않는다.

해결 방법 : 점수가 내림차순으로 주어지기 때문에 주어진 점수가 몇 번째에 나오는지 찾으면 그 값이 등수가 된다.
등수를 찾으면 등수에 맞는 등급을 구하면 된다.

주요 알고리즘 : 구현

출처 : 홍익대 2019 A번
*/

int scores[64];

int main(void) {
    int x;
    for (int i = 1; i <= 50; i++) {
        scanf("%d", &scores[i]);
    }
    scanf("%d", &x);
    for (int i = 1; i <= 50; i++) {
        if (scores[i] == x) {
            if (i <= 5) printf("A+");
            else if (i <= 15) printf("A0");
            else if (i <= 30) printf("B+");
            else if (i <= 35) printf("B0");
            else if (i <= 45) printf("C+");
            else if (i <= 48) printf("C0");
            else printf("F");
            break;
        }
    }
    return 0;
}