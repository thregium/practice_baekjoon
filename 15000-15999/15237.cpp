#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <map>
using namespace std;

/*
���� : N(N <= 1000)���� ���� �̷���� �迭(Ai <= 10^9)�� ���� ��, �� ���� ���� Ƚ���� ó�� ������ ������ �����Ѵ�.

�ذ� ��� : ���� Ƚ���� multiset�� ���� �����ϰ�, ó�� ������ ��� map�� ���� ��ġ�� ������ ���´�.
�׸���, ���Ľÿ� �� ���� multiset�� map���� �����ͼ� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ڷᱸ��

��ó : AIPO 2017P 6��
*/

int a[1024];
multiset<int> s;
map<int, int> mp;

int cmp1(const void* a, const void* b) {
    int ac = s.count(*(int*)a); //a�� ���� Ƚ��
    int bc = s.count(*(int*)b); //b�� ���� Ƚ��
    if (ac != bc) return ac < bc ? 1 : -1;
    int ai = mp.find(*(int*)a)->second; //a�� ù ���� ����
    int bi = mp.find(*(int*)b)->second; //b�� ù ���� ����
    return ai > bi ? 1 : ai == bi ? 0 : -1;
    return 0;
}

int main(void) {
    int n, c;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (!s.count(a[i])) {
            mp.insert(pair<int, int>(a[i], i)); //a[i]�� ó�� ������ ��� ���ڿ� ���� ��ġ�� ��ġ���� ���´�.
        }
        s.insert(a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}