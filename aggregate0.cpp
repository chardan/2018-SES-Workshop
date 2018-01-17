// Aggregate initialization (C++11):

#include <vector>
#include <iostream>

using namespace std;

struct my_type
{
 int x		= 0;
 float y	= 0.0;

 string s;
};

my_type f()
{
 return { 1, 2.0, "whee!" };
}

int main()
{
 my_type x { 1, 2.0, "three" };

 vector<my_type> xs {
						{ 1, 2.0, "three" },
						{ 2, 4.0, "six" },
						{ 3, 8.0, "nine" }
					};

 auto ar = f();
}
