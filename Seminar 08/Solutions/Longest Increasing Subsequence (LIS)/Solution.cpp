// 06. Longest Increasing Subsequence
//// Two tables; T1 - LIS for I-th index; T2 - Previous node
//// Rec: longest path follows T2 and has max value in T1
int longestIncreesingSubsequenceDyn(const vector<int>& arr, vector<int>& path)
{
	vector<int> dyn(arr.size());
	vector<int> prev(arr.size());

	for (int i = 0; i < arr.size(); i++)
	{
		int max = 0;
		int prevIndex = -1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j]< arr[i] && dyn[j] > max)
			{
				max = dyn[j];
				prevIndex = j;
			}
		}
		dyn[i] = max + 1;
		prev[i] = prevIndex;

	}

	//find max
	int max = -1;
	int maxInd = -1;
	for (int i = 0; i < dyn.size(); i++) 
	{
		if (dyn[i] > max)
		{
			max = dyn[i];
			maxInd = i;
		}
	}

	//path
	int pathIter = maxInd;
	while (pathIter != -1)
	{
		path.push_back(arr[pathIter]);
		pathIter = prev[pathIter];
	}
	std::reverse(path.begin(), path.end());

	return max;
}