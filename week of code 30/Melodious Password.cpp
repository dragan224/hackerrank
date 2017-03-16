#include <bits/stdc++.h>

using namespace std;

string consonants = "bcdfghjklmnpqrstvwxz";
string vowels = "aeiou";

void traverse(int len, int is_vowel, string password) {
    if (len == 0) {
        printf("%s\n", password.c_str());
        return;
    }
    
    if (is_vowel) {
        for (int i = 0; i < vowels.length(); i++) {
            password.push_back(vowels[i]);
            traverse(len - 1, is_vowel ^ 1, password);
            password.pop_back();
        }
    } else {
        for (int i = 0; i < consonants.length(); i++) {
            password.push_back(consonants[i]);
            traverse(len - 1, is_vowel ^ 1, password);
            password.pop_back();
        }
    }
}

int main(){
    int n;
    cin >> n;
    traverse(n, 0, "");
    traverse(n, 1, "");
    return 0;
}

