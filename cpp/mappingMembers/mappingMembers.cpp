#include <map>
#include <string>
#include <iostream>


struct DataTest {
	int a;
	int b;
	int c;
	int d;
};

int main(int argc, char* argv[])
{
	//Create Data member mapping
	std::map<std::string, int DataTest::*> mp;
	mp["a"] = &DataTest::a;
	mp["b"] = &DataTest::b;
	mp["c"] = &DataTest::c;
	mp["d"] = &DataTest::d;

	//create easy mapping function
	DataTest* dt;
	auto mapVal = [&] (std::string key, int val) { dt->*(mp[key]) = val; };

	//define some test data sets
	DataTest testData = DataTest();
	DataTest testData1 = DataTest();

	//set some data
	dt = &testData;

	mapVal("a", 1);
	mapVal("b", 2);
	mapVal("c", 3);
	mapVal("d", 4);

	dt = &testData1;

	mapVal("a", 5);
	mapVal("b", 6);
	mapVal("c", 7);
	mapVal("d", 8);

	//shortcut print function
	auto print = [] (int val) {std::cout << val << std::endl;};
	
	print(testData.a);
	print(testData.b);
	print(testData.c);
	print(testData.d);

	print(testData1.a);
	print(testData1.b);
	print(testData1.c);
	print(testData1.d);

	//easy pause output
	std::cin.get();

	return 0;

}



