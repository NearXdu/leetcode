class Solution {
    public:
	int numTrees(int n) {
	    vector<long>C(n+1);
	    C[0] = 1;
	    for (int i = 0; i < n; i++)
	    {
		C[i + 1] = (2 * (2 * i + 1)*C[i]) / (i + 2);
	    }
	    return C[n];
	}
};
