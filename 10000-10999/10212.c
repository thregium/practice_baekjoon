#include <stdio.h>
#include <time.h>

/*
문제 : 2번의 시도에서 각각 "Korea" 또는 "Yonsei"가 떠야 한다. 실행하는 코드는 같아야 한다.

해결 방법 : 코드의 수행 시간은 매번 조금씩 변할 수 있기 때문에 적당히 많은 횟수의 연산(약 1억회)을
한 다음, 클럭의 횟수를 세서 홀수와 짝수인 경우를 나누어 출력하는 글자를 정하면 된다.
여전히 운이 크게 작용하므로 여러 번 실행해야 할 수 있다.

주요 알고리즘 : ?

출처 : Coder's High 2014 PB번
*/

int main(void) {
    clock_t t = clock();
    long long cnt = 0;
    for (long long i = 0; i <= 103000; i++) {
        for (long long j = 1; j * j <= i; j++) {
            cnt += (j * i) % 103000;
        }
    }
    t = clock() - t + cnt;
    printf("%s", (t & 1) ? "Korea" : "Yonsei");
    return 0;
}