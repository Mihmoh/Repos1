#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class MyException
{
private:
    int excep;
public:
    MyException(int except) : excep{ except }
    {

    }
    void answer()
    {
        switch (excep)
        {
        case 1:
            cout << "Exception: error open file" << endl;
            break;
        case 3:
            cout << "Exception: non-numeric value" << endl;
            break;
        }
    }
};

int checkInt()		//функция проверки int
{
    int value = 0;
    while (true) {
        if (cin >> value) {
            break;
        }
        else {
            cin.clear();
            cin.ignore();
            throw MyException(3);
        }
    }
    return value;
}

void continuationCondition() //пауза продолжения
{
    char s;
    rewind(stdin);
    printf("\nPress enter to continue... \n");
    scanf_s("%c", &s);
}

int main()
{
    ifstream sourceFile;
    ofstream resultFile;
    string fileString;
    vector <string> cont;

    try
    {
        sourceFile.open("sourceFile.txt");
        if(!sourceFile)
            throw MyException(1);
    }
    catch (MyException& ex)
    {
        system("cls");
        ex.answer();
        continuationCondition();
    }

    cout << "File sourceFile.txt is opened" << endl << endl;

    while (!sourceFile.eof()) {
        getline(sourceFile, fileString);
        if (fileString == "")
            continue;
        cont.push_back(fileString);
    }

    int stop = 1;

    while(stop)
    {
        try
        {
            system("cls");
            cout << "Content of file: " << endl << endl;

            for (int i = 0; i < cont.size(); i++)
            {
                cout << cont[i] << endl;
            }

            cout << endl << "Enter symbols: " << endl;
            char c, c1, c2;
            string s;
            int quantity_in_string = 0, quantity_in_text = 0, j = 0, length = 0;

            getline(cin, s);
            cin.clear();
            while (s[j] != '\0'&& j < 3)
            {
                j++;
                length++;
            }
            if (length == 1)
            {
                c = s[0];

                j = 0;
                resultFile.open("resultFile.txt");
                if (!resultFile)
                    throw MyException(1);
                resultFile << "Symbol " << c << endl;

                for (int i = 0; i < cont.size(); i++)
                {
                    s = cont[i];
                    while (s[j] != '\0')
                    {
                        if (s[j] == c)
                            quantity_in_string++;
                        j++;
                    }
                    quantity_in_text = quantity_in_text + quantity_in_string;
                    cout << s << " - " << quantity_in_string << " symbols" << endl;
                    resultFile << s << " - " << quantity_in_string << " symbols" << endl;
                    j = 0;
                    quantity_in_string = 0;
                }

                cout << endl << quantity_in_text << " symbols in all the text text" << endl;
                resultFile << endl << quantity_in_text << " symbols in all the text text" << endl;
                quantity_in_text = 0;
                length = 0;
            }
            if (length == 2)
            {
                c = s[0];
                c1 = s[1];

                j = 0;
                resultFile.open("resultFile.txt");
                if (!resultFile)
                    throw MyException(1);
                resultFile << "Symbols " << c << c1 << endl;

                for (int i = 0; i < cont.size(); i++)
                {
                    s = cont[i];
                    while (s[j + 1] != '\0')
                    {
                        if (s[j] == c && s[j + 1] == c1)
                            quantity_in_string++;
                        j++;
                    }
                    quantity_in_text = quantity_in_text + quantity_in_string;
                    cout << s << " - " << quantity_in_string << " symbols" << endl;
                    resultFile << s << " - " << quantity_in_string << " symbols" << endl;
                    j = 0;
                    quantity_in_string = 0;
                }

                cout << endl << quantity_in_text << " combinations in all the text text" << endl;
                resultFile << endl << quantity_in_text << " combinations in all the text text" << endl;
                quantity_in_text = 0;
                length = 0;
            }

            if (length == 3)
            {
                c = s[0];
                c1 = s[1];
                c2 = s[2];

                j = 0;
                resultFile.open("resultFile.txt");
                if (!resultFile)
                    throw MyException(1);
                resultFile << "Symbols " << c << c1 << c2 << endl;

                for (int i = 0; i < cont.size(); i++)
                {
                    s = cont[i];
                    while (s[j + 2] != '\0')
                    {
                        if (s[j] == c && s[j + 1] == c1 && s[ j + 2 ] == c2)
                            quantity_in_string++;
                        j++;
                    }
                    quantity_in_text = quantity_in_text + quantity_in_string;
                    cout << s << " - " << quantity_in_string << " symbols" << endl;
                    resultFile << s << " - " << quantity_in_string << " symbols" << endl;
                    j = 0;
                    quantity_in_string = 0;
                }

                cout << endl << quantity_in_text << " combinations in all the text text" << endl;
                resultFile << endl << quantity_in_text << " combinations in all the text text" << endl;
                quantity_in_text = 0;
                length = 0;
            }
            

            sourceFile.close();
            resultFile.close();

            cout << endl << "Information is written to result file" << endl;
            cout << endl << "Do you want to count another symbol? 1 - yes, 0 - no" << endl;
            stop = checkInt();
            getline(cin, s);
        }
        catch (MyException& ex)
        {
            system("cls");
            ex.answer();
            continuationCondition();
        }
    }      
}

//от одного до трёх символов искать последовательность
