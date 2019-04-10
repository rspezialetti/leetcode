/*Time complexity O(n^2)*/
void selectionSort(vector<int>& numbers)
{
    for(size_t i = 0; i < numbers.size() - 1; ++i)
    {
        int index_min = i;
        
        for(size_t j = i+1; j < numbers.size(); ++j)
        {
            if(numbers[j] < numbers[index_min])
                index_min = j;
        }
        
        const int temp = numbers[i];

        numbers[i] = numbers[index_min];
        numbers[index_min] = temp;
    }
}
