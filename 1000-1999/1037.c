#include <stdio.h>

/*
문제 : 자연수 A의 약수 가운데 1과 A를 제외한 모든 약수가 순서 없이 주어질 때 A를 구한다.

해결 방법 : A의 약수 가운데 1을 제외한 가장 작은 약수가 존재하고, 이를 m이라고 하면 A를 제외한 가장 큰 약수는
A / m이 된다. 따라서 A는 가장 작은 약수와 가장 큰 약수의 곱이다.

주요 알고리즘 : 수학 
*/

int main(void) {
    int n, t, m, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        if(i == 0) {
            m = t;
            x = t;
        }
        else if(t < m) m = t;
        else if(t > x) x = t;
    }
    printf("%d", m * x);
    return 0;
}