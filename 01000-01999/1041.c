#include <stdio.h>
#include <stdlib.h>

/*
문제 : N * N * N(N <= 10^6) 개의 정육면체를 쌓아서 밖에 나온 면에 쓰인 수의 합이 가장 작을 때의 합을 구한다.
각 면에 쓰인 수는 50 이하의 자연수로 주어진다. 또한, 밖에 나온 면은 밑면을 제외한다.

해결 방법 : N이 1인 경우에는 밑면을 제외한 모든 면이 보이기 때문에 밑면을 가장 큰 수로 하고, 나머지 면들을 보이면 된다.
2 이상인 경우에는 각 정육면체에서 최대 3개의 면까지 보이게 된다. 이때, 서로 평행한 면끼리는 같이 보일 수 없다.
따라서, 가장 작은 면부터 보이되, 평행한 면인 경우에는 보일 수 없으므로 그 다음으로 작은 면을 찾아서 같이 보이는 식으로
가면 된다. 면 3개가 보이는 정육면체는 항상 4개이고, 면 1개만 보이는 정육면체는 (N - 2) * ((N - 2) + (N - 1) * 4)개이다.
나머지는 전부 면 2개가 보이는 정육면체이다.

주요 알고리즘 : 기하학, 그리디 알고리즘
*/

int dice[7];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    long long n, r;
    int smallest = 6, nd2 = 6, rd3 = 6, biggest = 6;
    scanf("%lld", &n);
    dice[6] = 99;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice[i]);
    }
    for (int i = 0; i < 6; i++) {
        if (dice[i] < dice[smallest]) smallest = i;
    }
    if (smallest > 5) return 1;
    for (int i = 0; i < 6; i++) {
        if (i + smallest == 5 || i == smallest) continue;
        if (dice[i] < dice[nd2]) nd2 = i;
    }
    if (nd2 > 5) return 2;
    for (int i = 0; i < 6; i++) {
        if (i + smallest == 5 || i + nd2 == 5 || i == smallest || i == nd2) continue;
        if (dice[i] < dice[rd3]) rd3 = i;
    }
    if (rd3 > 5) return 3;
    dice[6] = -1;
    for (int i = 0; i < 6; i++) {
        if (dice[i] > dice[biggest]) biggest = i;
    }
    if (biggest > 5) return 6;
    //qsort(dice, 6, sizeof(int), cmp1);
    if (n == 1) {
        printf("%d", dice[0] + dice[1] + dice[2] + dice[3] + dice[4] + dice[5] - dice[biggest]);
        return 0;
    }
    r = (n * (n - 1) * 4 + (n - 2) * (n - 2)) * (dice[smallest] + dice[nd2]);
    r += 4 * dice[rd3];
    r -= ((n - 2) * ((n - 1) * 4 + (n - 2))) * dice[nd2];
    printf("%lld", r);
    return 0;
}