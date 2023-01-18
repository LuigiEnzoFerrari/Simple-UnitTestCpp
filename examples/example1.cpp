#include <cstring>
#include "../UnitTest.hpp"
#include <vector>
#include <iterator>
#include <bits/stdc++.h>

void testCopyConstructor(UnitTest unit) {
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2(it);

	unit.assertTrue(it == it2);

	int *p = new int[5];
	int *tmp = p;
	for (int i = 0; i < 5; i++) { p[i] = i<<1; }

	std::vector<int>::iterator it3(p);
	std::vector<int>::iterator it4(it3);
	unit.assertEqual(*it3, *it4);
	unit.assertEqual(*(it3 + 3), *(it4 + 3));
	delete[] tmp;
}

void testAssignmentOperations(UnitTest unit) {

	int *p = new int[5];
	int *tmp = p;
	for (int i = 0; i < 5; i++) { p[i] = i<<1; }
	std::vector<int>::iterator it(p);

	unit.assertEqual(*(p + 3), *(it + 3), "Expeted: Equal; *(p + 3) == *(it + 3)");

	bool equal = true;
	for (size_t i = 0; i < 5; i++) {
		if (*it++ != *p++) { equal = false;}
	}
	unit.assertTrue(equal, "Expeted: True; *p++ == *it++");

	unit.assertEqual(*(p - 3), *(it - 3), "Expeted: Equal; *(p - 3) == *(it - 3)");

	for (size_t i = 0; i < 5; i++) {
		if (*--it != *--p) {
			equal = false;
		}
	}
	unit.assertTrue(equal, "Expeted: True; *p-- == *it--");

	delete[] tmp;
}

/*
** Simple Functions Using asserts methods 
*/

int main( void ) {
	std::cout << "testCopyConstructor" << std::endl;
	testCopyConstructor(UnitTest());
	std::cout << "testAssignmentOperations" << std::endl;
	testAssignmentOperations(UnitTest());
	return (0);
}
