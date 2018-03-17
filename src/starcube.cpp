#include <vector>
#include <iostream>
#include <csvreader.h>
#include <logger.h>
#include <fstream>
#include <map>
#include <vector>
#include <startable.h>
#include <startree.h>
#include <starcube.h>
#include <iomanip>

using namespace std;

int iceberg = 2;
int level = 0;


string cuboid[] = {"*", "*" , "*", "*","*"};


StarCube ::StarCube(vector<vector<string> > csv_data){
	this->csv_data = csv_data;
	cuboid_key.clear();
	//cuboid_key.insert(pair<string, int>("****", 1));
	//cout  << "Contructor called : csv size : " << csv_data.size() << endl;
}

void StarCube :: print_keys(){
	cout <<  "Print key value\n";
	for(auto it = cuboid_key.begin(); it != cuboid_key.end();it++){
		cout <<it->first <<  " : " << it->second<< endl;
	}
}

void StarCube :: print_cuboid(int num){
	//cout << "print****\n";
	string key = cuboid[0] + cuboid[1] +cuboid[2] +cuboid[3] +cuboid[4];
	//f(cuboid_key.find(key) == cuboid_key.end()){
	//	cuboid_key.insert(pair<string ,int>(key, num));
		//cout << setw(2) <<cuboid[0] << " " << setw(2) <<cuboid[1] << " " <<setw(2)<<  cuboid[2] << " " << setw(2) << cuboid[3] << " "<< setw(2)<<  cuboid[4] << " : " << num <<  endl;
		cout << setw(2) <<cuboid[0] << " " <<setw(2) <<cuboid[1] << " " <<setw(2)<<  cuboid[2] << " " << setw(2) << cuboid[3] << " "<< setw(2)<<  cuboid[4] << " : " << num <<  endl;

	//}

}

bool StarCube :: all_stars_childs(TreeNode* root){
	if(root){
		vector<TreeNode* >  child_list = get_childs(root);
		int size = child_list.size();
		for(int i  = 0 ; i < size  ; i++){
			if(child_list[i]->val.compare("*")!= 0){
				return false;
			}
			all_stars_childs(child_list[i]);
		}

		return true;
	}
	return false;

}

void StarCube :: star_cubing1(StarTree startree, TreeNode *root, TreeNode* cnode, int level, vector<int>& skip){


	if(cnode){
		TreeNode *new_root = NULL;
		//cout<< "All stars: "<<  cnode->val  << all_stars_childs(cnode)<< endl;

		if(cnode->count >= iceberg){

			if(cnode !=  root){
				//cout<< "Not root :  " << level << ", " <<  cnode->val <<endl;
				cuboid[level] = cnode->val;
				print_cuboid(cnode->count);

			}else if(isleaf(cnode)){
				//cout << "isleaf  " << cnode->val<<endl;
				cuboid[level] = cnode->val;
				print_cuboid(cnode->count);

			}else{
				//cout << "Generate star tree"<<endl;


				new_root = new TreeNode();
				new_root->val = "*";
				skip.push_back(level);
				new_root = startree.generate_star_tree(csv_data, new_root, level+1, skip);

				//cout << "new Root count : " <<  new_root->count <<endl;
			}
		}

		if(!isleaf(cnode) ){

			star_cubing1(startree,  root, cnode->child, level + 1, skip);

		}

		if(new_root ){
			//cout <<  "Call new child :"  << cnode->val << ", "<< level <<"\n";
			cuboid[level] = "*";
			star_cubing1(startree,  new_root, new_root, level + 1, skip);
		}

		if(cnode->sibling){
			cuboid[level] = "*";
			star_cubing1(startree,  root, cnode->sibling, level, skip);

		}

		cuboid[level] = "*";//remove T



		//cout <<  "Reset : " << level << endl;


		//free(new_root);
	}

}


void StarCube :: star_cubing(TreeNode *root, TreeNode* cnode, int level){
	//cout <<" call dfs\n";
	if(cnode){

		//if(cnode->count >  iceberg){
			vector<TreeNode* >  child_list = get_childs(cnode);
			int size = child_list.size();
			for(int i  = 0 ; i < size  ; i++){
				if(child_list[i]->count >= iceberg){
					if(!isleaf(child_list[i])){
						cuboid[level] = child_list[i]->val;
						star_cubing(root, child_list[i] ,  level + 1);
						cuboid[level] = "*";
						star_cubing(root, child_list[i] ,  level + 1);
					}else{
						print_cuboid(cnode->count);
					}
				}else{
					print_cuboid(cnode->count);

				}
			}

			//if(isleaf(cnode)){
			//	print_cuboid(cnode->count);
			 if (cnode->sibling == NULL){
				// set all next value to * for current cnode
				for(int j = level + 1 ; j < 5; j++ ){
					cuboid[j] = "*";
				}
				print_cuboid(cnode->count);
			}

		cuboid[level] = "*";
		//star_cubing(root, cnode->child, level + 1);


	}

}



vector<TreeNode* > StarCube :: get_childs(TreeNode *root){
	vector<TreeNode* > child_list;
	if(root){
		TreeNode * child;
		child = root->child;
		while(child){
			child_list.push_back(child);
			child = child->sibling;
		}

	}
	return child_list;

}


bool StarCube :: isleaf(TreeNode* root){
	return root->child == NULL;
}
