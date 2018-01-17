// C++17 allows you to add an attribute list to a namespace:

// *Nested* namespaces cannot have attributes:
// namespace [[deprecated]] foo::bar::bax {
namespace [[deprecated("we don't do it this way any more")]] foo {

int f() [[nodiscard]] { return 1; }

} // namespace foo

int main()
{
 foo::f();
}
