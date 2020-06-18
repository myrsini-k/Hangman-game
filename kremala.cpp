#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;

void print_word (string key , bool found [], int lives) {
        for (int i = 0; i < key.length(); i = i + 1) {
        if (found[i] == true) cout << key[i];
        else cout << "*";
    }
    cout << " Remaining lives: " << lives << endl;
}

int main () {
    int lives = 5;
    cout << "Give me a word in capitals" << endl;
    string word;
    cin >> word;
    bool validword = false;
    while (! validword) { //tsekarw an einai egyrh h lexh mou
        if (word.length() < 4) {
            cout << "too short word try again" << endl;
            cin >> word;
            continue;
        }
        else if (word.length() > 20) {
            cout << "too long word try again" << endl;
            cin >> word;
            continue;
        }
        else {
            bool capital = true;
            int i = 0;
            for (i; i < word.length(); i = i + 1) {
                if (!isupper(word[i])) {
                    cout << "your word is invalid try again" << endl;
                    capital = false;
                    break;
                }
            }
            if (capital == false) {
                cin >> word;
                continue;
            }
        }
        validword = true;
    }

    bool found_letter[word.length()];

    int i = 0;
    for (i; i < word.length(); i++) {
        found_letter[i] = false;
    }
    system("cls");
    print_word(word, found_letter, lives);

    int remaining = word.length();
    while (remaining > 0 && lives > 0) {
        cout << "give me a capital letter" << endl;
        char letter;
        cin >> letter;
        bool flag = false;
        if (isupper(letter) == false) {
            cout << "you did not give me a capital letter" << endl;
            continue;
        }
        int i = 0;
        for (i; i < word.length(); i++) {
            if (letter == word[i]) {
                if (found_letter[i] == true) {
                cout << "you have given me that letter before try again" << endl;
                break;
            }
                found_letter[i] = true;
                remaining = remaining - 1;
                flag = true;
            }
        }
        if (flag == false) {
            lives = lives - 1;
        }
        print_word(word, found_letter, lives);
    }

    if (lives == 0) cout << "I am sorry you lost the word was : " << word <<endl;
    else cout << "Congratulations you won the word was : " << word << endl;
}