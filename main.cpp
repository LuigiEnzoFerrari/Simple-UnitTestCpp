#include <cstring>
#include "UnitTest.hpp"
#include <vector>
#include <iterator>

void testVecReverse(std::string funcName, UnitTest one = UnitTest()) {
	int p[4] = {3, 4, 5, 2};
	std::vector<int> vec(p, p + 4);

	std::vector<int>::reverse_iterator it = vec.rbegin();
	one.assertEqual(*(it + 2), *(p + 2));
}

void testVecIterator(std::string funcName, UnitTest one = UnitTest()) {
	int p[4] = {3, 4, 5, 2};
	std::vector<int> vec(p, p + 4);

	std::vector<int>::iterator it = vec.begin();
	one.assertEqual(*(it + 2), *(p + 2));

	it = vec.end();
	one.assertEqual(*it, p[3]);
}

void testVectorSize(std::string funcName, UnitTest one = UnitTest()) {
	std::vector<int> vec;

	one.assertTrue(vec.empty());

	for (int i = 0; i < 2; i++) {
		vec.push_back(i);
	}
	one.assertTrue(vec.size() == 2);

}

int main( void ) {

	testlist vecsize = {testVectorSize};
	testlist veciterators = {testVecIterator, testVecReverse};
	
	testSuite("vector_size", vecsize, 1);
	testSuite("normal_and_reverse_iterators", veciterators, 2);
	return (0);
}
