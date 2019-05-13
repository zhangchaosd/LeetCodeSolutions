#include <vector>
#include <string>

using namespace std;

/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */
class S165 {
public:
	int compareVersion(string version1, string version2) {
		int n1 = version1.length() - 1;
		int n2 = version2.length() - 1;
		long long v1 = -1;
		long long v2 = -1;
		while (n1 >= 0 && (version1[n1] == '.' || version1[n1] == '0'))
		{
			n1--;
			if (version1[n1] == '.')
			{
				version1.erase(n1);
				n1--;
			}
		}
		if (n1 == -1) v1 = 0;
		while (n2 >= 0 && (version2[n2] == '.' || version2[n2] == '0'))
		{
			n2--;
			if (version2[n2] == '.')
			{
				version2.erase(n2);
				n2--;
			}
		}

		if (n2 == -1) v2 = 0;
		if (v1 == 0 && v2 == 0)return 0;
		if (v1 == 0)return -1;
		if (v2 == 0)return 1;
		n1 = version1.length() - 1;
		n2 = version2.length() - 1;
		int i = 0;
		int j = 0;
		while (i <= n1 && j <= n2)
		{
			while (version1[i] == '0')i++;
			while (version2[j] == '0')j++;
			if (i <= n1 && version1[i] == '.')i--;
			if (j <= n2 && version2[j] == '.')j--;
			int i2 = i;
			int j2 = j;
			while (i2 <= n1 && version1[i2] != '.')i2++; i2--;
			while (j2 <= n2 && version2[j2] != '.')j2++; j2--;

			if (i2 == i && j2 == j)
			{
				if (version1[i] != version2[j])return version1[i] > version2[j] ? 1 : -1;
				while (i <= n1 && version1[i] != '.')i++;
				while (j <= n2 && version2[j] != '.')j++;
				i++; j++; continue;
			}
			if (i2 == i && j2 != j)return -1;
			if (i2 != i && j2 == j)return 1;
			if (i2 - i != j2 - j)return i2 - i > j2 - j ? 1 : -1;
			for (; i <= i2; i++, j++)
			{
				if (version1[i] != version2[j]) return version1[i] > version2[j] ? 1 : -1;
			}
			i++; j++;
		}
		if (i == n1 + 2 && j == n2 + 2)return 0;
		if (i == n1 + 2)return -1;
		return 1;
	}
};


