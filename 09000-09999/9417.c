#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N < 100)개의 줄에 각각 100개 미만의 2^31보다 작은 정수가 주어진다. 각 줄에 대해 각 줄에 있는
서로 다른 정수의 쌍에서 만들 수 있는 최대공약수 가운데 가장 큰 것을 각각 출력한다.

해결 방법 : 우선 각 줄을 문자열 형태로 입력받는다. 그 다음으로, strtoll 함수를 이용해 각 수들을 파싱한다.
0이 나오기 전까지 End 포인터에서 반복해서 확인하면 된다.
각 수들을 파싱한 다음에는 모든 쌍에 대해 최대공약수를 확인하고 가장 큰 것을 찾으면 된다.

주요 알고리즘 : 수학, 유클리드 호제법, 파싱

출처 : Thai 2010N J번
*/

char buff[4096];
int num[128];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, m, x, r;
    char* p;
    scanf("%d\n", &n);
    for (int nn = 0; nn < n; nn++) {
        fgets(buff, 4000, stdin);
        m = 0;
        p = buff;
        while (1) {
            x = strtoll(p, &p, 10); //파싱을 통해 각 줄에 있는 수를 구한다.
            if (x == 0) break;
            num[m] = x;
            m++;
        }
        
        r = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (gcd(num[i], num[j]) > r) r = gcd(num[i], num[j]);
            }
        }
        printf("%d\n", r);
    }
    return 0;
}