// Messin with C++17 variant:

#include <any>
#include <string>
#include <vector>
#include <variant>
#include <optional>
#include <iostream>

using namespace std;

/* std::any<> allows heterogenous data storage. As always,
be careful... do you /really/ need any, and not variant? Remember,
std::any<> is type erasure... */
void demo_any()
{
 if(any a = string("Hello, World!"); a.has_value())
 try
  {
	cout << "yep, any has a value! Isn't that grand?\n";

	// To get a value back, you'll have to cast it:
	cout << "got: " << any_cast<string>(a) << '\n';
  }
 catch(bad_any_cast& e)
  {
	cout << "Oops: " << e.what() << '\n';
  }
 else
  {
	cout << "Nope, no value!\n";
  }

 vector<any> xs { string("hi"), 1, 2.0 };

 try
  {
	cout << "xs[0] = " << any_cast<string>(xs[0]) << '\n';
	cout << "xs[1] = " << any_cast<int>(xs[1]) << '\n';
	cout << "xs[2] = " << any_cast<float>(xs[2]) << '\n';	// JFW: note that this will throw, correct type is double
  }
 catch(bad_any_cast&e )
  {
	cout << "Oops: " << e.what() << '\n';
  }
}

/* std::variant<> is a discriminated union. Unlike any<>, it holds an object that
belongs to a fixed range of types: */
void demo_variant()
{
 variant<int, float, string> v;

 v = string("hi");
 cout << get<string>(v) << '\n';

 v = 2.0f;
 cout << get<float>(v) << '\n';

 v = 3;
 cout << get<int>(v) << '\n';
}

/* std::optional<> is similar to Haskell's Maybe monad. It either holds a value or does
not, but compared to a pointer, it is never in an invalid state: to retrieve a value, 
you MUST check for the presence of the value: */
void demo_optional()
{
 if(optional<string> s; s)
  cout << "well, this shouldn't happen!\n"; // s should be empty!
 else
  cout << "s is empty.\n";

 if(optional<string> s { "hello!" }; s)
  cout << "s = " << *s << '\n';
 else
  cout << "well, this shouldn't happen!\n"; // s should have a value!

 /* Note that this will compile, but is /undefined behavior/! 
  optional<string> s;
  cout << *s << '\n'; */

 optional<string> s = "Greetings, Programs!";
 auto reaction = s.value_or("Sark");	// never allow Sark-- fight for the Users!!

 cout << *s << '\n';
}

int main()
{
 demo_any();
 demo_variant();
 demo_optional();
}
