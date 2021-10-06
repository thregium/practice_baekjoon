#include <stdio.h>

/*
문제 : A, B, C, D로 이루어진 원반을 앞으로 2칸 돌리고 뒤로 1칸 돌리는 것을 반복했을 때 N(N <= 10^9)번째에 오는 값을 구한다.
처음에는 A에서 시작한다.

해결 방법 : 12번마다 A, B, C, B, C, D, C, D, A, D, A, B가 반복되는 것을 알 수 있다. 따라서, 12로 나눈 나머지에 따라
경우를 나누어 처리하면 된다.

주요 알고리즘 : 수학

출처 : HotSpot 2010 1-1번
*/

int main(void) {
    int z, n;
    scanf("%d", &z);
    for (int i = 0; i < z; i++) {
        scanf("%d", &n);
        switch (n % 12) {
        case 0:
        case 2:
        case 4:
            printf("B\n");
            break;
        case 1:
        case 9:
        case 11:
            printf("A\n");
            break;
        case 3:
        case 5:
        case 7:
            printf("C\n");
            break;
        case 6:
        case 8:
        case 10:
            printf("D\n");
            break;
        }
    }
    return 0;
}