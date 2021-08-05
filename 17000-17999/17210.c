#include <stdio.h>

/*
문제 : N(N <= 25 * 10^8)개의 문을 규칙에 맞게 여는 방법을 구한다. 없다면 Love is open door를 출력한다. (규칙 생략)

해결 방법 : N이 6 이상인 경우에는 규칙에 맞게 여는 방법이 존재하지 않는다. 그 외에는 지그재그로 열면 된다.

주요 알고리즘 : 수학

출처 : 한양대E 2019R A번
*/

int main(void) {
    long long n, x;
    scanf("%lld %lld", &n, &x);
    if (n > 5) printf("Love is open door");
    else {
        for (int i = 1; i < n; i++) {
            x = !x;
            printf("%lld\n", x);
        }
    }
    return 0;
}