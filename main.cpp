#include <cstring>
#include "UnitTest.hpp"
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

void TestCompoundAssignmentOperations(UnitTest unit) {

	int *p = new int[5];
	int *tmp = p;
	for (int i = 0; i < 5; i++) { p[i] = i<<1; }

	std::vector<int>::iterator it(p);

	unit.assertEqual(*(p + 3), *(it + 3));
	bool equal = true;
	for (size_t i = 0; i < 5; i++) {
		if (*it++ != *p++) {
			equal = false;
		}
	}
	unit.assertTrue(equal);

	unit.assertEqual(*(p - 3), *(it - 3));

	for (size_t i = 0; i < 5; i++) {
		if (*--it != *--p) {
			equal = false;
		}
	}

	unit.assertTrue(equal);
	for (size_t i = 0; i < 1; i++) {
		if (it[i] != p[i]) {
			equal = false;
		}
	}
	unit.assertTrue(equal, "nem lembro");

	p += 4;
	it += 4;
	unit.assertEqual(*p, *it);

	p -= 2;
	it -= 2;
	unit.assertEqual(*p, *it);

	delete[] tmp;
}


int main( void ) {

	testlist suit = {testCopyConstructor, TestCompoundAssignmentOperations};

	UnitTest one(" pera ", "basnan");

	testSuite("normal_and_reverse_iterators", suit, one);
	return (0);
}

	// testlist vecsize = {testVectorSize};

	// testSuite("vector_size", vecsize, 1);