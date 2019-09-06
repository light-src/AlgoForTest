#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef struct tree {
	int num;
	int x;
	int y;
	tree* left;
	tree* right;

	tree(int n, int tx, int ty) {
		num = n;
		x = tx;
		y = ty;
		left = NULL;
		right = NULL;
	}
};

tree* root;
vector<int> prearr;
vector<int> postarr;

bool compare(const pair<int, vector<int>> &a, const pair<int, vector<int>> &b)
{
	if (a.second[1] == b.second[1])
		return a.second[0] < b.second[0];
	else
		return a.second[1] > b.second[1];
}

void preorder(tree* ptr) {
	if (ptr) {
		// pointer가 null이 아니라면
		prearr.push_back(ptr->num);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(tree *ptr) {
	if (ptr) {
		// pointer가 null이 아니라면
		postorder(ptr->left);
		postorder(ptr->right);
		postarr.push_back(ptr->num);
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	vector<pair<int, vector<int>>> temp;
	tree *ptr, *prev;
	int i, lev;

	for (i = 1; i <= nodeinfo.size(); i++) 
		temp.push_back(make_pair(i, nodeinfo[i - 1]));
	
	sort(temp.begin(), temp.end(), compare);

	root = new tree(temp[0].first, temp[0].second[0], temp[0].second[1]);
	for (i = 1; i < temp.size(); i++) {
		ptr = root;
		prev = NULL;
		while (ptr != NULL) {
			prev = ptr;
			if (temp[i].second[0] < ptr->x)
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		if (temp[i].second[0] < prev->x)
			prev->left = new tree(temp[i].first, temp[i].second[0], temp[i].second[1]);
		else
			prev->right = new tree(temp[i].first, temp[i].second[0], temp[i].second[1]);
	}
	ptr = root;
	preorder(ptr);
	postorder(ptr);
	answer.push_back(prearr);
	answer.push_back(postarr);
	return answer;
}
