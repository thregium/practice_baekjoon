#include <stdio.h>
#include <unordered_map>
using namespace std;

/*
���� : N(N <= 1000)���� �ڿ���(<= 10^9)�� ������ �̷���� �� ���� �ִ������� ���Ѵ�. 10^9 �̻��� ��� ������ 9�ڸ��� ���Ѵ�.

�ذ� ��� : �� ���� ���� �����Ǵ� ��� �ڿ����� ���μ������Ѵ�. �̶�, ���μ��� �ſ� Ŀ�� �� �����Ƿ� �� ���μ���
�ؽøʿ� �ش��ϴ� ���μ��� ������ �Բ� �����Ѵ�. ������ ������ �� ���� ���� ��ġ�� ���μ��� ��ġ�� Ƚ����ŭ ���س�����.
���ϸ鼭 10^9�� �Ѿ�� �Ѿ����� �����ϰ�, 10������ ���� ���θ� �����س�����.
���������� 10������ �Ѿ����� Ȯ���ϰ� �Ѿ��ٸ� ������ 9�ڸ��� ���, ���� �ʾҴٸ� �״�� ����Ѵ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�, �ؽø�

��ó : COCI 11/12#2 3��
*/

char sieve[32768];
int prime[4096];
int pp = 0;
unordered_map<int, int> a, b;

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    for (int i = 2; i < 32768; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i; //32768 �̸��� �Ҽ� ����
        for (int j = i * 2; j < 32768; j += i) sieve[j] = 1;
    }
    int n, x, c, r2 = 0;
    long long r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        for (int j = 0; j < pp; j++) {
            if (x % prime[j]) continue;
            c = 0; //���μ� ����
            while (x % prime[j] == 0) {
                x /= prime[j];
                c++;
            }
            if (a.find(prime[j]) == a.end()) a.insert(pair<int, int>(prime[j], c)); //���ο� ���μ�
            else a.find(prime[j])->second += c; //�̹� �ִ� ���μ�
        }
        if (x == 1) continue;
        else if (x < prime[pp - 1]) return 1;
        else {
            if (a.find(x) == a.end()) a.insert(pair<int, int>(x, 1)); //ū ���μ��� ����
            else (a.find(x)->second)++;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        for (int j = 0; j < pp; j++) {
            if (x % prime[j]) continue;
            c = 0; //���μ� ����
            while (x % prime[j] == 0) {
                x /= prime[j];
                c++;
            }
            if (b.find(prime[j]) == b.end()) b.insert(pair<int, int>(prime[j], c));
            else b.find(prime[j])->second += c;
        }
        if (x == 1) continue;
        else if (x < prime[pp - 1]) return 1;
        else {
            if (b.find(x) == b.end()) b.insert(pair<int, int>(x, 1)); //ū ���μ�
            else (b.find(x)->second)++;
        }
    }
    
    for (auto i : a) {
        if (b.find(i.first) == b.end()) continue;
        else {
            c = small(i.second, b.find(i.first)->second); //��ġ�� ���μ��� ������ŭ ���ϱ�
            for (int j = 0; j < c; j++) {
                if (r * i.first >= 1000000000) {
                    r2 = 1; //10���� �Ѿ����� ���� ǥ��
                    r = r * i.first % 1000000000; //���� ó��
                }
                else r *= i.first;
            }
        }
    }
    if (r2) printf("%09lld", r);
    else printf("%lld", r);
    return 0;
}