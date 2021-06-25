#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 8987654321234567890

/*
문제 : 두 개의 희소 벡터에 대해 더하고 곱하고 왼쪽으로 이동시키는 연산의 결과를 각각 구한다. 벡터의 길이는 최대 10^18이고,
벡터의 원소 개수는 최대 1000개이다. 벡터는 위치순으로 주어지며 원소가 -1인 경우에는 위치 * -1, 1인 경우에는 위치로 주어진다.
양수끼리 더하면 1이 되고 음수끼리 더하면 -1이 된다.

해결 방법 : 덧셈과 곱셈의 경우에는 투 포인터를 이용해 해결 가능하다. 만약 한쪽에만 나오는 원소가 나오면 합벡터에 해당 원소를
더해주면 되고, 양쪽에 나오는 원소가 나오면 합이 0인지 확인 후 0이라면 곱벡터에 음수로 추가해주고, 0이 아니라면
곱벡터에는 양수로, 합벡터에는 해당 원소를 추가해준다. 이동 연산의 경우에는 수를 적당히 줄인 후 0 이하가 되면 다시
N을 더하거나 빼준 다음 절댓값을 기준으로 정렬해주면 된다.

주요 알고리즘 : 구현, 투 포인터

출처 : PacNW 2018 V번 // SEUSA 2018D2 G번
*/

long long a[1024], b[1024], sum[2048], mul[2048], shfa[1024], shfb[1024];
long long sp = 0, mp = 0;

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return llabs(ai) > llabs(bi) ? 1 : llabs(ai) == llabs(bi) ? 0 : -1;
}

int main(void) {
    long long n, k, m1, m2, x = 0, y = 0;
    scanf("%lld %lld", &n, &k);
    scanf("%lld", &m1);
    for (int i = 0; i < m1; i++) {
        scanf("%lld", &a[i]);
        if (a[i] < 0) {
            shfa[i] = a[i] + k;
            if (shfa[i] >= 0) shfa[i] -= n; //왼쪽으로 K만큼 이동 후 벗어났다면 다시 오른쪽으로 N만큼 이동
        }
        else {
            shfa[i] = a[i] - k;
            if (shfa[i] <= 0) shfa[i] += n;
        }
    }
    a[m1] = INF;
    qsort(shfa, m1, sizeof(long long), cmp1); //정렬해준다.

    scanf("%lld", &m2);
    for (int i = 0; i < m2; i++) {
        scanf("%lld", &b[i]);
        if (b[i] < 0) {
            shfb[i] = b[i] + k;
            if (shfb[i] >= 0) shfb[i] -= n; //왼쪽으로 K만큼 이동 후 벗어났다면 다시 오른쪽으로 N만큼 이동
        }
        else {
            shfb[i] = b[i] - k;
            if (shfb[i] <= 0) shfb[i] += n;
        }
    }
    b[m2] = INF;
    qsort(shfb, m2, sizeof(long long), cmp1); //정렬해준다.

    while (x < m1 || y < m2) {
        if (llabs(a[x]) < llabs(b[y])) {
            //a[x]만 나오는 경우
            sum[sp++] = a[x];
            x++;
        }
        else if (llabs(b[y]) < llabs(a[x])) {
            //b[y]만 나오는 경우
            sum[sp++] = b[y];
            y++;
        }
        else {
            //동시에 나오는 경우
            if (a[x] + b[y] == 0) {
                //합이 0이라면
                mul[mp++] = a[x];
                if (a[x] > 0) mul[mp - 1] *= -1;
            }
            else {
                //합이 0이 아니라면
                sum[sp++] = a[x];
                mul[mp++] = a[x];
                if (a[x] < 0) mul[mp - 1] *= -1;
            }
            x++;
            y++;
        }
    }

    printf("%lld ", sp);
    for (int i = 0; i < sp; i++) {
        printf("%lld ", sum[i]);
    }
    printf("\n%lld ", mp);
    for (int i = 0; i < mp; i++) {
        printf("%lld ", mul[i]);
    }
    printf("\n%lld ", m1);
    for (int i = 0; i < m1; i++) {
        printf("%lld ", shfa[i]);
    }
    printf("\n%lld ", m2);
    for (int i = 0; i < m2; i++) {
        printf("%lld ", shfb[i]);
    }
    return 0;
}
