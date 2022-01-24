/*
*
* Code will be updated.
*
*/

void merge(Job arr[], int l, int m, int r){
    //arr[l...m], arr[m+1...r]
    
    //size of the subarrays
    int n1 = m - l + 1;
    int n2 = r - m;
    Job L[n1];
    Job M[n2];
    
    for(int i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for(int i=0; i<n2; i++){
        M[i] = arr[m+1+i];
    }
    
    int i=0; int j=0; int k=l;
    
    while(i < n1 && j < n2){
        if(L[i].dead >= M[j].dead){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    
    while(i < n1){
        arr[k] = L[i];
        k++; i++;
    }
    
    while(j < n2){
        arr[k] = M[j];
        k++; j++;
    }
}
void mergeSort(Job arr[], int l, int r){
    //base case
    if(l<r){
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid,  r);
    }
        
}
int max(int n1, int n2){
    return (n1>n2) ? n1 : n2;
}

int x(Job arr[], int n, int day){
    
    if(n==0){
        return 0;
    }
        
        
    if(arr[n-1].dead<=day)
        return x(arr, n-1, day);
    
    else{
        return max(arr[n-1].profit + x(arr, n-1, day+1), x(arr, n-1, day));
    }
}

//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) 
{ 
    //sort Jobs according to their deadlines.
    mergeSort(arr, 0, n-1);
    
    for(int i=0; i<n; i++){
        cout << arr[i].dead << " " << arr[i].profit << endl;
    }
    vector<int> jobs;
    
    int ans = x(arr, n, 0);
    jobs.push_back(2); //dummy value
    jobs.push_back(ans);
    
    return jobs;
} 
