#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/log/trivial.hpp>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <csvreader.h>
#include <logger.h>
#include <startable.h>
#include <startree.h>
#include <starcube.h>

using namespace std;


//iceberg conditions
int temperature_iceberg = 2;
int pressure_iceberg = 2;
int pm_value_iceberg = 2;
int cbwd_iceberg = 2;
int dwep_iceberg = 20;



//star values for each attribute
string temperature_star_val = "*";
string pm_value_star_val = "*";
string pressure_star_val = "*";
string cbwd_star_val = "*";
string dwep_star_val = "dwep*";


//attributes
string field_number, field_year, field_month, field_day, field_hour, field_pm_value,field_dwep,field_temperature, field_pressure,field_cbwd,field_iws,field_is,field_ir;
int field_number_index, field_year_index, field_month_index, field_day_index, field_hour_index, field_pm_value_index,field_dwep_index,field_temperature_index,field_pressure_index,field_cbwd_index,field_iws_index,field_is_index,field_ir_index;



int main(){

	INFOLOG("Start Star Cubing Algorithm\n");


	map<string, map<string, int> > freq_table;
	map<string, string>  star_table;
	map<string, string>  temperature_star_table;
	map<string, string>  pm_value_star_table;
	vector<vector<string> > csv_data;
	map<string, int>::iterator innerit;
	CsvReader reader;
	StarTable startable;
	StarTree startree;
	StarCube* starcube = new StarCube();




	csv_data = reader.read_csv(freq_table);


	if(csv_data.size() == 0){
		ERRORLOG("Error in input reading. Data size zero\n");
		return 0;
	}

	INFOLOG("Number of tuples : %d\n", (int)csv_data.size());
	INFOLOG("Freq table size : %d\n", (int)freq_table.size());


	///temperature
	startable.generate_attrs_stars(freq_table[field_temperature], csv_data, field_temperature_index, temperature_star_val, temperature_iceberg);

    ///pm_value stars
	startable.generate_attrs_stars(freq_table[field_pm_value], csv_data, field_pm_value_index, pm_value_star_val, pm_value_iceberg);

	///pressure_iceberg stars
	startable.generate_attrs_stars(freq_table[field_pressure], csv_data, field_pressure_index, pressure_star_val, pressure_iceberg);

	///pressure_iceberg stars
	startable.generate_attrs_stars(freq_table[field_cbwd], csv_data, field_cbwd_index, cbwd_star_val, cbwd_iceberg);


	if(INFO)
		cout <<  "Un compressed table : " <<  csv_data.size() <<  ",  atrributes : " <<  csv_data[0].size() << endl;;


	csv_data = startable.compress_star_table(csv_data);


	if(INFO){
		reader.printdata(csv_data);
		//cout <<  "Compressed table : " <<  csv_data.size() <<  ",  atrributes : " <<  csv_data[0].size() <<  endl;
	}



	TreeNode* root  = new TreeNode();
	root->val = "*";
	startree.generate_star_tree(csv_data, root);


	printf("\n                           \n");
	printf("****************************\n");
	printf("****************************\n");
	printf("**** Start Star Cubing   ***\n");
	printf("****************************\n");


	//starcube->star_cubing(root,root , 0);
	starcube->dfs(root, root, 0);








	return 0;
}
