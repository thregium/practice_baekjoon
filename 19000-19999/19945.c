#include <stdio.h>

/*
문제 : 정수 N(-2^32 <= N < 2^32)이 주어질 때, N의 MSB의 위치를 구한다. N은 32비트 정수이고,
음수의 경우 2의 보수 형태로 저장된다. 0일 때에는 MSB를 1이라 정의한다.

해결 방법 : 0일 때는 1, 음수일 때에는 32로 미리 예외 처리를 한다. 나머지 수는 2로 계속 나누어서 마지막으로 1보다 큰 수가
나오는 지점까지 나누면 그때의 지점이 MSB의 위치가 된다.

주요 알고리즘 : 수학

출처 : 인하대 2020N B번
*/

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    if (n == 0) printf("1");
    else if (n < 0) printf("32");
    else {
        for (int i = 1; i < 32; i++) {
            if ((n >> i) & 1) r = i + 1;
        }
        printf("%d", r);
    }
    return 0;
}