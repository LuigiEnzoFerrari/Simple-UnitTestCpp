#include <cstring>
#include "../UnitTest.hpp"
#include <vector>
#include <iterator>
#include <bits/stdc++.h>

static std::string *arraySet( void ) {
	std::string *names = new std::string[5];
	names[0] = "Luigi";
	names[1] = "Caio";
	names[2] = "Rafa";
	names[3] = "Adrian";
	names[4] = "Gustavo";
	return (names);
}

void testVectorCapacity(UnitTest unit) {
	std::vector<std::string> vec;
	std::string *names = arraySet();

	unit.assertTrue(vec.empty(), "Expected: True; vec.empty() == 0");
	unit.assertTrue(vec.size() == 0, "Expected: True; vec.size() == 0");
	unit.assertTrue(vec.capacity() == 0, "Expected: True; vec.capacity() == 0");

	vec.reserve(3);
	unit.assertTrue(vec.size() == 0, "Expected: True, reserve(3); vec.size() == 0");
	unit.assertTrue(vec.capacity() == 3, "Expected: True; vec.capacity() == 3");

	vec.resize(6);
	unit.assertFalse(vec.empty(), "Expected: False; vec.empty() != 0");
	unit.assertTrue(vec.size() == 6, "Expected: True, resize(6); vec.size() == 6");
	unit.assertTrue(vec.capacity() == 6, "Expected: True; vec.capacity() == 6");
	delete[] names;
}

void testVectorIterator(UnitTest unit) {
	std::string *names = arraySet();
	std::vector<std::string> vec(names, names + 5);
	std::vector<std::string>::iterator it;

	it = vec.begin();
	unit.assertTrue((*it) == "Luigi", "Expected: Luigi; vec.begin() == Luigi");

	it = vec.end();
	unit.assertTrue((*(it - 1)) == "Gustavo", "Expected: Luigi; vec.end() - 1 == Gustavo");

	std::vector<std::string>::reverse_iterator rit;

	rit = vec.rbegin();
	unit.assertTrue((*rit) == "Gustavo", "Expected: Luigi; vec.rbegin() == Gustavo");

	rit = vec.rend();
	unit.assertTrue((*(rit - 1)) == "Luigi", "Expected: Luigi; vec.rend() - 1 == Luigi");

	delete[] names;
}

/*
** A suit function to run a list full of tests
** The first argument is the name of the set.
** The second argument is the tests list.
** The third argument is optional, you can pass a personalized UnitTest class.
*/

int main( void ) {

	testlist suit = {testVectorIterator, testVectorCapacity};

	testSuite("Vector Iterator", suit);
	return (0);
}
