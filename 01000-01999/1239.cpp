#include <stdio.h>
#include <assert.h>
#include <algorithm>
using namespace std;

/*
���� : N(N <= 8)���� ������ �ڿ����� �־�����. ���� ���� 100�� ��, ������ ���� ��Ʈ�� �׷��� ������
�߽ɼ��� ������ ���� ���� ���� �߽ɼ� ������ ���Ѵ�.

�ذ� ��� : next_permutation() �Լ��� �̿��Ͽ� ��� ��츦 ���鼭 �� ��� ��� �߽ɼ��� ������
���� ���� ��츦 ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����
*/

int a[8];
int best = 0;

int count_halfline(int n) {
    int r = 0, sum;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; sum < 50; j = (j + 1) % n) {
            sum += a[j];
            if (sum == 50) r++;
        }
    }
    assert(r % 2 == 0);
    r >>= 1;
    if (r > best) best = r;
    return r;
}

int main(void) {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        assert(a[i] > 0);
        sum += a[i];
    }
    assert(sum == 100);
    while (next_permutation(a, a + n));
    count_halfline(n);
    while (next_permutation(a, a + n)) count_halfline(n);
    printf("%d", best);
    return 0;
}