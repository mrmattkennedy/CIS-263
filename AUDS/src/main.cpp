#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file 
#include <algorithm>
#include <string>
#include "catch.hpp"
#include "AUDS.h"

// Test cases take two parameters - the first is a test
// name and the second is a tag.
// This test merely checks that 1 is equal to 1.  It
// should always pass.  It is included here to show how
// to write test cases.

TEST_CASE( "Constructor test", "[creation]" ){
	AUDS<int> a;
	AUDS<float> b;
	AUDS<AUDS<int> > c;
	CHECK( a.size() == 0 );
	CHECK( b.size() == 0 );
	CHECK( c.size() == 0 );
}

TEST_CASE( "Push test", "[inner]" ){
	AUDS<int> a;
	for(int i=0; i<1000; i++){
		a.push(i);
	}
	CHECK( a.size() == 1000 );
}

TEST_CASE( "Pop test", "[inner]" ){
	AUDS<std::string> s;
	for(int i=0; i<1000; i++){
		s.push("Item " + std::to_string(i));
	}
	for(int i=0; i<500; i++){
		std::cout << s.pop() << std::endl;
	}
	CHECK( s.size() == 500 );
}

TEST_CASE("Pop 1 element array", "[inner]" ){
	AUDS<std::string> s;
	for (int i = 0; i < 1000; i++)
		s.push("Item " + std::to_string(i));

	for (int i = 0; i < 999; i++)
		std::cout << s.pop() << std::endl;

	CHECK(s.size() == 1);
	std::cout << "Last pop: " << s.pop() << std::endl;
	CHECK(s.size() == 0);
}


//Should the exception be thrown when there are no objects?
//Or when the actual size is 0? Technically, the array
//is initialized with default values for the 100
//elements, so assuming it's when actual size is 0.
TEST_CASE("Pop past array size", "[inner]" ){
	AUDS<std::string> s;
	for (int i = 0; i < 100; i++)
		s.pop();
//	CHECK(s.pop() == "1");
	
	for (int i = 0; i < 10; i++) {
		REQUIRE_THROWS(s.pop());
	}
}

TEST_CASE("Check actual size after pushing.", "[inner]" ){
	AUDS<std::string> s;
	for (int i = 0; i < 1000; i++)
		s.push(std::to_string(i));

	CHECK(s.size() == 1000);
	CHECK(s.getSize() == 1135);
}

TEST_CASE("Check actual size after popping", "[inner]" ){

	AUDS<std::string> s;

	for (int i = 0; i < 1000; i++)
		s.push(std::to_string(i));

	for (int i = 0; i < 500; i++)
		s.pop();

	CHECK(s.size() == 500);
	CHECK(s.getSize() == 635);
}
