#include <iostream>

enum Banks {PKO, BGZ, BRE, BPH};

struct Account {
    Banks   bank;
    int  balance;
};

struct Person {
    char   name[20];
    Account account;
};

struct Couple {
    Person  he;
    Person she;
};

const Couple* bestClient(const Couple* cpls,
                         int size, Banks bank) {
    const Couple* c = nullptr;
    int sumMax = 0;
    for(size_t i = 0; i < size; i ++) {
        if(cpls[i].he.account.bank == bank || cpls[i].she.account.bank == bank) {
            int sum = cpls[i].he.account.balance + cpls[i].she.account.balance;
            if(c == nullptr) {
                sumMax = sum;
                c = &cpls[i];
            } else {
                if(sum > sumMax) {
                    sumMax = sum;
                    c = &cpls[i];
                }
            }
        }
    }
    return c;
}

int main() {
    using std::cout; using std::endl;
    Couple cpls[] = {
        {{"Johny", {PKO, 1200}}, {"Mary", {BGZ, 1500}}},
        {{"Peter", {BGZ, 1400}}, {"Suzy", {BRE, 1300}}},
        {{"Kevin", {PKO, 1600}}, {"Katy", {BPH, 1500}}},
        {{"Kenny", {BPH, 1800}}, {"Lucy", {BRE, 1700}}},
    };

    const Couple* p = bestClient(cpls,4,BGZ);
    cout << p->he.name << " and " << p->she.name
         << ": " << p->he.account.balance +
                    p->she.account.balance << endl;
}

