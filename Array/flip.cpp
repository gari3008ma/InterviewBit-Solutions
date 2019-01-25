vector<int> Solution::flip(string A) {
    int size=A.size(),i,j;
    vector<int> pr;
    for(i=0;i<size;i++)
    {
        if(A[i]=='1')
           A[i]=-1;
    }
    int max_sum=INT_MIN,current_sum=0;
    int start =0,end=0;
    pr.push_back(-1);
    pr.push_back(-1);
    for(i=0;i<size;i++)
    {
        current_sum=current_sum+A[i]-'0';
        if(current_sum>max_sum)
            {
                max_sum=current_sum;
                pr[0]=start;
                end=i;
                pr[1]=end;
            }
        if(current_sum<0)
        {
            current_sum=0;
            start=i+1;
        }
    }
    if(pr[0]==-1 && pr[1]==-1)
    {
        vector<int> res;
        return res;
    }
        pr[0]++;
        pr[1]++;
   
    return pr;
}

