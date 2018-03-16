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


void StarCube :: star_cubing(TreeNode *root, TreeNode* cnode){








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


