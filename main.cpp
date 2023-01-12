#include <cstring>
#include "UnitTest.hpp"
#include <vector>
#include <iterator>

void testVecReverse(UnitTest unit) {
	int p[4] = {3, 4, 5, 2};
	std::vector<int> vec(p, p + 4);

	std::vector<int>::reverse_iterator it = vec.rbegin();
	unit.assertEqual(*(it + 2), *(p + 2));
}

void testVecIterator(UnitTest unit = UnitTest()) {
	int p[4] = {3, 4, 5, 2};
	std::vector<int> vec(p, p + 4);

	std::vector<int>::iterator it = vec.begin();
	unit.assertEqual(*(it + 2), *(p + 2));

	it = vec.end();
	unit.assertEqual(*it, p[3]);
}

void testVectorSize(UnitTest unit) {
	std::vector<int> vec;

	unit.assertTrue(vec.empty());

	for (int i = 0; i < 2; i++) {
		vec.push_back(i);
	}
	unit.assertTrue(vec.size() == 2);

}

int main( void ) {
	testlist veciterators = {testVecIterator, testVecReverse};
	testSuite("normal_and_reverse_iterators", veciterators, 2);
	return (0);
}

	// testlist vecsize = {testVectorSize};

	// testSuite("vector_size", vecsize, 1);