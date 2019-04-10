void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

/*Time Complexity O(n^2)*/
void bubbleSort(vector<int>& numbers)
{
    bool swapped = false;
    for(size_t j  = 0; j < numbers.size(); ++j)
    { 
        for(size_t i = 0; i < numbers.size() - 1; ++i)
        {
            if(numbers[i] > numbers[i + 1])
            {
              swap(&numbers[i], &numbers[i + 1]);
              swapped = true;
            }
        }
        
        if(swapped == false)
          break;
    }
}
