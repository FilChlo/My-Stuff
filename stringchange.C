/*Program used to read string and
 *change all characters uppercase
 *and all number to #.
*/
#include<iostream>
#include<string>
#include<cctype>

using namespace std;

string convertString(string str);

int main()
{
        string input;

        cout << "Enter a sentence: " << endl;
        getline(cin, input, '\n');

        string newline = convertString(input);
        cout << newline << endl;

        return 0;
}

string convertString(string str)
{
        int len = str.size();
        for (int i = 0; i < len; i++) {
                str[i] = toupper(str[i]);
                if (isdigit(str[i])) {
                        str[i] = '#';
                }
        }
        return str;
}

