#include <iostream>
#include <string>
using namespace std;

void printEncoding(string str, string asf)
{
    if (str.size() == 0)
    {
        cout << asf << endl;
        return;
    }
    if (str.size() == 1)
    {
        int num = str[0] - '0';
        if (num == 0)
            return;
        cout << asf + (char)('a' + num - 1) << endl;
        return;
    }
    int num1 = str[0] - '0';
    if (num1 == 0)
        return;
    string str1 = str.substr(1);
    printEncoding(str1, asf + (char)('a' + num1 - 1));

    int num2 = stoi(str.substr(0, 2));
    string str2 = str.substr(2);
    if (num2 <= 26)
        printEncoding(str2, asf + (char)('a' + num2 - 1));
}

int main()
{
    string str;
    cin >> str;
    printEncoding(str, "");
}