#include <iostream>
using namespace std;

int main()
{
    char kalimat[] = "aku lapar hari ini ";
    char *p, kar;
    p = kalimat;

    cout << "Kalimat: " << kalimat << endl;

    // ENKRIPSI
    for (int i = 0; i < sizeof(kalimat); i++)
    {
        kar = *p;
        if (kar >= 'a' && kar <= 'z')
        {
        	kar += 3;
            if (kar > 'z')
                kar = kar - 'z' + 'a' - 1;
        }
        if (kar >= 'A' && kar <= 'Z')
        {
        	kar += 3;
            if (kar > 'Z')
                kar = kar - 'Z' + 'A' - 1;
        }
        *p = kar;
        p++;
        if (*p == '\0') break;
    }
    cout << "Enkrip : " << kalimat << endl;

    p = kalimat;
    for (int i = 0; i < sizeof(kalimat); i++)
    {
        kar = *p;
        if (kar >= 'a' && kar <= 'z')
        {
            kar -=3;
            if (kar < 'a')
                kar = kar + 'z' - 'a' + 1;
        }
        if (kar >= 'A' && kar <= 'Z')
        {
            kar -=3;
            if (kar < 'A')
                kar = kar + 'Z' - 'A' + 1;
        }
        *p = kar;
        p++;
        if (*p == '\0') break;
    }
    cout << "Translate : " << kalimat;
}

