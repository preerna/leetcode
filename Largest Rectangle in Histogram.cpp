class Solution {
public:
vector <int> prevSmallerElement(vector <int> &in)
{
    stack <int> s;
    s.push(-1);
    vector<int>ans(in.size());
    for(int i=0;i<in.size();i++)
    {
        int curr = in[i];
        while(s.top()!=-1 && in[s.top()]>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector <int> nextSmallerElement(vector <int> &in)
{
    stack <int>s;
    s.push(-1);
    vector<int>ans(in.size());
    for(int i=in.size()-1;i>=0;i--)
    {
        int curr = in[i];
        while (s.top()!=-1 && in[s.top()]>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        vector <int> prev = prevSmallerElement(heights);
        vector <int> next = nextSmallerElement(heights);
        int MaxArea = INT_MIN;
        int size = heights.size();
        for(int i=0;i<heights.size();i++)
        {
            int length = heights[i];
            if(next[i]==-1)
            {
                next[i]=size;
            }
            int width = next[i]-prev[i]-1;
            int area = length*width;
            MaxArea = max(MaxArea,area);
        }
        return MaxArea;
    }
};