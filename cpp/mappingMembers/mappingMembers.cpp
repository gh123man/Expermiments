/* 
    By: Brian Floersch (gh123man@gmail.com)
    
    This is some tinkering I did with closures, member pointers, and autos.

    If it works, output wil look like this:
     
        brian@brian-Laptop:~/experiments/cpp/mappingMembers$ ./mappingMembers 
        1
        2
        3
        4
        5
        6
        7
        8
        brian@brian-Laptop:~/experiments/cpp/mappingMembers$
    
*/



#include <map>
#include <string>
#include <iostream>

//some example data structure. 
struct DataTest {
	int a;
	int b;
	int c;
	int d;
};

int main(int argc, char* argv[]) {

	//Create Data member mapping
	std::map<std::string, int DataTest::*> mp;
	mp["a"] = &DataTest::a;
	mp["b"] = &DataTest::b;
	mp["c"] = &DataTest::c;
	mp["d"] = &DataTest::d;

	//create mapping function with mapping pointer
	DataTest* mapPointer;
	auto mapVal = [&] (std::string key, int val) { mapPointer->*(mp[key]) = val; };

	//define some test data sets
	DataTest testData0 = DataTest();
	DataTest testData1 = DataTest();

	mapPointer = &testData0; //set the map pointer to the first data set

    //mapps chars to the struct members using the map pointer
	mapVal("a", 1);
	mapVal("b", 2);
	mapVal("c", 3);
	mapVal("d", 4);

	mapPointer = &testData1; //set the map pointer to the second data set

    //mapps chars to the struct members using the map pointer
	mapVal("a", 5);
	mapVal("b", 6);
	mapVal("c", 7);
	mapVal("d", 8);
	
	auto print = [] (int val) {std::cout << val << std::endl;}; //lazy print function
	
	print(testData0.a);
	print(testData0.b);
	print(testData0.c);
	print(testData0.d);

	print(testData1.a);
	print(testData1.b);
	print(testData1.c);
	print(testData1.d);

	std::cin.get();//easy pause output
	
	return 0;
}



