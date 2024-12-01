size_t Solve(vector<int> cr, vector<int> cg, vector<int> cb)
{
    vector<int> optr; vector<int> optb; vector<int> optg;
    optr.push_back(cr[0]);
    optg.push_back(cg[0]);
    optb.push_back(cb[0]);

    for(size_t i=1; i < n; i++)
    {
        optr.push_back(cr[i] + min(optb[i-1],optg[i-1]));
        optg.push_back(cg[i] + min(optb[i-1],optr[i-1]));
        optb.push_back(cb[i] + min(optr[i-1],optg[i-1]));
    }

    return min(optr[n], optg[n], optb[n]);
}