
#include <tuple>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
struct wombat
{
 T x;
};

wombat(const int) -> wombat<float>;

template <typename T>
struct some_data
{
 T k, v;
};

some_data(const char *a, const char *b) -> some_data<string>;

int main()
{
 // Some built-in deduction guides-- now quite pervasive in the standard library:
 vector ns { 1, 2, 3, 4, 5 };
 vector xs { "Hello", "there", "world!" };
 vector<string> ys { "Hello", "there", "world!" };

 // ...again, notice the lack of explicit template parameters (from deduction guides):
 std::tuple zs { 1, 'c', "foo", 3.0 };

 // A type constructed with a user-defined deduction guide:
 wombat w { 5 };

 /* Deduction guides can be used for what used to be called POD types! */
 some_data d { "Hello", "World!" };

 cout << d.k << " => " << d.v << '\n';
}
