#include "Hall.hpp"

int main() {

	Hall h1(1,2,3);
	Hall h2(2,3,4);
	Hall h3(h2);
	h1.print();
	return 0;
}