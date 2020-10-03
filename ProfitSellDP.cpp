class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<int> maxx(n), mini(n);
        mini[0] = prices[0];
        for (int i = 1; i < n; i++)
        {
            mini[i] = min(mini[i - 1], prices[i]);
        }
        maxx[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            maxx[i] = max(maxx[i + 1], prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, maxx[i] - mini[i]);
        }
        return ans;
    }
};