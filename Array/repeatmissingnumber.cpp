vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int i,length = A.size(),xor1=A[0],set_bit,a=0,b=0;
    vector<int> res;
    for(i=1;i<length;i++)
    {
        xor1=xor1^A[i];
    }
    for(i=1;i<=length;i++)
    {
        xor1=xor1^i;
    }
    set_bit = xor1 & ~(xor1-1);
    for(i=0;i<length;i++)
    {
        if(A[i] & set_bit)
        {
            a = a^A[i];
        }
        else
        {
            b = b^A[i];
        }
    }
    for(i=1;i<=length;i++)
    {
        if(i & set_bit)
        {
            a = a^i; 
        }
        else
        {
            b = b^i;
        }
    }
 
   res.push_back(a);
   res.push_back(b);
    return res;
}
