#include <stdio.h>

/*
문제 : 중심에서 반지름이 D1부터 D2(D1 <= D2 <= 2000)까지인 동심원을 반지름 1마다 1개씩 그렸다.
그리고 중심에서 시작하는 반직선에 시작점을 맞춰놓고 각 동심원마다
반지름 길이만큼 점을 같은 간격으로 찍었을 때, 중심에서 보이는 점의 개수를 구한다.

해결 방법 : D1부터 D2까지 각 동심원의 점에 대해 보이는 점인 경우 해당 점에 의해 가리는 점들을
모두 지운 다음 이를 반복하며 보이는 점의 개수를 세면 된다. 해당 점에 의해 가리는 점들은
유클리드 호제법을 이용해 기약분수 꼴로 고친 후 반지름이 D2가 될 때 까지 지워나가면 된다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법, 에라토스테네스

출처 : 정올 2014 중2/고1번
*/

char sieve[2048][2048];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int d1, d2, x, y, r = 0;
    scanf("%d %d", &d1, &d2);
    for (int i = d1; i <= d2; i++) {
        for (int j = 1; j <= i; j++) {
            if (sieve[i][j]) continue;
            r++;
            x = i / gcd(i, j);
            y = j / gcd(i, j);
            for (int k = 2; k * x <= d2; k++) sieve[k * x][k * y] = 1;
        }
    }
    printf("%d", r);
    return 0;
}