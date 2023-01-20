#include <iostream>
#include "UnitTest.hpp"

void asdasd(UnitTest& unit) {
	unit.assertTrue(false);
	unit.assertTrue(false);
}

void sla(UnitTest& unit) {
	unit.assertTrue(true);
	unit.assertTrue(false);
}

void xx(UnitTest& unit) {
	unit.assertTrue(true, "Banana");
}

void THESUIT2(UnitTest& unit) {
	xx(unit);
	sla(unit);
	asdasd(unit);
}

void THESUIT(UnitTest& unit) {
	asdasd(unit);
	sla(unit);
	xx(unit);
}


int main( void ) {
	UnitTest one;

	one.addSuit(THESUIT, "ALL");
	one.addSuit(THESUIT2, "NOT ALL");
	one.run();
	one.status();
	one.clear();
	return(one.exitStatus());
}
