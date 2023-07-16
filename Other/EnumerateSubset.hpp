vector< int > enumerate_subset(int S)
{
    vector< int > ret;
    int sub = S;
    while (sub > 0)
    {
        ret.push_back(sub);
        sub = (sub - 1) & S;
    }
    return ret;
}
