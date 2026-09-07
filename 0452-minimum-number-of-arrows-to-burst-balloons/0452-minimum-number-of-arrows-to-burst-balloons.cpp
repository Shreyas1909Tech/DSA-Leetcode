class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    int n=points.size();
    sort(begin(points),end(points));
    vector<int> prev=points[0];
    int count=1;
    for(int i=0;i<n;i++)
    {
        int curstartpoint=points[i][0];
        int curendpoint=points[i][1];

        int prevstartpoint=prev[0];
        int prevendpoint=prev[1];

        if(curstartpoint>prevendpoint)
        {
            count++;
            prev=points[i];
        }
        else
        {
            prev[0]=max(prevstartpoint,curstartpoint);
            prev[1]=min(curendpoint,prevendpoint);
        }
    }
    return count;
    }
};