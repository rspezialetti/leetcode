void insertionSort(vector<int>&vector)
{
    
    for(size_t i = 1; i < vector.size(); ++i)
    {
        const int val = vector[i];
        int hole = i;
        
        while(hole > 0 && vector[hole-1] > val)
        {
            vector[hole] = vector[hole-1];
            --hole;
        }       
        vector[hole] = val;
    }
}
