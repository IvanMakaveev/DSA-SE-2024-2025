template <class T>
void merge(T* firstArr, int firstLen, T* secondArr, int secondLen, T* res)
{
	T* result = new T[firstLen + secondLen];

	int firstCursor = 0;
	int secondCursor = 0;
	int resultCursor = 0;

	while (firstCursor < firstLen && secondCursor < secondLen)
	{
		if (firstArr[firstCursor] < secondArr[secondCursor])
        {
			result[resultCursor++] = firstArr[firstCursor++];
        }
		else
        {
			result[resultCursor++] = secondArr[secondCursor++];
        }
	}

	while (firstCursor < firstLen)
		result[resultCursor++] = firstArr[firstCursor++];

	while (secondCursor < secondLen)
		result[resultCursor++] = secondArr[secondCursor++];

	for (int i = 0; i < firstLen + secondLen; i++)
		res[i] = result[i];

	delete[] result;

}

void evensAndOdds(vector<int>& arr)
{
	vector<int> even;
	vector<int> odd;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] % 2 == 0)
			even.push_back(arr[i]);
		else
			odd.push_back(arr[i]);
	}

	std::reverse(odd.begin(), odd.end());

	merge<int>(even.data(), even.size(), odd.data(), odd.size(), arr.data());
}