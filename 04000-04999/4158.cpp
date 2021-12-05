#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
using namespace std;

/*
���� : N���� CD ��ȣ�� M(N, M <= 10^6)���� CD ��ȣ�� ���� ������������ �־�����. �� ���տ��� ���ÿ� �����ϴ�
CD ��ȣ�� ������ ����Ѵ�. ��, �� ���� �������� CD ��ȣ�� ���� ���� �������� �ʴ´�.

�ذ� ��� : �ؽü��� �̿��ؼ� ù ��° ������ CD���� �ؽ� �¿� ���� ����, �� ��° ������ ���ҵ��� �Է¹��� �� ����
�� �ؽü¿� �ִ� ������ Ȯ���ϸ� �ȴ�. �ִ� ��� �ᱣ���� 1�� �÷�������.
������� ũ�� ������ fgets()�� ����ϴ� ���� ����.

�ֿ� �˰��� : �ڷ� ����, �ؽü�, �Ľ�

��ó : Waterloo 100926 A��
*/

unordered_set<int> us1;
char buff[128];

int main(void) {
    int n, m, x, r;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        r = 0;
        getchar();
        for (int i = 0; i < n; i++) {
            fgets(buff, 100, stdin);
            x = strtoll(buff, NULL, 10);
            us1.insert(x);
        }
        for (int i = 0; i < m; i++) {
            fgets(buff, 100, stdin);
            x = strtoll(buff, NULL, 10);
            if (us1.find(x) != us1.end()) r++;
        }
        printf("%d\n", r);
        us1.clear();
    }
    return 0;
}