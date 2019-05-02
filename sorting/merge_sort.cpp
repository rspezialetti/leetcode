void mergeVector(vector<int>&  left, vector<int>&  right, vector<int>&  merged)
{
    size_t idx_m = 0;
    size_t idx_l = 0;
    size_t idx_r = 0;
    
    while(idx_l < left.size() && idx_r < right.size())
    {
        if(left[idx_l] <= right[idx_r])
        {
            merged[idx_m] = left[idx_l];
            ++idx_l;
        }
        else
        {
            merged[idx_m] = right[idx_r];                
            ++idx_r;
        }
        ++idx_m;
    }
    
    while(idx_r < right.size())
    {
        merged[idx_m] = right[idx_r];
        
        ++idx_r;
        ++idx_m;
    }
    
    while(idx_l < left.size())
    {
        merged[idx_m] = left[idx_l];
        
        ++idx_l;
        ++idx_m;
    }
}

/*Time Complexity: O(nlogn) Space Complexity: O(n)*/
void mergeSort(vector<int>& numbers)
{
    if(numbers.size() < 2)
        return;
    
    const size_t size = numbers.size();
    const size_t size_half = size * 0.5;
    
    vector<int> left(size_half, 0);
    vector<int> right(size - size_half, 0);
    
    for(size_t i = 0; i < size_half; ++i)
    {
        left[i] = numbers[i];
        right[i] = numbers[i + size_half];
    }

    mergeSort(left);    
    mergeSort(right);
    
    mergeVector(left, right, numbers);
}
