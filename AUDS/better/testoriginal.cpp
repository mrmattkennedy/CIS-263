#include "AUDS.h"
#include <iostream>

int main(int argc, char** argv) {
	AUDS<int> a;

	for (int i = 0; i < 100000; i++)
		a.push(i);
	
	for (int i = 0; i < a.getSize() + 1; i++)
		a.pop();

	for (int i = 0; i < 10000; i++)
		a.push(i);

	AUDS<int> b(a);
	return 1;
}
