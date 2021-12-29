#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf)
{
    if (ques.size() == 0)
    {
        cout << asf << endl;
        return;
    }
    int curr_key = ques[0] - '0';
    for (char c : codes[curr_key])
    {
        printKPC(ques.substr(1), asf + c);
    }
}

int main()
{
    string str;
    cin >> str;
    printKPC(str, "");
}