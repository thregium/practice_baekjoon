#include <stdio.h>

/*
���� : 'A'�� 'B'�θ� �̷���� ���� N(N <= 50)�� ���ڿ� ��� A �ڿ� B�� ���� ���� K���� ���ڿ��� �ƹ��ų� �ϳ� ����Ѵ�.
���� ��� -1�� ����Ѵ�.

�ذ� ��� : ����, ���̰� N�� �� ���ڿ��� ���� �� �ִ� ���� ū K�� �Ǵ� ���� ���ʿ� A�� ����, ���ʿ� B�� ���� �ִ� ����̴�.
�̶��� K�� N�� ¦���� �� (N / 2)^2, Ȧ���� �� ((N - 1) / 2) * ((N + 1) / 2)�̴�.
����, �̺��� ū ��쿡�� -1�� ����Ѵ�.

���ڿ��� ���� �� �ִٸ�, �켱 ���� 0���� ������ �����Ѵ�. �̶��� ��� ���ڰ� 'B'�� �����̴�.
���⼭ 'A'�� ���ʺ��� �־�� K�� ������ Ȯ���Ѵ�. A�� ���� �־ �߰��� �� �ִ� K�� ������ (N - i * 2 + 1)�̴�.
�� �Ŀ��� i�� �ִ� A�� ��ȣ�̴�. �׺��� ũ�ٸ� �� ��°�� A�� �ְ� K���� �ش� ���� �� �� ���� ���ڸ� ���ɴ�.
�� ������ ��쿡�� �ڿ������� ���� �� �־�� �� ��ġ�� A�� �ְ� Ž���� �����ϸ� �ȴ�. �̶��� ��ġ�� �ڿ��� K��°�̴�.
Ž���� �����ϸ� ���ݱ��� ���� ���ڿ��� ����Ѵ�.

�ֿ� �˰����� : �׸��� �˰�����, ���շ�, ������
*/

char res[64];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k > (n >> 1) * ((n + 1) >> 1)) {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < n; i++) res[i] = 'B';
    for (int i = 1; i <= (n >> 1); i++) {
        if (k > n - i * 2 + 1) {
            k -= n - i * 2 + 1;
            res[i - 1] = 'A';
        }
        else {
            res[n - i - k] = 'A';
            break;
        }
    }
    printf("%s", res);
    return 0;
}