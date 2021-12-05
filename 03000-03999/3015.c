#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
���� : N(N <= 500000)���� �ڿ���(< 2^31)�� �־��� ��, ���̿� �� ū ���� ���� ���� ������ ���Ѵ�.

�ذ� ��� : ���� 2���� ����Ѵ�. �� ���� ���� �����ϵ��� ������ �����ϰ�, �ٸ� �� ���� ������ ���� ���� ������ ����.
�̶�, �� �ؿ� �ִ� ���� ��쿡�� �� ������ 1�� �� ���� �����ؾ� �Ѵ�.
�Ź� ���ÿ��� ���Ҹ� �� ������ �ᱣ���� 1�� ���ϰ�, ���Ҹ� ���� �� ���� �� ��° ������ �� ���� �ִ� ���� ���س�����
���� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ����

��ó : COI 2007 1��
*/

int d[524288], st[524288], st2[524288];
int top = 0;

int main(void) {
    int n, t, c = 0;
    long long r = 0;
    //srand(time(NULL));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
        //d[i] = rand() % 10;
    }
    for (int i = 0; i < n; i++) {
        while (top > 0 && st[top - 1] < d[i]) {
            top--;
            r++;
        }
        st[top] = d[i];
        st2[top] = (top <= 0 ? 0 : st[top] != st[top - 1] ? 1 : st2[top - 1] + 1);
        top++;
        if (top > 1) r += st2[top - 1];
    }
    printf("%lld\n", r);
    /*
    r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            c = 1;
            for (int k = i + 1; k < j; k++) {
                if (d[k] > d[i] || d[k] > d[j]) c = 0;
            }
            r += c;
        }
    }
    printf("%lld", r);
    */
    return 0;
}