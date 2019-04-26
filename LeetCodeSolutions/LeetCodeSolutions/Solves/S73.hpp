
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */
class S73 {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();
		set<int>rows;
		set<int>cols;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == 0)
				{
					rows.insert(i);
					cols.insert(j);
				}
			}
		}
		for (auto it = rows.begin(); it != rows.end(); it++)
		{
			for (int i = 0; i < n; i++)
				matrix[*it][i] = 0;
		}
		for (auto it = cols.begin(); it != cols.end(); it++)
		{
			for (int i = 0; i < m; i++)
				matrix[i][*it] = 0;
		}
	}
};






