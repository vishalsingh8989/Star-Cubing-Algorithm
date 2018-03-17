#ifndef _STAR_TREE_H
#define _STAR_TREE_H


#include <map>
#include <vector>
#include <string>



typedef struct TreeNode{

	   std::string val;
	   int count;
	   TreeNode *sibling;
	   TreeNode *child;

}TreeNode ;


class StarTree
{

public:

	 TreeNode* generate_star_tree(std::vector<std::vector<std::string> > &table, TreeNode* root , int row_idx , std::vector<int> &skip);
	 TreeNode* insert(int row_idx , std::vector<std::string> row , TreeNode* root, std::vector<int>& skip);
};


#endif
