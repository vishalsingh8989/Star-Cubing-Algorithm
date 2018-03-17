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

	StarCube();


	void star_cubing(TreeNode *root, TreeNode* cnode, int level);
	std::vector<TreeNode* >  get_childs(TreeNode *root);
	bool isleaf(TreeNode* root);
	void dfs(TreeNode *root, TreeNode* cnode, int level);
	void  print_cuboid(int num);


};

#endif
