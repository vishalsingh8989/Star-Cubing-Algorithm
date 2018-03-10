#include<iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/log/trivial.hpp>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>


#include<csv_reader.h>
#include<logger.h>

using namespace std;
using namespace boost;

int main(){



	INFOLOG("Start Star Cubing Algorithm\n");


	CsvReader reader;
	vector<vector<string> > csv_data = reader.read_csv();


	if(csv_data.size() == 0){
		ERRORLOG("Error in input reading. Data size zero\n");
		return 0;
	}else{
		INFOLOG("Number of tuples : %d\n", (int)csv_data.size());
	}




	return 0;
}

