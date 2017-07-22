#include <iostream>
#include <clocale>
#include <conio.h>

using namespace std;

int main()
{
    setlocale(LC_CTYPE,"Spanish");

    cout << endl << endl << "\t\t Máximo" << endl << endl;

    int n,maximo;

    cout << endl << "Ingrese números  (finalice con -1):" << endl;
    cin >> n;

    maximo=n;

    while(n!=-1)
    {
        if(n>maximo)
            maximo=n;

        cin >> n;
    }

    cout << endl << "Máximo: \t" << maximo << endl;

    cout << endl << endl << "\t\t\t\t\t Fin del programa \a" << endl << endl;

    getch();
    return 0;
}
