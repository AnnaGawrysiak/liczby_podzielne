 /*
 Usuñ wszystkie duplikaty, poza tymi, które s¹ podzielne przez 3 lub 13.
 Posortuj vector w nastêpuj¹cej kolejnoœci - najpierw liczby podzielne przez 3, potem podzielne przez 13,
 potem ca³a reszta - nie zmieniaj kolejnoœci wylosowanych liczb.
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

bool divisibility ( int number);

int main()
{
    srand(time(NULL));

    vector <int> numbers (1000);

    generate(numbers.begin(), numbers.end(), random_number);

    numbers.erase(remove_if(numbers.begin(), numbers.end(),divisibility),numbers.end());

    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(std::cout, " "));

    return 0;
}

int random_number()
{
    //random_device rd; // used to initialize seed engine
    //mt19937 rng(rd());
   // uniform_int_distribution<int> uni(1,59);
    //auto random_integer = uni(rng);
    //int number = random_integer;

    //cout << rd.entropy() << endl;

    int number = rand()%MAX_NUM;

    cout << number << endl;

    return number;
}

bool divisibility ( int number)
{
    if(number%3==0||number%13==0)
        return true;

    return false;
}
