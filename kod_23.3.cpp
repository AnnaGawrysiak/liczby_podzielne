 /*
 Usu� wszystkie duplikaty, poza tymi, kt�re s� podzielne przez 3 lub 13.
 Posortuj vector w nast�puj�cej kolejno�ci - najpierw liczby podzielne przez 3, potem podzielne przez 13,
 potem ca�a reszta - nie zmieniaj kolejno�ci wylosowanych liczb.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include<time.h>
#include<stdlib.h>
#include <iterator> // for ostream_iterator

#define MAX_NUM 59

using namespace std;

int random_number();

bool pred(int a, int b);

void remDup(vector <int> &v);

int main()
{
    srand(time(NULL));

    vector <int> numbers (1000);

    generate(numbers.begin(), numbers.end(), random_number);

    remDup(numbers);

    //numbers.erase(remove_if(numbers.begin(), numbers.end(),divisibility),numbers.end());

    cout << "Vector after duplicates being erased: " << endl;

    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));

    return 0;
}

int random_number()
{
    int number = rand()%MAX_NUM;

    cout << number << endl;

    return number;
}

bool pred (int a, int b)
{
    if ((a == b && a%3!=0)||(a == b && a%13!=0)||(a == b && b%3!=0)||(a == b && b%13!=0))
        return true;
     else
        return false;
}


void remDup(vector <int> &v)
{
    // sorting vector
    sort(v.begin(), v.end());

    // using unique() method
    // to remove duplicates
   auto ip = unique(v.begin(), v.end(), pred);

    // resize the new vector
    v.resize(distance(v.begin(), ip));

}
