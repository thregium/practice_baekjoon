#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 10000)���� ����� �ִ�. �� ����� ������ �ڿ���(2 <=, <= 10^6)�� ���´�.
1��° ������� ������ �� ����� �ڿ��� ��°�� ����� �����ϰ� ���� ������� �ٽ� �̸� �ݺ��Ѵ�.
�̶�, ���������� ���� ����� ��ȣ�� ���Ѵ�.

�ذ� ��� : ť�� ������� �ְ� ��ȣ�� Ƚ����ŭ ť�� �������� ����� �����ϴ� ������ �ùķ��̼��Ѵ�.
��, �� �������� �ð��� ���̱� ���� �ڿ����� ���θ� �ϴ� ���� ����.

�ֿ� �˰��� : �ڷ� ����, ť, �ùķ��̼�

��ó : ECNA 2019 F��
*/

queue<pair<int, int>> q;

int main(void) {
    int n, k;
    pair<int, int> p;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        q.push({ i, k });
    }
    while (q.size() > 1) {
        k = q.front().second;
        k %= q.size();
        if (k == 0) k = q.size();
        for (int i = k - 1; i >= 0; i--) {
            p = q.front();
            q.pop();
            if (i > 0) q.push(p);
        }
    }
    printf("%d", q.front().first);
    return 0;
}