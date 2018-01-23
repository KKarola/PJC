#include <iostream>

// ...

bool checkpass(const char* pass) {

    bool length = true;
    int sLength = 0;
    for(int i = 0; pass[i] != '\0'; i++) {
        if(pass[i] >= 32 && pass[i] < 126) {
            sLength++;
        }
    }
   if(sLength < 8) {
        std::cout << "Too short" << std::endl;
        length = false;
   }

    int diff = 0;
    bool rozne;
    bool different = true;
    for(int i = 0; pass[i] != '\0'; i++) {
        rozne = true;
        for(int j = i+1; pass[j] != '\0'; j++) {
            if(pass[i] == pass[j]) {
                rozne=false;
            }
        }
        if(rozne) diff++;

    }
    if(diff < 6) {
        std::cout << "Too few different characters" << std::endl;
        different = false;
    }

    bool number = false;
    for(int i = 0; pass[i] != '\0'; i++) {
        if(pass[i] >= 48 && pass[i] <= 57) {
            number = true;
        }
    }
    if(!number) std::cout << "No digit" << std::endl;

    bool upper = false;
    for(int i = 0; pass[i] != '\0'; i++) {
        if(pass[i] >= 65 && pass[i] <= 90) {
            upper = true;
        }
    }
    if(!upper) std::cout << "No uppercase letter" << std::endl;

    bool lower = false;
    for(int i = 0; pass[i] != '\0'; i++) {
        if(pass[i] >= 97 && pass[i] <= 122) {
            lower = true;
        }
    }
    if(!lower) std::cout << "No lowercase letter" << std::endl;

    bool alphanumeric = false;
    for(int i = 0; pass[i] != '\0'; i++) {
        if(!((pass[i] >= 48 && pass[i] <= 57) || (pass[i] >= 65 && pass[i] <= 90) || (pass[i] >= 97 && pass[i] <= 122))) {
            alphanumeric = true;
        }
    }
    if(!alphanumeric) std::cout << "No non-alphanumeric character" << std::endl;

    if(length & different & number & upper & lower & alphanumeric)
        return true;
}

int main() {
    using std::cout; using std::endl;
    const char* passes[] =
        {
            "AbcDe93",  "A1b:A1b>",  "Ab:Acb<",
            "abc123><", "Zorro@123", '\0'
        };
    for (int i = 0; passes[i] != '\0'; ++i) {
        cout << "checking " << passes[i] << endl;
        if (checkpass(passes[i])) cout << "OK" << endl;
        cout << endl;
    }
}
