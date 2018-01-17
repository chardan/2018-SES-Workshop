/* 
g++ -std=c++17 -Wall -Wextra -pedantic -pthread -o pete pete.cpp
(I used GCC 7.2.1, but this should work with any recent compiler.) 
*/

#include <tuple>
#include <vector>
#include <string>
#include <future>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <type_traits>

// Pure laziness! (And to reduce clutter.)
using namespace std;

// You can declare nested namespaces is one step (C++17):
namespace florkle::bar::bax {

int x = 1;

} // namespace florkle::bar::bax

/* Instead of the Old Hard Way(TM), where you had to give a static member a place
to live, now you can use "inline variables" (C++17): */
struct my_wombat_t
{
 static inline int x = 2; // yay!
};

// ...you don't even need this: inline int my_wombat_t::x = 2; 

// Here's a "regular flavor" return-type deduced function (C++14):
auto bar();
auto bar()
{
 return string("hi!");
}

// The same function in C++11 (which reveals how the C++14 mechanism works):
auto bar2() -> string
{
 return string("hi!");
}

// Returning multiple values is easy now:
auto bax()
{
 return tuple { 1, string("hello!"), 2.5 };
}

/* Notice that the return type varies depending on the compile-time
type evaluation using "constexpr if" (that's how the feature is refered
to, even though it's spelled "if constexpr"). 
	This actually reveals what this feature's actually doing-- it's 
syntactic sugar for the old SFINAE (Substitution Failure Is Not An Error)
technique, but much easier to read and write: */
template <typename T>
auto foo()
{
 if constexpr (is_same<T, string>::value)
  return 5;
 else
  return "hello";
}

int main()
{
 // Notice not only "auto", but also deduced template parameter (C++17):
 auto xs = vector { 1, 2, 3, 4, 5 };

 // Loop (C++11):
 for(const auto& x : xs)
  cout << x << '\n';

 cout << "====\n";

 // Super older-school way (C++98):
 for(std::vector<int>::const_iterator x = xs.begin(); x != xs.end(); ++x)
  cout << *x << '\n';

 // Old-school way (C++11):
 for(std::vector<int>::const_iterator x = begin(xs); x != end(xs); ++x)
  cout << *x << '\n';

 // Old-school way, pt. 2 (C++11):
 for(auto x = begin(xs); x != end(xs); ++x)
  cout << *x << '\n';

 // Range-for (C++11):
 for(const auto& x : xs)
  cout << x << '\n';

 cout << "====\n";

 // Showing off initializer-list a bit:
 for(const auto& x : { 1, 2, 3, 4, 5 })
  cout << x << '\n';

 cout << "====\n";

 // STL and parametrically-typed lambda (ok in C++14):
 for_each(begin(xs), end(xs), 
          [](const auto& x) { cout << x << '\n'; });

 // Using an algorithm (C++11):
 copy(begin(xs), end(xs), ostream_iterator<int>(cout));

 cout << "====\n";

 // Notice that the return type changes with the selected specialization (C++17):
 cout << foo<int>() << '\n';
 cout << foo<string>() << '\n';

 // New if syntax binds a variable to comparitor scope (similar to a for-loop):
 if(auto i = xs[2]; i > 1)
  cout << "yep!\n";
 else
  i = 2;

 // We can easily get at types at compile-time:
 using foo = decltype(xs)::const_iterator;
 using bar = decltype(cbegin(xs));

 if constexpr (is_same<foo, bar>::value)
  cout << "yep, the same!\n";

 // It's easy to assign a lambda to a variable:
 auto fn = [] { return "hi!"; };

 cout << fn() << '\n';

 // Maybe-asynchronously launch a function (compiler/optimizer can choose):
 async([]() { for(int i = 0; i != 10; ++i) cout << "hello!\n"; });

 // Demand asynchronous execution: 
 async(launch::async, []() { for(int i = 0; i != 10; ++i) cout << "also hello!\n"; });
}
