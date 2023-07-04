 void merge(int arr[], int l, int m, int r)
    {
        vector<int>temp;
        int i = l , n1 = m;
        int j = m+1, n2= r;
        
        while(i<=n1 && j<=n2)
        {
            if(arr[i] < arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
            
        }
        while(i<=n1)
        {
            temp.push_back(arr[i]);
                i++;
        }
        while(j<=n2)
        {
            temp.push_back(arr[j]);
                j++;
        }
        // copy changes in arr
        int k = 0;
        for(int i=l;i<=r;i++)
        {
            arr[i] = temp[k++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //base case
        if(l>=r) return;
        
        //rec case
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
