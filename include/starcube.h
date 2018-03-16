#ifndef _STAR_CUBE_H
#define _STAR_CUBE_H


#include <map>
#include <vector>
#include <string>

#include <startree.h>


class StarCube
{



public:
	void star_cubing(TreeNode *root, TreeNode* cnode);
	std::vector<TreeNode* >  get_childs(TreeNode *root);



};

#endif
