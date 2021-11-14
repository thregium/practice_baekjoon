#include <stdio.h>
#include <deque>
using namespace std;

/*
���� : N(N <= 1000)���� ���ڸ� ù ��° ���ں��� ���� ���ڿ��� �� �Ǵ� �ڿ� �ٿ����� ���� �� �ִ� ���ڿ� ���
���� ���������� ���� ���� ���Ѵ�.

�ذ� ��� : ���ڵ��� ���� �����ϸ� �� ���� ���ڿ� ���ų� �Ǵ� �׺��� ���������� ���� ���ڰ� ���� ���� �� �տ� �ְ�,
�� �ܿ��� �� �ڿ� �ִ´�. �̸� �ݺ��� �� ���� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ��

��ó : ���δ� 2016 E��
*/

deque<char> dq;

int main(void) {
    int t, n;
    char c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %c", &c);
            if (dq.empty() || dq.front() >= c) dq.push_front(c);
            else dq.push_back(c);
        }
        for (char i : dq) {
            printf("%c", i);
        }
        printf("\n");
        dq.clear();
    }
    return 0;
}