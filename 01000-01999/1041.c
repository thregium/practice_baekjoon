#include <stdio.h>
#include <stdlib.h>

/*
���� : N * N * N(N <= 10^6) ���� ������ü�� �׾Ƽ� �ۿ� ���� �鿡 ���� ���� ���� ���� ���� ���� ���� ���Ѵ�.
�� �鿡 ���� ���� 50 ������ �ڿ����� �־�����. ����, �ۿ� ���� ���� �ظ��� �����Ѵ�.

�ذ� ��� : N�� 1�� ��쿡�� �ظ��� ������ ��� ���� ���̱� ������ �ظ��� ���� ū ���� �ϰ�, ������ ����� ���̸� �ȴ�.
2 �̻��� ��쿡�� �� ������ü���� �ִ� 3���� ����� ���̰� �ȴ�. �̶�, ���� ������ �鳢���� ���� ���� �� ����.
����, ���� ���� ����� ���̵�, ������ ���� ��쿡�� ���� �� �����Ƿ� �� �������� ���� ���� ã�Ƽ� ���� ���̴� ������
���� �ȴ�. �� 3���� ���̴� ������ü�� �׻� 4���̰�, �� 1���� ���̴� ������ü�� (N - 2) * ((N - 2) + (N - 1) * 4)���̴�.
�������� ���� �� 2���� ���̴� ������ü�̴�.

�ֿ� �˰��� : ������, �׸��� �˰���
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