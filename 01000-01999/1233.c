#include <stdio.h>

/*
���� : �� �ֻ����� ���� ���� S1, S2, S3(S1, S2 <= 20)(S3 <= 40)�� �־��� ��, ���� ���� ������ ���� ���� ���� ���Ѵ�.

�ذ� ��� : ��� ����� ���� Ȯ���ϴ��� �ð� ���� Ǯ �� �����Ƿ� ���� Ȯ���غ� ���� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : USACO 2008X G1��
*/

int sums[128];

int main(void) {
    int s1, s2, s3, best = 0;
    scanf("%d %d %d", &s1, &s2, &s3);
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                sums[i + j + k]++;
            }
        }
    }
    for (int i = 1; i <= s1 + s2 + s3; i++) {
        if (sums[i] > sums[best]) best = i;
    }
    printf("%d", best);
    return 0;
}