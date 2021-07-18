#include <iostream>
#include <string>
using namespace std;

 string test() {
	string s1("1");
	string s2("2");
	string temp(s1 + s2);
	return temp;
}

int main() {
	test();
	return 0;
}