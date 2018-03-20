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
#include <time.h>

using namespace std;


//iceberg conditions
int temperature_iceberg = 2;
int pressure_iceberg = 2;
int pm_value_iceberg = 2;
int cbwd_iceberg = 2;
int dwep_iceberg = 20;



// string temperature_star_val = "b*";
// string pm_value_star_val = "a*";
// string pressure_star_val = "c*";
// string cbwd_star_val = "d*";
// string dwep_star_val = "dwep*";

//star values for each attribute
string temperature_star_val = "*";
string pm_value_star_val = "*";
string pressure_star_val = "*";
string cbwd_star_val = "*";
string dwep_star_val = "dwep*";


//attributes
string field_number, field_year, field_month, field_day, field_hour, field_pm_value,field_dwep,field_temperature, field_pressure,field_cbwd,field_iws,field_is,field_ir;
int field_number_index, field_year_index, field_month_index, field_day_index, field_hour_index, field_pm_value_index,field_dwep_index,field_temperature_index,field_pressure_index,field_cbwd_index,field_iws_index,field_is_index,field_ir_index;



int main(int argc, char** argv){

	INFOLOG("Start Star Cubing Algorithm\n");
 	time_t start_time = time(nullptr);
    cout << asctime(localtime(&start_time))
              << start_time << " seconds since the Epoch\n";


	cout <<  "argc " <<  argc << endl;
	if(argc != 3){
		cout <<  "Error: input file missing"<<endl;
		cout <<  "Use :  starmain <input.csv> <iceberg(int)>. "<<endl;
		cout <<  " params are without quotes.copy paste: \"starmain sample.csv 2\""<<endl;
		return 1;
	}
	cout <<  "continue :" <<  endl;
	map<string, map<string, int> > freq_table;
	map<string, string>  star_table;
	map<string, string>  temperature_star_table;
	map<string, string>  pm_value_star_table;
	vector<vector<string> > csv_data;
	//map<string, int>::iterator innerit;
	string file_name(argv[1]);

	CsvReader reader(file_name);
	StarTable startable(stoi(argv[2]));
	StarTree startree;

	csv_data = reader.read_csv(freq_table);
	StarCube starcube(csv_data, stoi(argv[2]));


	if(csv_data.size() == 0){
		ERRORLOG("Error in input reading. Data size zero\n");
		return 0;
	}

	INFOLOG("Number of tuples : %d\n", (int)csv_data.size());
	INFOLOG("Freq table size : %d\n", (int)freq_table.size());



	///temperature
	startable.generate_attrs_stars(freq_table[field_temperature], csv_data, field_temperature_index, temperature_star_val, startable.iceberg);

    ///pm_value stars
	startable.generate_attrs_stars(freq_table[field_pm_value], csv_data, field_pm_value_index, pm_value_star_val, startable.iceberg);

	///pressure_iceberg stars
	startable.generate_attrs_stars(freq_table[field_pressure], csv_data, field_pressure_index, pressure_star_val, startable.iceberg);

	///pressure_iceberg stars
	startable.generate_attrs_stars(freq_table[field_cbwd], csv_data, field_cbwd_index, cbwd_star_val, startable.iceberg);


	if(INFO)
		cout <<  "Uncompressed table : " <<  csv_data.size() <<  ",  atrributes : " <<  csv_data[0].size() << endl;;


	csv_data = startable.compress_star_table(csv_data);
	cout << "Number of tuples in compressed table : " <<  (int)csv_data.size() << endl;;
	cout << "Freq table size : " << (int)freq_table.size() <<  endl;


	if(INFO)
		reader.printdata(csv_data);
		//cout <<  "Compressed table : " <<  csv_data.size() <<  ",  atrributes : " <<  csv_data[0].size() <<  endl;


	TreeNode* root  = new TreeNode();
	root->val = "*";
	startree.generate_star_tree(csv_data, root, 0);

	printf("\n                           \n");
	printf("****************************\n");
	printf("**** Start Star Cubing   ***\n");
	printf("****************************\n");


	cout << "Root count : " <<  root->count <<endl;
	//starcube->star_cubing(root,root , 0);


	string cuboid[] = {"*", "A" , "B", "C","D"};


	vector<TreeNode*> subtree;
	starcube.star_cubing1(startree, root, startree.root, 0, cuboid, subtree);
	starcube.print_cuboid();

	//starcube.print_keys();

	//starcube.star_cubing(root, root, 1);


	time_t end_time = time(nullptr);
	cout << asctime(localtime(&end_time)) << end_time << " seconds since the Epoch\n";
	cout << "Time  :  " <<  (int)(end_time-start_time) << endl;;






	return 0;
}
