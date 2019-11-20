#include <iostream>
#include <string>
using namespace std;

void Problem4a(string input);

int main() {
    string input = "";

    cout << "enter what you want reversed ";
    getline(cin, input);
    cout << "The reversed input is ";
    Problem4a(input);
    cout << endl;
    return 0;
}

void Problem4a(string input) {
    if (input == "")
    {
        return;
    } else
    {
        Problem4a(input.substr(1));
        cout << input.at(0);
    }
}
