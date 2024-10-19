char findTheDifference(string s, string t) {
    vector<int> counts(26, 0);
    for(auto& c:s)
    {
        counts[c-'a'] += 1;
    }

    for(auto& c:t)
    {
        if(--counts[c-'a'] < 0)
        {
            return c;
        } 
    }
    
    return '\0';
}