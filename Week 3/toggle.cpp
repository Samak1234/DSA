#include <iostream>
#include <cctype>   // for isupper, islower, toupper, tolower
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
        else if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }

    cout << "Toggled string: " << str << endl;
    return 0;
}
/*#include <cctype>

This includes a library that provides functions like:
isupper() → checks if a character is uppercase
islower() → checks if a character is lowercase
toupper() → converts to uppercase
tolower() → converts to lowercase*/