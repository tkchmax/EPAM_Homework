#include "Calculator_oop.h"

int main()
{
   // calc();

    string s;
    while (true)
    {
        cout << ">> ";
        getline(cin, s);
        if(s == "q")
            break;
        try
        {
            Calculator(s).go();
        }
        catch (invalid_argument& e)
        {
            cout << e.what() << endl;
        }
   }
}

