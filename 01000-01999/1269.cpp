#include <stdio.h>
#include <set>
using namespace std;

/*
���� : �� �ڿ����� ������ �־��� ��, �� ������ ��Ī�����տ� ���ϴ� ������ ���� ���Ѵ�.

�ذ� ��� : �¿� ù ��° ������ ��� ���Ҹ� ���� ����, �� ��° ���տ��� �ش� ���Ұ� �ִٸ� �ᱣ������ 1��ŭ ����
���ٸ� 1��ŭ ���Ѵ�. ���� �ᱣ������ ù ��° ������ ������ ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ��
*/

set<int> s;

int main(void) {
    int a, b, x, r;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < a; i++) {
        scanf("%d", &x);
        s.insert(x);
    }
    r = a;
    for (int i = 0; i < b; i++) {
        scanf("%d", &x);
        if (s.find(x) != s.end()) r--;
        else r++;
    }
    printf("%d", r);
    return 0;
}