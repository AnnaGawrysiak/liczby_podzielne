#include <iostream>
#include <vector>
#include <algorithm>
#include<time.h>
#include<stdlib.h>
#include <iterator> // for ostream_iterator
#include <unordered_set>

#define MAX_NUM 59

using namespace std;

int random_number();

bool pred(int a);

void remDup(vector <int> &v);

int main()
{
    srand(time(NULL));

    vector <int> numbers (1000);

    generate(numbers.begin(), numbers.end(), random_number);

    cout << "Vector elements: " << endl;

    cout << endl;

    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));

    unordered_set<int> myset;

    vector<int>::iterator it;

    for(it = numbers.begin(); it != numbers.end(); it++)
    {
             myset.insert(numbers.at(*it));

    }

    // erase numbers divisible by 13 and 3 from myset

    for (auto iter = myset.begin(); iter != myset.end(); iter++)
    {
        if (pred(*iter))
        {
            myset.erase(iter);
        }

    }

    // isolate numbers divisible by 3 and 13 from initial vector

     vector <int> myvector3;

     vector <int> myvector13;

     int i = 0;

     int j = 0;

    for_each(numbers.begin(), numbers.end(), [&i, &j, &myvector3](int number)
        {
            if(number%3==0)
                myvector3.push_back(number);

        });

    for_each(numbers.begin(), numbers.end(), [&i, &j, &myvector13](int number)
        {

             if(number%13==0)
                myvector13.push_back(number);

        });

    // clear vector contents, preallocate memory and insert new values

    numbers.clear();

    numbers.reserve(myvector3.size() + myvector13.size() + myset.size()); // preallocate memory
    numbers.insert(numbers.end(), myvector3.begin(), myvector3.end());
    numbers.insert(numbers.end(), myvector13.begin(), myvector13.end());

    cout << "Vector contents: " << endl;

   for (auto iter = myset.begin(); iter != myset.end(); iter++)
    {
           numbers.push_back(*iter);
    }

    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));

    return 0;
}

int random_number()
{
    int number = rand()%MAX_NUM;

    return number;
}

bool pred (int a)
{
    if (a%3==0||a%13==0)
        return true;
     else
        return false;
}
