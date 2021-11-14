#include <stdio.h>
#include <set>
using namespace std;

/*
���� : N(N <= 1000)���� 9�� ������ ���ڷ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ����� ������ ������ ������ �������� ���Ѵ�.

�ذ� ��� : �¿� ���ڿ��� �� ���ڵ��� �ְ�, �� ���� �ִ� ���� ���� ������, �ٱ��� ���� ũ�Ⱑ ���� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ��

��ó : CTU 2016 B��
*/

char buff[1024];
set<set<int>> st;

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        st.clear();
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            set<int> stp;
            for (int j = 0; buff[j]; j++) {
                if (stp.find(buff[j] - '0') != stp.end()) continue;
                stp.insert(buff[j] - '0');
            }
            if (st.find(stp) != st.end()) continue;
            else st.insert(stp);
        }
        printf("%d\n", st.size());
    }
    return 0;
}