#include <stdio.h>
#include <set>
using namespace std;

/*
���� : ũ�� 500000 ������ �� ���� A, B�� �־��� ��, A�� �����̸鼭 B�� ���Ұ� �ƴ� ���� ������������ ����Ѵ�.
�� ������ ���Ҵ� 2^31���� ���� �ڿ����̴�. �� ���տ� ���� ���Ҵ� ���� �� �־����� �ʴ´�.

�ذ� ��� : �¿� ���� A�� ���ҵ��� ���� ��, ���� B�� �Է¹����� ���� B�� ���� ��� �¿� �ִ� ���ҵ��� ����.
�� ���� ���� ��ȸ�ϸ� �ִ� ���ҵ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ��
*/

set<int> amb;

int main(void) {
    int na, nb, x;
    scanf("%d %d", &na, &nb);
    for (int i = 0; i < na; i++) {
        scanf("%d", &x);
        amb.insert(x);
    }
    for (int i = 0; i < nb; i++) {
        scanf("%d", &x);
        if (amb.find(x) != amb.end()) amb.erase(x);
    }
    printf("%d\n", amb.size());
    for (int i : amb) {
        printf("%d ", i);
    }
    return 0;
}