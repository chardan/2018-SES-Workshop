CXX=g++ -std=c++17
#CXX=clang -std=c++1y

CXXFLAGS=-Wall -Wextra -pthread

CXX_CC=$(CXX) $(CXXFLAGS)

all:
	$(CXX_CC) -o pete pete.cpp 
	$(CXX_CC) -o aggregate0 aggregate0.cpp
	$(CXX_CC) -o deduction_guides0 deduction_guides0.cpp
	$(CXX_CC) -o namespace-attrs namespace-attrs.cpp
	$(CXX_CC) -o pete pete.cpp
	$(CXX_CC) -o structured_bindings0 structured_bindings0.cpp
	$(CXX_CC) -o variant_any_optional0 variant_any_optional0.cpp
	$(CXX_CC) -o fold_expressions0 fold_expressions0.cpp
	$(CXX_CC) -o using0 using0.cpp
	$(CXX_CC) -o variadic0 variadic0.cpp
