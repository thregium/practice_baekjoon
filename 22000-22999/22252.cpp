#include <stdio.h>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

/*
���� : Q(Q <= 100000)���� ������ ������ �� ���� ���� ��ġ�� ���� ���Ѵ�.
1. (String)�� K(K <= 100000)���� ���ο� ������ ��´�. �� ������ ��ġ�� C(C <= 100000)�̴�.
2. (String)���Լ� K(K <= 100000)���� ������ ���´�. �װ� ���� �ִ� ���� ��ġ�� ���� ������ K���̸�,
���� �ִ� ������ ���ų� K������ ���ٸ� �ִ� ��ŭ�� ���´�.
��� ������ ������ 10^6�� ���ϴ�. �� (String)�� 15�� ���ϴ�.

�ذ� ��� : ���ڿ��� �켱���� ť�� �ؽøʿ� ������� ���´�. �켱���� ť�� �ִ� ������ �����.
���ο� �ڰ� ������ ������ �ؽøʿ� �� ���ڿ��� ��Ͻ�Ų��. �׸��� �� �������� �켱���� ť�� �߰��Ѵ�.
�׿��Լ� ������ ���� ������ �ؽøʿ� ���� ��� �״�� �Ѿ��. �ִ� ��쿡�� ���� K�� �Ǵ�,
������ ������ �� ���� ���� ���ͼ� ���� ���� �����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽø�, �켱���� ť

��ó : ��ȣ�� 3ȸ 2��
*/

unordered_map<string, priority_queue<int>> gori;
char buff[32];

int main(void) {
    int q, o, k, c;
    long long r = 0;
    string s;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %s %d", &o, buff, &k);
        s.assign(buff);
        if (o == 1) {
            if (gori.find(s) == gori.end()) gori.insert(make_pair(s, priority_queue<int>()));
            for (int j = 0; j < k; j++) {
                scanf("%d", &c);
                gori[s].push(c);
            }
        }
        else if (o == 2) {
            if (gori.find(s) == gori.end()) continue;
            for (int j = 0; j < k; j++) {
                if (gori[s].size() == 0) break;
                r += gori[s].top();
                gori[s].pop();
            }
        }
        else return 1;
    }
    printf("%lld", r);
    return 0;
}