#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_set>
using namespace std;

/*
���� : N(N <= 100000)���� ���ڿ��� �־�����. "ENTER"�� �־��� �� �� ���ڿ��� ó������ ������ Ƚ���� ���Ѵ�.
ù ���ڿ��� �ݵ�� "ENTER"�̴�.

�ذ� ��� : �Է¹��� ���ڿ��� "ENTER"�� ��� �ؽü��� �ʱ�ȭ�ϰ�, �� �� ��쿡�� �� ���ڿ��� �ؽü¿�
�ִٸ� �Ѿ�� ���� ��� �ᱣ���� 1�� ���� �� �ؽü¿� �� ���ڿ��� �߰��Ѵ�.
�̸� �ݺ��� �� �ᱣ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽü�, ���ڿ�

��ó : ������ 1ȸ B��
*/

unordered_set<string> st;
char buff[32];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (!strcmp(buff, "ENTER")) st.clear();
        else if (st.find(buff) == st.end()) {
            st.insert(buff);
            r++;
        }
    }
    printf("%d", r);
    return 0;
}