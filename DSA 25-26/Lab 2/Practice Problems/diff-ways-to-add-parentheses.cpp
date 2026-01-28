/*
  Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
  The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 10^4.
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;

        for(int i=0; i<expression.size(); i++)
        {
            char a = expression[i];

            if(a=='+' || a=='-' || a=='*')
            {
                vector<int> l = diffWaysToCompute(expression.substr(0,i));
                vector<int> r = diffWaysToCompute(expression.substr(i+1));

                for(int x: l)
                {
                    for(int y: r)
                    {
                        if(a=='+') results.push_back(x+y);
                        else if(a=='-') results.push_back(x-y);
                        else if(a=='*') results.push_back(x*y);
                    }
                }
            }
        }
        if (results.empty()) { //for cases like 3+4
            results.push_back(stoi(expression));
        }
        return results;
    }
};
