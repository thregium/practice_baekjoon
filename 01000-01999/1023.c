#include <stdio.h>

/*
���� : ���� N(N <= 50)�� '('�� ')'�� �̷���� ���ڿ� ��� ��ȣ�� �������� ���� K(K <= 2^N - 1)��° ���ڿ��� �ִ��� Ȯ���ϰ�
�ִٸ� �׷��� ���ڿ��� ����Ѵ�.

�ذ� ��� : ���ʿ� (�� �̸� �ִٰ� �����ϰ� �����ʿ� ���� ������ ���� ���� �� �ִ� ��ȣ ���ڿ��� ���� �̸� ����� �д�.
i(i�� �տ� �ִ� '('�� ��)�� 0�� ��쿡�� ��ȣ ���ڿ��� �Ϲ����� ��ȣ ���ڿ��� ����, 1 �̻��� ��쿡��
��ȣ�� ���� ĭ�鿡 �ѹ��� �־�� ����(i = i - 1)�� ������(i = 0)�� ��ȣ ���ڿ��� ���� ������ �˾Ƴ� �� �ִ�.
�̵��� ���� �˾Ƴ� �Ŀ��� i = 0�� ���� ���� ���� K��° ���ڿ��� �ִ����� Ȯ���Ѵ�.
���� �ִ� ��쿡�� ���ʿ������� ��ĭ�� ���ڵ��� �˾Ƴ��� �ȴ�.

�̴� '('�� �����ϴ� ��ȣ���� ���ڿ��� �տ��� ��ȣ�� �����ٸ� 2^i(i�� ���� ������ ��)���� ��찡 �ְ�,
������ �ʾҴٸ� 2^i - (���� ������ ���� �տ� �ִ� '('�� ���� �̸� ����ص� ��ȣ ���ڿ��� ����)���� ��찡 �����Ƿ�
���� ���� K�� �� �̻��̶�� ')'�� �����ϰ�, �̸��̶�� '('�� �����ϸ� �ȴ�. �̶�, ')'�� �����ϴ� ����
�ش��ϴ� ������ ��ŭ�� K���� ����� �Ѵ�. ����, �̷� ���� ���� '('�� ���� ������ �� ��쿡�� ��ȣ�� ���� ���̹Ƿ�
���ķδ� ��ȣ�� ���� ���� ����ؾ� �Ѵ�.

�ֿ� �˰����� : DP, ���շ�
*/

long long mem[64][64];
char res[64];

int main(void) {
    int n, par = 0, vld = 1;
    long long k;
    scanf("%d %lld", &n, &k);
    mem[0][0] = 1;
    for (int i = 2; i <= n; i += 2) {
        for (int j = 0, k = i - 2; j < i; j += 2, k -= 2) mem[0][i] += mem[0][j] * mem[0][k];
        //���� '('�� 0���� ���� ��ȣ ���ڿ��� īŻ�� ���� ���� ����
    }
    for (int lp = 1; lp <= n; lp++) {
        for (int i = 0; i <= n - lp; i++) {
            for (int rp = 0; rp < i; rp++) {
                mem[lp][i] += mem[lp - 1][rp] * mem[0][i - rp - 1];
                //lp : ������ '(' ����, i : ������ ����, rp : ������ ')'�� ��ġ
            }
        }
    }
    if (k >= (1LL << n) - mem[0][n]) {
        //K��° ��ȣ���� ���ڿ��� ���� �� ���� ���
        printf("-1");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (vld) {
            //��ȣ�� ������ ���� ���
            if (k >= (1LL << (n - i - 1)) - mem[par + 1][n - i - 1]) {
                res[i] = ')';
                k -= (1LL << (n - i - 1)) - mem[par + 1][n - i - 1];
                par--;
                if (par < 0) vld = 0; //�̹� ')'�� ���� ��ȣ�� ���� ���
            }
            else {
                res[i] = '(';
                par++;
            }
        }
        else {
            //�̹� ��ȣ�� ���� ���
            if (k >= (1LL << (n - i - 1))) {
                res[i] = ')';
                k -= (1LL << (n - i - 1));
            }
            else res[i] = '(';
        }
    }
    printf("%s", res);
    return 0;
}