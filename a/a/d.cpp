#include <iostream>
#include <string>
using namespace std;


class base {
public:
  int x;
};


class child: public base {
public:
  int a;
};


void main() {
	string str;
	str = "--s --js=p|s";
	base* p = new child;
  cout << ((child*)p)->a;
}