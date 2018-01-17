// Some fun with structured bindings!

#include <tuple>
#include <string>
#include <iostream>

using std::cout;
using std::tuple;
using std::string;

auto bletch()
{
 return tuple(1, "hi", 2);
}

auto bax() -> tuple<int, int, string>
{
 return { 1, 2, "hi" };
}

struct foo
{
 int x = 1;
 double d = 2.5;
 string s = "hello!";
};

foo g()
{
 return { 2, 3.2, "yo!" };
}

int main()
{
 {
 auto [x, y, z] = bletch();
 cout << x << ", " << y << ", " << z << '\n';
 }
 {
 auto [x, y, z] = g();
 cout << x << ", " << y << ", " << z << '\n';
 }
 {
 auto [x, y, z] = bax();
 cout << x << ", " << y << ", " << z << '\n';
 }

 if(auto [x, y, z] = bax(); (x < y) && (y > 1))
  cout << "y > 1! z = " << z << '\n';
 else
  cout << "nope!\n";

 // Structured bindings with an array:
 {
 int xs[] = { 0, 1, 2, };
 auto [a, b, c] = xs;

 a = 10;
 cout << xs[0] << '\n';

 auto& [d, e, f] = xs;

 d = 10;
 cout << xs[0] << '\n';
 }

 // Structured bindings with a tuple:
 {
 int x = 10;
 string s = "hello";
 double d = 123.456;

 auto tp = tie(x, s, d);

 auto& [a, b, c] = tp;
 cout << a << ", " << b << ", " << c << '\n';
 }

 // Structured bindings and classes:
 {
	struct { int x = 10; string s = "hello"; double d = 123.5; } foo;

    auto& [a, b, c] = foo;
    cout << a << ", " << b << ", " << c << '\n';
 }

}
