#include <iostream>
using namespace std;

void printSS(string ques, string ans)
{
    if (ques.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    string ros = ques.substr(1);
    printSS(ros, ans + ques[0]);
    printSS(ros, ans);
}

int main()
{
    string str;
    cin >> str;
    printSS(str, "");
}