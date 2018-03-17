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

int iceberg = 1;
int level = 0;

string cuboid[] = {"*", "*" , "*", "*"};

void StarCube :: dfs(TreeNode *root, TreeNode* cnode, int level){
	//cout <<" call dfs\n";
	if(cnode){

		//if(cnode->count >  iceberg){
			vector<TreeNode* >  child_list = get_childs(cnode);
			for(int i  = 0 ; i <  child_list.size() ; i++){
				if(child_list[i]->count > iceberg){
					//cout << child_list[i]->val << " level : " << level << endl;
					cuboid[level] = child_list[i]->val;
					dfs(root, child_list[i] ,  level + 1);
				}else{

					cout << "Cuboid : " << setw(2) <<cuboid[0] << " " <<setw(2)<<  cuboid[1] << " " << setw(2) << cuboid[2] << " "<< setw(2)<<  cuboid[3] << " : " << cnode->count <<  endl;

				}
			}

			if(isleaf(cnode)){
				cout << "Cuboid : " << setw(2) <<cuboid[0] << " " <<setw(2)<<  cuboid[1] << " " << setw(2) << cuboid[2] << " "<< setw(2)<<  cuboid[3] << " : " << cnode->count <<  endl;
			}



	}else{
		cout << "Cuboid : " << setw(2) <<cuboid[0] << " " <<setw(2)<<  cuboid[1] << " " << setw(2) << cuboid[2] << " "<< setw(2)<<  cuboid[3] << " : " << cnode->count <<  endl;

	}


}

void StarCube :: star_cubing(TreeNode *root, TreeNode* cnode, int level){

	if(cnode){
		vector<TreeNode* >  child_list = get_childs(cnode);
		//if(INFO)
		//	cout << "Root : " <<  root->val << " : child count " << child_list.size() <<endl;


		for(int i  = 0 ; i <  child_list.size() ; i++){

			if(cnode->count > iceberg){
				cout << child_list[i]->val << " level : " << level << endl;
				if(cnode != root){
					cout <<  "If \n";
					cout << "Cuboid : " << setw(2) <<cuboid[0] << " " <<setw(2)<<  cuboid[1] << " " << setw(2) << cuboid[2] << " "<< setw(2)<<  cuboid[3] << " : " << cnode->count <<  endl;
					cout << endl;
				}else if(isleaf(cnode)){
					cout <<  "else if \n";
					cout << "Cuboid : " << setw(2) <<cuboid[0] << " " <<setw(2)<<  cuboid[1] << " " << setw(2) << cuboid[2] << " "<< setw(2)<<  cuboid[3] << " : " << cnode->count <<  endl;
					cout << endl;
				}

			}

		}

		if(!isleaf(cnode)){
			cuboid[level] = cnode->child->val;
			star_cubing(root , cnode->child , level + 1);
		}
//		//TODO

		if(cnode->sibling != NULL){
			//cuboid[level] = cnode->sibling->val;
			star_cubing(root , cnode->sibling , level );
		}

		cuboid[level] = "*";

//		else{
		//cout << "Cuboid : " << setw(2) <<cuboid[0] << " " <<setw(2)<<  cuboid[1] << " " << setw(2) << cuboid[2] << " "<< setw(2)<<  cuboid[3] << " : " << cnode->count <<  endl;
//
//		}





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


