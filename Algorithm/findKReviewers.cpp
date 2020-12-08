#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<pair<int, string>> helper(unordered_map<string, priority_queue<int>>& mp, int k)
{
	priority_queue<pair<int, string>>  pq;
	vector<pair<int, string>> res;

	// push the highest quality reviewer of each affiliation into a priority_queue
	for (auto& m : mp)
	{
		if (m.second.size() >= 1)
		{
			pq.push(make_pair(m.second.top(), m.first));
			m.second.pop();
		}
	}
	
	// add the highest quality reviewer into the result
	int i = 0;
	while ((i < k) && !pq.empty())
	{
		res.push_back(pq.top());
		pq.pop();
		i++;
	}

	// check whether has leftover K. if no, return result; if yes, recursively call helper function
	int todoK = k - res.size();
	if (todoK <= 0) return res;
	else
	{
		vector<pair<int, string>> temp;
		temp = helper(mp, todoK);
		res.insert(res.end(),temp.begin(),temp.end());
		return res;
	}
}


/*
Requirements:
findKReviewers: find K Reviewers from N affiliation, keep diversity as 1st priority, quality as 2nd priority
input:  N reviewers, each reviewer has info of quality and affliation; K: number of reviewers to pick
output: K reviewers, each reviewer has info of quality and affliation
Notify: We use integer to save quality value, assume the bigger value, the higher quality
*/
vector<pair<int, string>> findKReviewers(vector<pair<int, string>>& reviewers, int k)
{
	// edge case
	if(k == 0 || k > reviewers.size()) return {};

	// key: affiliation; value: priority_queue of quality
	unordered_map<string, priority_queue<int>> mp;

	// loop reviewers and put them into a unordered_map
	for (auto& p : reviewers)
		mp[p.second].push(p.first);

	// helper function picks the K reviewers
	return helper(mp, k);
}

int main()
{
	vector<pair<int, string>> reviewers, res;
	int k = 4;
	reviewers = {{6,"Google"}, {5,"Google"}, {3,"Google"}, 
		     {4,"Facebook"}, {2,"Facebook"},
		     {1,"Apple"}};
	res = findKReviewers(reviewers, k);
	for (auto& x : res)
		cout << "{" << x.first << "," << x.second << "}" << "\n" <<endl;
	
	return 1;
}
