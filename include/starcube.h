#ifndef _STAR_CUBE_H
#define _STAR_CUBE_H


#include <map>
#include <vector>
#include <string>
#include <startree.h>


class StarCube
{



public:

	std::map<std::string , int> cuboid_key;
	std::vector<std::vector<std::string> > csv_data;


	StarCube(std::vector<std::vector<std::string> > ddat);

	bool all_stars_childs(TreeNode* root);
	void star_cubing(TreeNode *root, TreeNode* cnode, int level );
	void star_cubing1(StarTree startree, TreeNode *root, TreeNode* cnode, int level, std::vector<int>&skip);
	std::vector<TreeNode* >  get_childs(TreeNode *root);
	bool isleaf(TreeNode* root);
	void  print_cuboid(int num);
	void print_keys();


};

#endif
