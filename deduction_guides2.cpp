/* Deduction guides can be used for what used to be called POD types! */

#include <string>
#include <iostream>

using namespace std;

template <typename T>
struct some_data
{
 T k, v;
};

some_data(const char *a, const char *b) -> some_data<string>;

int main()
{
 some_data d { "Hello", "World!" };

 cout << d.k << " => " << d.v << '\n';
}
