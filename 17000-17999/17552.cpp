#include <stdio.h>
#include <set>
using namespace std;

/*
���� : ũ�� N(N <= 18)�� ������ �κ����� �־��� ��, ũ�� N�� ������ ���� �� �ִ��� ���ϰ�,
�����ϴٸ� �ش� ������ ���ҵ��� ����Ѵ�. ��, ��� ���Ҵ� 0 �̻��� �����̴�.

�ذ� ��� : ��� ���ҵ��� Ʈ���¿� ����ִ´�. ���� ���� ���� ���� 0���� Ȯ���� �� �´ٸ� �����. �ƴ϶�� �ش� ������
���� �� �����Ƿ� ���α׷��� �����Ѵ�. ���ķδ� ���� ���� ���Ҹ� ������ ��(���� ���� �κ��յ� �� ���� ���� ��),
������ ���ҿ� ��������� ���ҵ�� ���� �� �ִ� ��� �κ��յ��� Ʈ���¿��� �����Ѵ�. �̸� �ݺ��ϴٰ� �κ����� Ʈ���¿� ���ٸ�
������ ���� �� �����Ƿ� ���������� �����ϰ�, N���� ���� ���ο� ���� �����ߴٸ� ���ݱ����� ���ҵ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, Ʈ����

��ó : BAPC 2019P K��
*/

multiset<long long> ms;
long long res[32];

int main(void) {
    long long n, w, x;
    scanf("%lld", &n);
    for (int i = 0; i < (1 << n); i++) {
        scanf("%lld", &w);
        ms.insert(w);
    }
    if (*(ms.begin()) != 0) {
        printf("impossible");
        return 0;
    }
    ms.erase(ms.begin());
    for (int i = 0; i < n; i++) {
        res[i] = *(ms.begin());
        for (int j = 0; j < (1 << i); j++) {
            x = res[i];
            for (int k = 0; k < i; k++) {
                if (j & (1 << k)) x += res[k];
            }
            if (ms.find(x) != ms.end()) {
                ms.erase(ms.find(x));
            }
            else {
                printf("impossible");
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld\n", res[i]);
    }
    return 0;
}