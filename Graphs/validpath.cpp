 string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) 
  {
      int i,j,k,mat[1000][1000],x=A,y=B;
    string answer;
    memset(mat,0,sizeof(mat));
    for(i=0;i<=A;i++)
    {
        for(j=0;j<=B;j++)
        {
            for(k=0;k<C;k++)
            {
                if(((E[k]-i)*(E[k]-i)+(F[k]-j)*(F[k]-j))<=D*D)
                mat[i][j]=-1;
            }
        }
    }
    if(mat[0][0]==-1)
     return "NO";
    vector<vector<int>> graph;
    vector<int> arr={0,0};
    mat[0][0]=1;
    graph.push_back(arr);
    while(!graph.empty())
    {
        vector<int> arr=graph.front();
        int  elex=arr[0];
        int eley=arr[1];
        graph.erase(graph.begin());
        if(elex==x && eley==y)
        return "YES";
        if(elex-1>=0 && eley-1>=0 && mat[elex-1][eley-1]==0)
        {
            vector<int> arr = {elex-1,eley-1};
            mat[elex-1][eley-1]=1;
            graph.push_back(arr);
        }
        if(elex-1>=0  && mat[elex-1][eley]==0)
        {
            vector<int> arr = {elex-1,eley};
            mat[elex-1][eley]=1;
            graph.push_back(arr);
        }
        if(elex-1>=0 && eley+1<=y && mat[elex-1][eley+1]==0)
        {
            vector<int> arr = {elex-1,eley+1};
            mat[elex-1][eley+1]=1;
            graph.push_back(arr);
        }
         if( eley-1>=0 && mat[elex][eley-1]==0)
        {
            vector<int> arr = {elex,eley-1};
            mat[elex][eley-1]=1;
            graph.push_back(arr);
        }
         if(eley+1<=y && mat[elex][eley+1]==0)
        {
            vector<int> arr = {elex,eley+1};
            mat[elex][eley+1]=1;
            graph.push_back(arr);
        }
         if(elex+1<=x && eley-1>=0 && mat[elex+1][eley-1]==0)
        {
            vector<int> arr = {elex+1,eley-1};
            mat[elex+1][eley-1]=1;
            graph.push_back(arr);
        }
          if(elex+1<=x  && mat[elex+1][eley]==0)
        {
            vector<int> arr = {elex+1,eley};
            mat[elex+1][eley]=1;
            graph.push_back(arr);
        }
          if(elex+1<=x && eley+1<=y && mat[elex+1][eley+1]==0)
        {
            vector<int> arr = {elex+1,eley+1};
            mat[elex+1][eley+1]=1;
            graph.push_back(arr);
        }
    }
    if(mat[x][y]==1)
    answer="YES";
    else
    answer="NO";
    return answer;
  }
