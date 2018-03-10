#include<vector>
#include<iostream>
#include<csv_reader.h>
#include<logger.h>
#include <fstream>
#include<map>
using namespace std;

vector<vector<string> > CsvReader :: read_csv(){

	INFOLOG("Start reading csv file for input.\n");

	string csv_file_name = "/Users/vishaljasrotia/eclipse-workspace/star_cubing_algorithm/input/PRSA_data_2010_2014.csv";

	vector<vector<string> > csv_data;
	ifstream csv_file(csv_file_name);

	string number, year, month, day, hour, pm_value,dwep,temperature, pressure,cbwd,iws,is,ir;


	if(!csv_file.is_open()){
		ERRORLOG("Problem in file open()\n");
		return csv_data;
	}


	vector<string> tuple;

	// read feild names
    getline ( csv_file, number, ',' );
    getline ( csv_file, year, ',' );
    getline ( csv_file, month, ',' );
    getline ( csv_file, day, ',' );
    getline ( csv_file, hour, ',' );
    getline ( csv_file, pm_value, ',' );
    getline ( csv_file, dwep, ',' );
    getline ( csv_file, temperature, ',' );
    getline ( csv_file, pressure, ',' );
    getline ( csv_file, cbwd, ',' );
    getline ( csv_file, iws, ',' );
    getline ( csv_file, is, ',' );
    getline ( csv_file, ir, '\n' );



	while ( csv_file.good() )
	{


	     getline ( csv_file, number, ',' );
	     tuple.push_back(number);
	     getline ( csv_file, year, ',' );
	     tuple.push_back(year);
	     getline ( csv_file, month, ',' );
	     tuple.push_back(month);
	     getline ( csv_file, day, ',' );
	     tuple.push_back(day);
	     getline ( csv_file, hour, ',' );
	     tuple.push_back(hour);
	     getline ( csv_file, pm_value, ',' );
	     tuple.push_back(pm_value);
	     getline ( csv_file, dwep, ',' );
	     tuple.push_back(dwep);
	     getline ( csv_file, temperature, ',' );
	     tuple.push_back(temperature);
	     getline ( csv_file, pressure, ',' );
	     tuple.push_back(pressure);
	     getline ( csv_file, cbwd, ',' );
	     tuple.push_back(cbwd);
	     getline ( csv_file, iws, ',' );
	     tuple.push_back(iws);
	     getline ( csv_file, is, ',' );
	     tuple.push_back(is);
	     getline ( csv_file, ir, '\n' );
	     tuple.push_back(ir);

	     csv_data.push_back(tuple);
	     tuple.clear();

	     if(INFO){
	    	 	 string  info_log = number + " : " + year + "/"+month +"/" + day + ":"+hour+", " +pm_value;
	    	 	 const char *log_string = info_log.c_str();
	    	 	 INFOLOG("%s\n",log_string);
	     }



	}



	return csv_data;
}

void CsvReader :: printname(){
	cout << "Hello World from csv_reader.cpp\n"<<endl;
}

