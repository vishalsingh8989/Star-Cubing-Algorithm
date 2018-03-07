#include<vector>
#include<iostream>
#include<csv_reader.h>
#include<logger.h>
#include <fstream>
using namespace std;

vector<vector<int> > CsvReader :: read_csv(){
	INFOLOG("Start reading csv file for input.\n");
	vector<vector<int> > csv_data;


	ifstream csv_file ( "PRSA_data_2010_2014.csv" );

	string value;

	if(!csv_file.is_open()){
		ERRORLOG("ERROR: Problem in file open()\n");
	}

	while ( csv_file.good() )
	{

	     getline ( csv_file, value, ',' );
	     cout << string( value, 1, value.length()-2 );
	}

	return csv_data;
}

void CsvReader :: printname(){
	cout << "Hello World from csv_reader.cpp\n"<<endl;
}

