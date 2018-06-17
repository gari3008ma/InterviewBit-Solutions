int rem(int str,int A)
{
    int i,r=0;
    for(i=0;i<str.length();i++)
    {
        r=r*10+(str[i]-'0');
        r=r%A;
    }
    return r;
}
string Solution::multiple(int A) {
    queue<int> graph;
    int value;
    set<int> vis;
    int v;
    graph.push(1);
    while(!graph.empty())
    {
        value=graph.front();
        graph.pop();
        v = rem(value,A);
        if(v==0)
          return value;
        if(vis.find(v)==vis.end())
        {
            vis.insert(v);
            graph.push(value+"0");
            graph.push(value+"1");
        }
    }
    return "";
}
