/* A little fun with fold expressions! Fold-expressions give you a nicer syntax for
writing many recursive variadic template functions. */

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// Example of an rfold against the comma operator, which is the
// sequencing operator:
template <typename ...FnS>
auto my_for_each(string& s, FnS&& ...fns)
{
 return (fns(s), ...);
}

void upcase(string& s)
{
 transform(begin(s), end(s), begin(s),
           [](auto c) { return toupper(c); });
}

void sort_s(string& s)
{
 sort(begin(s), end(s));
}

int main()
{
 auto sort_s = [](auto& seq) { return sort(begin(seq), end(seq)); };

 string s { "hello, there!" };

 my_for_each(s, &upcase, sort_s, [](auto& s) { s += '\n'; });
 
 cout << s;
}
