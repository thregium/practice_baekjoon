#include <stdio.h>

/*
문제 : 면이 6개인 두 주사위의 각 면에 쓰인 수들이 주어질 때, 첫 번째 주사위를 던진 결과가
두 번째 주사위를 던진 결과보다 클 확률을 기약분수로 구한다.

해결 방법 : 주사위의 각 면마다 쓰인 수의 모든 조합을 브루트 포스로 찾는다. 그 다음, 그러한 조합 가운데
첫 번째 주사위의 결과가 더 큰 것의 개수를 센다. 그 값이 분자이고, 36이 분모인 분수를 약분하여 기약분수를 구하면 된다.

주요 알고리즘 : 브루트 포스, 수학, 확률론, 유클리드 호제법

출처 : Seoul 2020 B번
*/

int first[6], sec[6];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &first[i]);
    }
    for (int i = 0; i < 6; i++) {
        scanf("%d", &sec[i]);
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (first[i] > sec[j]) cnt++;
        }
    }
    printf("%d/%d", cnt / gcd(cnt, 36), 36 / gcd(cnt, 36));
    return 0;
}