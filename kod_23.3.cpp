/*
3.
Usuñ wszystkie duplikaty, poza tymi, które s¹ podzielne przez 3 lub 13. Posortuj vector w nastêpuj¹cej kolejnoœci
 - najpierw liczby podzielne przez 3, potem podzielne przez 13, potem ca³a reszta - nie zmieniaj kolejnoœci wylosowanych liczb.

3**. Je¿eli chcesz mocnego utrudnienia dla powy¿szego zadania, to jest takie :)
Trzeba je wykonaæ bez tworzenia dodatkowego kontenera na dane, czyli np. bez dodatkowego vectora.
*/

// najpierw posortuj tak, zeby elemnety podzielne przez 3 znalaz³y sie na poczatku (uzwyj wlasnej funkcji do sortowania), ustaw pozycje pierwszego elementu niepodzielnego przez 3, nastepnie podzielne przez 13, potem ustaw wektor na pirwszej liczbie niepodzielnej przez 3 ani przez 13 i usun duplikaty pozostaych liczb

#include <iostream>
#include <vector>
#include <algorithm>
#include<time.h>
#include<stdlib.h>
#include <iterator> // for ostream_iterator

#define MAX_NUM 59

using namespace std;

int random_number();

bool pred3(int a, int b);

bool pred13 (int a, int b);

int main()
{
    srand(time(NULL));

    vector <int> numbers (1000);

    generate(numbers.begin(), numbers.end(), random_number);

    cout << "Vector elements: " << endl;

    cout << endl;

    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));

    // posortuj tak, aby podzielne przez 3 by³y na poczatku

    sort(
    numbers.begin(),
    numbers.end(),
    pred3);

    // ustal pozycje pierwszego elementu niepodzielnego przez 3

    int position_of_first_element_nondivisible_by_3 = 0;

     vector <int> :: iterator it = find_if(numbers.begin(), numbers.end(), [&numbers] (const int &number)
                                       {
                                           return number%3 != 0;
                                       });

    if (it != numbers.end())
    {
        position_of_first_element_nondivisible_by_3 = (it - numbers.begin() + 1);
    }


    // przesuniecie liczb podzielnych przez 13 za liczby podzielne przez 3


    sort(
    numbers.begin() + position_of_first_element_nondivisible_by_3,
    numbers.end(),
    pred13);

     // ustal pozycje pierwszego elementu niepodzielnego przez 3

    vector <int> :: iterator it2 = find_if(numbers.begin(), numbers.end(), [&numbers] (const int &number)
                                       {
                                           return (number%3 != 0);
                                       });

    int position_of_first_element13 = 0;

    if (it2 != numbers.end())
    {
        position_of_first_element13 = (it2 - numbers.begin() + 1);
    }

    // przesun liczby podzielne przez 13 za liczby podzielne przez 3, a przed pozostale

    sort(
    numbers.begin() + position_of_first_element13,
    numbers.end(),
    pred13);

    // ustal pozycje pierwszego elementu niepodzielnego przez 3

    vector <int> :: iterator it3 = find_if(numbers.begin(), numbers.end(), [&numbers] (const int &number)
                                       {
                                           return (number%3 != 0 && number%13 != 0);
                                       });

    int position_of_first_element = 0;

    if (it3 != numbers.end())
    {
        position_of_first_element = (it3 - numbers.begin() + 1);
    }

    // Usuñ wszystkie duplikaty z pozostalego zakresu.

    unique(numbers.begin() + position_of_first_element, numbers.end());

    cout << "Vector contents: " << endl;

    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));

    return 0;
}

int random_number()
{
    int number = rand()%MAX_NUM;

    return number;
}

bool pred3 (int a, int b)
{
    if (a%3==0&& b%3!=0)
        return a < b;
     else
        return false;
}

bool pred13 (int a, int b)
{
    if (a%13==0&& b%13!=0)
        return a < b;
     else
        return false;
}

