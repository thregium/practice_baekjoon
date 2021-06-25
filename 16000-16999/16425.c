#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 8987654321234567890

/*
���� : �� ���� ��� ���Ϳ� ���� ���ϰ� ���ϰ� �������� �̵���Ű�� ������ ����� ���� ���Ѵ�. ������ ���̴� �ִ� 10^18�̰�,
������ ���� ������ �ִ� 1000���̴�. ���ʹ� ��ġ������ �־����� ���Ұ� -1�� ��쿡�� ��ġ * -1, 1�� ��쿡�� ��ġ�� �־�����.
������� ���ϸ� 1�� �ǰ� �������� ���ϸ� -1�� �ȴ�.

�ذ� ��� : ������ ������ ��쿡�� �� �����͸� �̿��� �ذ� �����ϴ�. ���� ���ʿ��� ������ ���Ұ� ������ �պ��Ϳ� �ش� ���Ҹ�
�����ָ� �ǰ�, ���ʿ� ������ ���Ұ� ������ ���� 0���� Ȯ�� �� 0�̶�� �����Ϳ� ������ �߰����ְ�, 0�� �ƴ϶��
�����Ϳ��� �����, �պ��Ϳ��� �ش� ���Ҹ� �߰����ش�. �̵� ������ ��쿡�� ���� ������ ���� �� 0 ���ϰ� �Ǹ� �ٽ�
N�� ���ϰų� ���� ���� ������ �������� �������ָ� �ȴ�.

�ֿ� �˰��� : ����, �� ������

��ó : PacNW 2018 V�� // SEUSA 2018D2 G��
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
            if (shfa[i] >= 0) shfa[i] -= n; //�������� K��ŭ �̵� �� ����ٸ� �ٽ� ���������� N��ŭ �̵�
        }
        else {
            shfa[i] = a[i] - k;
            if (shfa[i] <= 0) shfa[i] += n;
        }
    }
    a[m1] = INF;
    qsort(shfa, m1, sizeof(long long), cmp1); //�������ش�.

    scanf("%lld", &m2);
    for (int i = 0; i < m2; i++) {
        scanf("%lld", &b[i]);
        if (b[i] < 0) {
            shfb[i] = b[i] + k;
            if (shfb[i] >= 0) shfb[i] -= n; //�������� K��ŭ �̵� �� ����ٸ� �ٽ� ���������� N��ŭ �̵�
        }
        else {
            shfb[i] = b[i] - k;
            if (shfb[i] <= 0) shfb[i] += n;
        }
    }
    b[m2] = INF;
    qsort(shfb, m2, sizeof(long long), cmp1); //�������ش�.

    while (x < m1 || y < m2) {
        if (llabs(a[x]) < llabs(b[y])) {
            //a[x]�� ������ ���
            sum[sp++] = a[x];
            x++;
        }
        else if (llabs(b[y]) < llabs(a[x])) {
            //b[y]�� ������ ���
            sum[sp++] = b[y];
            y++;
        }
        else {
            //���ÿ� ������ ���
            if (a[x] + b[y] == 0) {
                //���� 0�̶��
                mul[mp++] = a[x];
                if (a[x] > 0) mul[mp - 1] *= -1;
            }
            else {
                //���� 0�� �ƴ϶��
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
