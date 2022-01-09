#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
���� : P(P <= 50)���� ���翡 ���� �������� �Ҽ��� �Ʒ� 1�ڸ����� �־�����. �� ������ �̸��� �ҹ��� 20�� ���ϴ�.
�̶�, G(G <= 10000)���� ������ �´� �� Ȯ���Ѵ�.
�� ������ ������� ���ս� �������� Ư�� �� �̻�/����/�̸�/�ʰ�/�������� �����̴�.

�ذ� ��� : �Ǽ� ������ ����� ����Ƿ� ���������� �ٲپ� �����ϵ��� �Ѵ�. �̴� ���� �κп� 10�� ���ϰ�,
�Ҽ� �κ��� ���Ͽ� 10�� ���� �Ͱ� ������ ���°� �ǵ��� �ϴ� ������ ����ϴ�.
�׸��� �� ���縶���� �������� �ؽøʿ� �����Ѵ�.
�� �� �� ���󸶴� ������� ������ ���� ���س�����. �׷��ٰ� �� �����ڰ� ������ ������ Ȯ���ϰ�,
�������� ���Ͽ� �� ���� �´� �� ���θ� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽø�, �Ľ�, ���� ���е�?

��ó : Ulm 2009 B��
*/

unordered_map<string, int> party;
char buff[64];

int main(void) {
    int p, g, x, y, r;
    string s;
    //freopen("E:\\PS\\Contest\\Ulm\\2009\\ballot.in", "r", stdin);
    //freopen("E:\\PS\\Contest\\Ulm\\2009\\ballot_t.out", "w", stdout);
    scanf("%d %d", &p, &g);
    for (int i = 0; i < p; i++) {
        scanf("%s %d.%d", buff, &x, &y);
        s.assign(buff);
        party.insert(pair<string, int>(s, x * 10 + y));
    }
    for (int i = 1; i <= g; i++) {
        r = 0;
        while (1) {
            scanf("%s", buff);
            s.assign(buff);
            if (s == "=" || s == "<" || s == ">" || s == "<=" || s == ">=") {
                scanf("%d", &x);
                if (s == "=" && r == x * 10) r = 1;
                else if (s == "<" && r < x * 10) r = 1;
                else if (s == ">" && r > x * 10) r = 1;
                else if (s == "<=" && r <= x * 10) r = 1;
                else if (s == ">=" && r >= x * 10) r = 1;
                else r = 0;
                printf("Guess #%d was %s.\n", i, r ? "correct" : "incorrect");
                break;
            }
            else if (s == "+") continue;
            else if (party.find(s) == party.end()) return 1;
            else r += party[s];
        }
    }
    return 0;
}