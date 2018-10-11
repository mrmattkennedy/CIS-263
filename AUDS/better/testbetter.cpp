#include "AUDSbetter.h"
#include <iostream>

int main(int argc, char** argv) {
	AUDS<int> a;
	
/*	
	for (int i = 0; i < 100000; i++)
		a.push(i);
	
	for (int i = 0; i < a.getSize()+1; i++)
		a.pop();
	
	
	for (int i = 0; i < 100000; i++)
		a.push(i);

	AUDS<int> b(a);
*/

	for (int i = 0; i < 100; i++)
		std::cout << a.pop() << std::endl;
	return 1;
}
