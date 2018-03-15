#include <vector>
#include <iostream>
#include <csv_reader.h>
#include <logger.h>
#include <fstream>
#include <map>
#include <iomanip>

using namespace std;

extern string field_number, field_year, field_month, field_day, field_hour, field_pm_value,field_dwep,field_temperature, field_pressure,field_cbwd,field_iws,field_is,field_ir;

extern int field_number_index, field_year_index, field_month_index, field_day_index, field_hour_index, field_pm_value_index,field_dwep_index,field_temperature_index,field_pressure_index,field_cbwd_index,field_iws_index,field_is_index,field_ir_index;

vector<vector<string> > CsvReader :: read_csv(map<string, map<string, int> >& freq_table){

	INFOLOG("Start reading csv file for input.\n");



	map<string, map<string, int> >::iterator outerit;
	map<string, int>::iterator innerit;
	vector<vector<string> > csv_data;
	vector<string> tuple;
	string number, year, month, day, hour, pm_value,dwep,temperature, pressure,cbwd,iws,is,ir;
	string csv_file_name = "/Users/vishaljasrotia/eclipse-workspace/star_cubing_algorithm/input/PRSA_data_2010_2014.csv";

	ifstream csv_file(csv_file_name);

	if(!csv_file.is_open()){
		ERRORLOG("Problem in file open()\n");
		return csv_data;
	}




	// read field names
    getline ( csv_file, field_number, ',' );
    //freq_table[field_number] = map<string, int>();
    //field_number_index = 0;

    getline ( csv_file, field_year, ',' );
    //freq_table[field_year] = map<string, int>();
    //field_year_index = 1;

    getline ( csv_file, field_month, ',' );
    //freq_table[field_month] = map<string, int>();
    //field_month_index = 2;

    getline ( csv_file, field_day, ',' );
    //freq_table[field_day] = map<string, int>();
    //field_day_index = 3;

    getline ( csv_file, field_hour, ',' );
    //freq_table[field_hour] = map<string, int>();
    //field_hour_index = 4;

    getline ( csv_file, field_pm_value, ',' );
    freq_table[field_pm_value] = map<string, int>();
    field_pm_value_index = 0;

    getline ( csv_file, field_dwep, ',' );
    //freq_table[field_dwep] = map<string, int>();
    //field_dwep_index = 1;

    getline ( csv_file, field_temperature, ',' );
    freq_table[field_temperature] = map<string, int>();
    field_temperature_index = 1;


    getline ( csv_file, field_pressure, ',' );
    freq_table[field_pressure] = map<string, int>();
	field_pressure_index = 2;

    getline ( csv_file, field_cbwd, ',' );
    freq_table[field_cbwd] = map<string, int>();
	field_cbwd_index = 3;

    getline ( csv_file, field_iws, ',' );
    //freq_table[field_iws] = map<string, int>();
	//field_iws_index = 5;

    getline ( csv_file, field_is, ',' );
    //freq_table[field_is] = map<string, int>();
	//field_is_index = 11;

    getline ( csv_file, field_ir, '\n' );
    //freq_table[field_ir] = map<string, int>();
	//field_ir_index = 12;




	while ( csv_file.good() )
	{
	     getline ( csv_file, number, ',' );
	     //tuple.push_back(number);
	     getline ( csv_file, year, ',' );
	     //tuple.push_back(year);
	     getline ( csv_file, month, ',' );
	     //tuple.push_back(month);
	     getline ( csv_file, day, ',' );
	     //tuple.push_back(day);
	     getline ( csv_file, hour, ',' );
	     //tuple.push_back(hour);



	     getline ( csv_file, pm_value, ',' );
	     tuple.push_back(pm_value);



	     getline ( csv_file, dwep, ',' );
	     //tuple.push_back(dwep);


	     getline ( csv_file, temperature, ',' );
	     tuple.push_back(temperature);
	     getline ( csv_file, pressure, ',' );
	     tuple.push_back(pressure);
	     getline ( csv_file, cbwd, ',' );
	     tuple.push_back(cbwd);





	     getline ( csv_file, iws, ',' );
	     //tuple.push_back(iws);

	     getline ( csv_file, is, ',' );
	     //tuple.push_back(is);

	     getline ( csv_file, ir, '\n' );
	     //tuple.push_back(ir);

		 const char *hour_string = hour.c_str();
		 const char *day_string = day.c_str();
		 //if( atoi(day_string)%3 == 0 && atoi(day_string) != 0 && atoi(hour_string)%23 == 0 && atoi(hour_string) != 0){
		//	 tuple.clear();
		//	 continue;

		 //}


		 if(  atoi(day_string)%2 == 0 && atoi(hour_string) == 12  ){

		 }else{
			 tuple.clear();
			 continue;
		 }


		 csv_data.push_back(tuple);
	     tuple.clear();

	     if(INFO){
	    	 	 string  info_log = number + " : " + year + "/"+month +"/" + day + ":"+hour+", pm value : " +pm_value + \
	    	 			 ", dwep : " + dwep + ", temperature : " + temperature + ", pressure : "+ pressure;
	    	 	 const char *log_string = info_log.c_str();
	    	 	 INFOLOG("%s\n",log_string);
	     }


	     //record freq of value for earch attrbute

	     //record

	     freq_table[field_pm_value][pm_value]++;
	     freq_table[field_temperature][temperature]++;
	     freq_table[field_pressure][pressure]++;
	     freq_table[field_cbwd][cbwd]++;



//	     innerit = freq_table[field_pm_value].find(pm_value);
//	     if(innerit != freq_table[field_pm_value].end()){
//	    	 	 innerit->second++;
//	     }else{
//	    	 	 freq_table[field_pm_value][pm_value] = 1;
//	     }
//	     innerit = freq_table[field_dwep].find(dwep);
//		 if(innerit != freq_table[field_dwep].end()){
//			innerit->second++;
//		 }else{
//			freq_table[field_dwep][dwep] = 1;
//		 }
//
//		 innerit = freq_table[field_temperature].find(temperature);
//		 if(innerit != freq_table[field_temperature].end()){
//			innerit->second++;
//		 }else{
//			freq_table[field_temperature][temperature] = 1;
//		 }
//
//		 innerit = freq_table[field_cbwd].find(cbwd);
//		 if(innerit != freq_table[field_cbwd].end()){
//			innerit->second++;
//		 }else{
//			freq_table[field_cbwd][cbwd] = 1;
//		 }


	}

	return csv_data;
}

void CsvReader :: printdata(vector<vector<string> > &csvdata){



	for(int i = 0; i < csvdata.size() ; i++ ){
		cout <<  setw(14)<< csvdata[i][0]  <<  ", " << setw(14)<< csvdata[i][field_temperature_index] <<setw(14) <<   csvdata[i][field_pressure_index] << setw(14) <<   csvdata[i][field_cbwd_index] << setw(5) << csvdata[i][field_cbwd_index+1] << endl;
		//printf("%13s\n", csvdata[i][field_temperature_index]);

		//cout << csvdata[i][field_number_index] + " : " + csvdata[i][field_year_index]  + "/"+csvdata[i][field_month_index]  +"/" + csvdata[i][field_day_index]  + ":"+csvdata[i][field_hour_index] +", pm value : " +csvdata[i][field_pm_value_index] + \
		//		", dwep : " + csvdata[i][field_dwep_index]  + ", temperature : " + csvdata[i][field_temperature_index]  + ", pressure : "+ csvdata[i][field_pressure_index] <<endl;;
	}
	cout << "Number of tuples : " << csvdata.size()  <<endl;
	cout << "Number of atrributes : " << csvdata[0].size()  <<endl;
}
