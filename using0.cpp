/* Inspired by Vandevoorde, Josuttis, Gregor.
	- overloading with parameter packs and 'Using"!
	- see also:
	 http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0195r1.html

*/

#include <string>
#include <iostream>

using namespace std;

struct foo {};

struct base0
{
 void flurp(int) { cout << "base0::flurp(int)\n"; }
};

struct base1
{
 void flurp(foo) { cout << "base1::flurp(foo)\n"; }
};

struct base2
{
 void flurp(string) { cout << "base0::flurp(string)\n"; }
};

struct base3
{
 template <typename T>
 void flurp(const T x) { cout << "whee: " << x << '\n'; }
};

// Here's the magic:
template <typename ...Bases>
struct Wombat : Bases...
{
 using Bases::flurp...; 			// BOOM!
};

int main()
{
 Wombat<base0, base1, base2, base3> wombat;

 wombat.flurp(1);
 wombat.flurp(foo());
 wombat.flurp("hello");
 wombat.flurp(1.0);
}
