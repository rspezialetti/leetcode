int partitionVector(vector<int>&  v, int start, int end)
{
    const int pivot = v[end];
    
    int idx_pivot = start;
    
    for(int i = start; i < end; ++i)
    {
        if(v[i] <= pivot)
        {
            swap(v[i], v[idx_pivot]);
            ++idx_pivot;
        }
    }
    swap(v[idx_pivot], v[end]);
    
    return idx_pivot;
}

/*Time Complexity: Best case O(n log n), Worst case(n^2); Space Complexity: */
void quickSort(vector<int>& numbers, int start, int end)
{
     if(start >= end)
        return;
        
    const int idx_pivot = partitionVector(numbers, start, end);
    
    quickSort(numbers, start, idx_pivot - 1);
    quickSort(numbers, idx_pivot + 1, end);
}
