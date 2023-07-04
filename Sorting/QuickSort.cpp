    void quickSort(int arr[], int low, int high)
    {
        // base case
        if(low >= high)
            return;
        // rec case
        int pindex = partition(arr,low,high);
        quickSort(arr,low,pindex-1);
        quickSort(arr,pindex+1,high);
    }
    
    public:
    // j want bigger
    // if j gets smaller it swaps with i
    // i will come forward then swap
    
    int partition (int arr[], int low, int high)
    {
       int i= low,j=low+1;
       int pivot = arr[i];
       while(j<=high)
       {
           if(arr[j] > pivot)
           {
               j++;
           }
           else
           {
               i++;
               swap(arr[i],arr[j]);
               j++;
           }
       }

       swap(arr[i],arr[low]);
       return i;
    }
