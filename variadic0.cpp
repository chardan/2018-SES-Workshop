/* Tiny demo of parameter packs, variadic templates, and template fold expressions: */

#include <iostream>

using namespace std;

template <typename FnT, typename ...TS>
void apply_each(FnT& f, TS ...ts)
{
 (f(ts), ...);
}

int main()
{
 auto p = [](const auto& x) { cout << x << '\n'; };

 apply_each(p, 1, 2, "three", 4.2);
}
