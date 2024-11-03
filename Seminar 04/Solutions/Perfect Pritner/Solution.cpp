bool check(vector<long long>& printersTime, long long targetTime, long long targetPapers)
{
    long long papers = 0;
    for(auto currPrinterTime : printersTime)
    {
        papers += targetTime / currPrinterTime;
    }
    
    return papers >= targetPapers;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> v(k);
    
    long long minTime = LLONG_MAX, maxTime = LLONG_MIN; 
    for(int i = 0; i < k; i++)
    {
        cin >> v[i];
        minTime = min(minTime, v[i]);
        maxTime = max(maxTime, v[i]);
    }

    // In order to use Binary Search on Answer, we need to find a lower and upper limit for our possible answers
    long long beg = (n / k) * minTime; // Lowest time that we can possibly expect
    long long end = (n / k + 1) * maxTime; // Highest time that we expect
    long long ans = end; // Worst possible case - the largest value for the expected time
    
    while(beg <= end)
    {
        long long mid = beg + (end - beg) / 2;
        
        // We also need a way to verify our answer quickly. We can do it with our check() function
        if(check(v, mid, n))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }
    
    cout << ans;
    
    return 0;
}