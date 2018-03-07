#include<iostream>
#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>

#include<csv_reader.h>

using namespace std;
using namespace boost;

int main(){

	cout << "Hello world!!\n"<<endl;

	//funcall();

//	typedef std::istream_iterator<int> in;
//	for_each(in(cin), in(), cout
//					<< (lambda::_1 * 10)
//					<< "\nType in another number: " );

	CsvReader reader;
	reader.printname();
	return 0;
}

