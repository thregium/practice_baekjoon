#include <stdio.h>

/*
문제 : 8명이 원형으로 앉아있고, K번 사람에서 시작해서 폭탄 돌리기를 한다. N(N <= 100)개의 문제가 주어지고,
각 문제를 맞추면 다음 사람에게 폭탄을 넘길 수 있다. 3분 30초가 지나면 폭탄이 터진다고 할 때,
각 문제별로 걸린 시간과 맞추었는지 여부가 주어지면 폭탄이 터지게 되는 사람이 몇 번째인지 구한다.
단, N번의 문제 안에 터지고, 넘겨주는 도중에 터지는 경우는 없다.

해결 방법 : 매번 문제별로 걸린 시간을 더해나가며 210초가 될 때 까지 반복한다.
210초가 되면 그때의 사람이 몇 번인지 확인하고 출력한다. 그 외에는 맞추었는지 확인하고,
맞췄다면 다음 사람으로 넘기고, 그 외에는 그 사람이 다시 문제를 풀게 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : COCI 13/14#2 1번
*/

int main(void) {
    int k, n, s = 0, t;
    char z;
    scanf("%d%d", &k, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &t, &z);
        s += t;
        if (s >= 210) {
            printf("%d", k);
            return 0;
        }
        if (z == 'T') {
            k++;
            if (k > 8) k -= 8;
        }
    }
    return 1;
}