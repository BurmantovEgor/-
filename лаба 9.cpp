#include <iostream>
#include <string>
using namespace std;

struct country
{
    string name;
    string capital;
    int people;
    int s;
};

struct country1
{
    string name;
    string capital;
    int people;
    int s;
};

void cointry_in(country c[], int kolvo)
{
    for (int i = 0;i < kolvo;i++)
    {
        cout << "Введите название " << i + 1 << " государства: ";
        cin >> c[i].name;
        cout << "Введите столицу " << i + 1 << " государства: ";
        cin >> c[i].capital;
        cout << "Введите численность населения " << i + 1 << " государства: ";
        cin >> c[i].people;
        while (cin.fail() || c[i].people <= 0)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Попробуйте еще раз: " << endl;
            cin >> c[i].people;
        }
        cout << "Введите площадь " << i + 1 << " государства: ";
        cin >> c[i].s;
        while (cin.fail() || c[i].s <= 0)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Попробуйте еще раз: " << endl;
            cin >> c[i].s;
        }
        cout << endl;
    }
}

void cointry_out(country c[], int kolvo)
{
    for (int i = 0;i < kolvo;i++)
    {
        cout << "Название государства: " << c[i].name << endl;
        cout << "Столица государства: " << c[i].capital << endl;
        cout << "Численность населения госудастрва: " << c[i].people << endl;
        cout << "Площадь государства: " << c[i].s << endl;
        cout << endl;
    }
}

int main()
{
    system("chcp 1251>nul");
    int kolvo, chisl, schet = 0, j = 0;
    int people_dop, s_dop;
    string name_dop, capital_dop;
    cout << "Введите количество государств: ";
    cin >> kolvo;
    while (cin.fail() || kolvo <= 0)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Попробуйте еще раз: " << endl;
        cin >> kolvo;
    }

    country c[20];
    cointry_in(c, kolvo);
    cout << "СПИСОК ГОСУДАРСТВ\n";
    cointry_out(c, kolvo);
    cout << "Введите минимальную требуемую численность населения: ";
    cin >> chisl;
    while (cin.fail() || chisl <= 0)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Попробуйте еще раз: " << endl;
        cin >> chisl;
    }
    for (int i = 0;i < kolvo;i++)
    {
        if (c[i].people >= chisl)
        {
            schet++;
        }
    }
    if (schet != 0)
    {
        int num;
        cout << "\nПосле какого элемента вставить новый? \n";
        cin >> num;
        while (cin.fail() || num <= 0)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Попробуйте еще раз: " << endl;
            cin >> num;
        }

        cout << "Введите название новго государства: ";
        cin >> name_dop;
        cout << "Введите столицу нового государства: ";
        cin >> capital_dop;
        cout << "Введите численность населения нового государства: ";
        cin >> people_dop;
        while (cin.fail() || people_dop <= 0)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Попробуйте еще раз: " << endl;
            cin >> people_dop;
        }
        cout << "Введите площадь нового государства: ";
        cin >> s_dop;
        while (cin.fail() || s_dop <= 0)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Попробуйте еще раз: " << endl;
            cin >> s_dop;
        }
        cout << endl;

        country1 c1[20];

        for (int i = 0;i < kolvo;i++)
        {
            if (c[i].people >= chisl)
            {
                c1[j].name = c[i].name;
                c1[j].capital = c[i].capital;
                c1[j].people = c[i].people;
                c1[j].s = c[i].s;
                j++;
            }
        }
        for (int i = 0;i < num - 1;i++)
        {
            c1[i].name = c1[i].name;
            c1[i].capital = c1[i].capital;
            c1[i].people = c1[i].people;
            c1[i].s = c1[i].s;
        }
        for (int i = num + 1;i < schet + 1;i++)
        {
            c1[i].name = c1[i - 1].name;
            c1[i].capital = c1[i - 1].capital;
            c1[i].people = c1[i - 1].people;
            c1[i].s = c1[i - 1].s;
        }
        for (int i = num;i < num + 1;i++)
        {
            c1[i].name = name_dop;
            c1[i].capital = capital_dop;
            c1[i].people = people_dop;
            c1[i].s = s_dop;
        }
        cout << "Обновленный список государств";
        for (int i = 0; i < schet + 1; i++)
        {
            cout << "Название государства: " << c1[i].name;
            cout << endl << "Столица государства: " << c1[i].capital;
            cout << endl << "Численность населения госудастрва: " << c1[i].people;
            cout << endl << "Площадь государства: " << c1[i].s;
            cout << endl;
        }
       
    }
    cout << "\n Такой страны не существует \n";
    return 0;
}
