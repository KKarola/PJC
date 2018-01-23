#include <iostream>
using namespace std;

int sizeChar(const char* s)
{
   int i = 0;
   while(s[i] != '\0') {
    i++;
   }
   return i;
}

bool isLegal(const char* s)
{
    int sLen = sizeChar(s);
    for(int i = 0; i < sLen; i++) {
        if(!((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90) || s[i] == 32 || s[i] == 44 || s[i] == 46)) {
            return false;
        }
    }

    return true;
}

int numbOfLetters(const char* s)
{
    int sLen = sizeChar(s);
    int letters = 0;
    for(int i = 0; i < sLen; i++) {
        if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90)) {
            letters++;
        }
    }
    return letters;
}

int numbOfDiffLetters(const char* s)
{
    int sLen = sizeChar(s);
    int theSame = 0;
    int diffLett = 0;
    for(int i = 0; i < sLen; i++) {
        if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90)) {
            theSame = 0;
            for(int j = 0; j < i; j++) {
                if(s[i] == s[j] || (s[i] == (s[j] + 32)) || (s[i] == (s[j] - 32))) {
                    theSame = 1;
                }
            }
            diffLett = diffLett + 1 - theSame;
        }
    }

    return diffLett;

}

void mostFrequentLetter(const char* s)
{
    int sLen = sizeChar(s);
    int mostFrequentLetter = 0;
    int amount;
    char letter;

    for(int i = 0; i < sLen; i++) {
        if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90)) {
            amount = 1;
            for(int j = i+1 ; j < sLen; j++) {
                if(s[i] == s[j] || (s[i] == (s[j] + 32)) || (s[i] == (s[j] - 32))) {
                    amount++;
                }
            }

            if(amount > mostFrequentLetter) {
                mostFrequentLetter = amount;
                letter = s[i];
            }
        }
    }

    if(letter >= 97 && letter <= 122) {
       cout << (char) (letter - 32) << "/" << (char) letter << " occurs " << mostFrequentLetter << " times" << endl;
    } else {
       cout << (char) (letter) << "/" << (char) (letter + 32) << " occurs " << mostFrequentLetter << " times" << endl;
    }

}

void allLetters(const char* s)
{
    int sLen = sizeChar(s);
    const int tabSize = numbOfDiffLetters(s);
    char tab[tabSize];
    bool rozne;
    int k = 0;

    for(int i = 0; i < sLen; i++) {
        rozne = true;
        if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90)) {
            for(int j = 0 ; j < tabSize; j++) {
                if(s[i] == tab[j] || (s[i] == (tab[j] + 32)) || (s[i] == (tab[j] - 32))) {
                   rozne = false;
                }
            }
            if(rozne) {
                if(s[i] >= 97 && s[i] <= 122) {
                    tab[k] = (char) (s[i] - 32);
                } else {
                    if(s[i] >= 65 && s[i] <= 90)
                        tab[k] = s[i];
                }
                k++;
            }

        }
    }

    for(k = 0; k < tabSize; k++) {
        cout << tab[k];
    }

}
int main()
{
    const char str[] =
        "To be, or not to be, that is the question";
// 1.
    bool legal = isLegal(str);
    if (!legal)
    {
        cout << "Illegal string" << endl;
        return 1;
    }
    cout << "String OK" << endl;

// 2.
    int letters = numbOfLetters(str);
    cout << letters << " letters" << endl;

// 3.
    int diffLett = numbOfDiffLetters(str);
    cout << diffLett << " different letters" << endl;

// 4.
    mostFrequentLetter(str);

// 5.
    allLetters(str);

}
