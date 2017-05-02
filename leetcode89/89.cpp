class Solution {
    private:
	int binary2grey(vector<int>binary)
	{
	    vector<int>greyCode;
	    for (int i = 0; i < binary.size() - 1; i++)
	    {
		greyCode.push_back(binary[i] ^ binary[i + 1]);
	    }//二进制到格雷码
	    int sum = 0;
	    for (int i = greyCode.size() - 1; i >= 0; i--)
	    {
		sum += greyCode[i] << (greyCode.size() - 1 - i);
	    }//格雷码到十进制
	    return sum;
	}
	vector<int> num2Binary(int nums)//十进制转二进制
	{
	    vector<int>result;
	    while (nums)
	    {
		result.insert(result.begin(), nums % 2);
		nums /= 2;
	    }
	    result.insert(result.begin(), 0);
	    return result;
	}
    public:
	vector<int> grayCode(int n) {
	    int bits = pow(2, n);
	    vector<int>result;
	    //num2Binary(6);

	    for (int i = 0; i < bits; i++)
	    {
		vector<int>binary = num2Binary(i);//十进制转二进制
		int grey = binary2grey(binary);//二进制->格雷码->十进制
		result.push_back(grey);//写入结果
	    }

	    return result;
	}
};

///
//
class Solution {  
    public:  
	vector<int> grayCode(int n) {
	    vector<int>gray;
	    if (n == 0)
	    {
		gray.push_back(0);
		//gray.push_back(1);
		return gray;
	    }
	    vector<int> preGray = grayCode(n - 1);
	    vector<int>resGray(preGray);//前 2^(n-1)个数
	    for (int i = preGray.size() - 1; i >= 0; i--)
	    {
		int temp = preGray[i] + pow(2, n - 1);
		resGray.push_back(temp);
	    }//后2^(n-1)个数
	    return resGray;
	}
};
