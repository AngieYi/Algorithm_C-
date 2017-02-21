
#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Employee {
     int val;
     Employee *left;
     Employee *right;
     Employee(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	Employee* lowestCommonAncestor(Employee* root, Employee* p, Employee* q) {

	}
};