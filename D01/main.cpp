#include <iostream>
#include <vector>
#include <cctype>
#include <ctime>


using namespace std;

bool myIsAlpha(string name)
{
    for (int i = 0; i < name.length() - 1; i++)
    {
        if (name[i] != ' ' && !isalpha(name[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<string> helloVariation = {"Hello ", "Hello There ", "Hello noob "};
    srand(time(nullptr));
    int helloIndex = rand() % helloVariation.size();

    vector<string> badInputVariation = {"Enter letter with uppercase and name with alphabet characters!!!", "Bad Input try again...", "Try again"};
    int badInput = 0;

    string input;
    cout << helloVariation[helloIndex] << endl;
    while (true)
    {
        cout << "Name and Surname:";
        getline(cin, input);

        if (isupper(input[0]) && myIsAlpha(input))
        {
            break;
        }

        cout << badInputVariation[badInput] << endl;
        badInput++;
        if (badInput == badInputVariation.size())
        {
            badInput = badInputVariation.size() - 1;
        }
    }
    helloIndex = rand() % helloVariation.size();
    cout << helloVariation[helloIndex] << input << endl;

    return 0;
}
