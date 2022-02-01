#include <stdio.h>
#include <string.h>
#include <unordered_map>
using namespace std;

/*
문제 : 명령어들이 주어질 때 마다 각 계좌의 변화를 시뮬레이션하며 그 명령어의 결과를 출력한다.

해결 방법 : 각 명령어들마다 그 명령어에 맞는 변화를 시뮬레이션한다.
각 계좌의 금액은 해시맵으로 관리하고, 계좌의 순서는 배열로 관리한다.
"PREVED" 명령어에 주의한다.

주요 알고리즘 : 구현, 시뮬레이션, 해시맵, 케이스 워크

출처 : CTU 2001 B번
*/

char op[16];
long long acd[10240];
unordered_map<long long, long long> acc;

int main(void) {
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\b.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\b_t.out", "w", stdout);
    long long ucet, ucet2, casti, castf, tot = 0, date = 0;
    while (scanf("%s", op) != EOF) {
        if (!strcmp(op, "ZALOZ")) {
            scanf("%lld", &ucet);
            if (acc.find(ucet) != acc.end()) printf("Ucet %010lld uz existuje.\n\n", ucet);
            else {
                printf("Ucet %010lld vytvoren.\n\n", ucet);
                acc.insert(pair<long long, long long>(ucet, 0));
                acd[date++] = ucet;
            }
        }
        else if (!strcmp(op, "ULOZ")) {
            scanf("%lld %lld.%lld", &ucet, &casti, &castf);
            if (acc.find(ucet) != acc.end()) {
                printf("Ulozeno %lld.%02lld na ucet %010lld.\n\n", casti, castf, ucet);
                acc[ucet] += casti * 100 + castf;
                tot += casti * 100 + castf;
            }
            else printf("Ucet %010lld neexistuje.\n\n", ucet);
        }
        else if (!strcmp(op, "VYBER")) {
            scanf("%lld %lld.%lld", &ucet, &casti, &castf);
            if (acc.find(ucet) != acc.end()) {
                if (acc[ucet] < casti * 100 + castf) printf("Nedostatek penez.\n\n");
                else {
                    printf("Vybrano %lld.%02lld z uctu %010lld.\n\n", casti, castf, ucet);
                    acc[ucet] -= casti * 100 + castf;
                    tot -= casti * 100 + castf;
                }
            }
            else printf("Ucet %010lld neexistuje.\n\n", ucet);
        }
        else if (!strcmp(op, "PREVED")) {
            scanf("%lld %lld %lld.%lld", &ucet, &ucet2, &casti, &castf);
            if (acc.find(ucet) == acc.end()) {
                printf("Ucet %010lld neexistuje.\n", ucet);
                if (acc.find(ucet2) == acc.end()) printf("Ucet %010lld neexistuje.\n\n", ucet2);
                else printf("\n");
            }
            else if (acc[ucet] < casti * 100 + castf) {
                printf("Nedostatek penez.\n");
                if (acc.find(ucet2) == acc.end()) printf("Ucet %010lld neexistuje.\n\n", ucet2);
                else printf("\n");
            }
            else if (acc.find(ucet2) == acc.end()) printf("Ucet %010lld neexistuje.\n\n", ucet2);
            else {
                printf("Prevedeno %lld.%02lld z uctu %010lld na ucet %010lld.\n\n",
                    casti, castf, ucet, ucet2);
                acc[ucet] -= casti * 100 + castf;
                acc[ucet2] += casti * 100 + castf;
            }
        }
        else if (!strcmp(op, "STATISTIKA") || !strcmp(op, "LIST")) {
            printf("Pocet uctu: %d\n", acc.size());
            if (!strcmp(op, "LIST")) {
                for (int i = 0; i < date; i++) {
                    printf("%010lld %7lld.%02lld\n", acd[i], acc[acd[i]] / 100, acc[acd[i]] % 100);
                }
            }
            printf("Celkem: %11lld.%02lld\n\n", tot / 100, tot % 100);
        }
        else if (!strcmp(op, "RESET")) {
            printf("Reset systemu.\n\n");
            tot = 0, date = 0;
            acc.clear();
        }
        else return 1;
    }
    printf("Konec.\n");
    return 0;
}