#include <stdio.h>
#include <math.h>

/*
���� : N(N <= 500)���� ������ �ִ�. �� ������ ��ȣ��(<= 10^6, ���� �ƴ� ����)�� �־��� ��, ������ K(1 <= K <= N)�� �̻���
���� �� ��ȣ���� ǥ�������� ���� ���� ���� �̾��� ���� ǥ�������� ���Ѵ�.

�ذ� ��� : ���Ʈ ������ ��� ��츦 Ȯ���� ���� �ȴ�. �̶�, �Ǽ� ������ ũ�� ������ long double�� ��� �Կ� �����Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : īī������ 2018�� B��
*/

int fav[512];

int main(void) {
    int n, k;
    long long sum;
    long double best = 9E+40, ave, sum2;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &fav[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + k - 1; j < n; j++) {
            sum = 0;
            for (int ii = i; ii <= j; ii++) {
                sum += fav[ii];
            }
            ave = (long double)sum / (j - i + 1);
            sum2 = 0;
            for (int ii = i; ii <= j; ii++) {
                sum2 += (fav[ii] - ave) * (fav[ii] - ave);
            }
            sum2 /= (j - i + 1);
            if (sum2 < best) {
                best = sum2;
            }
        }
    }
    printf("%.9Lf", sqrtl(best));
    return 0;
}