

/* Time complexity : O(l1∗l2∗len_str), Space complexity: O(l1​∗l2​∗x). */
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
{
	map<int, string> map_val;
	vector<string> ties;

        int added = 0;

        for(size_t i = 0; i < list1.size(); ++i)
        {
            for(size_t j = 0; j < list2.size(); ++j)
            {
                if(list1[i].compare(list2[j]) == 0)
                {
                    const int sum = i + j;
                    
                    if(added == 0)
                    {
                        map_val.emplace(sum, list1[i]);
                        ++added;
                    }
                    
                    
                    if(map_val.find(sum) == map_val.end() && added != 0)
                        map_val.emplace(sum, list1[i]);
                    else
                        ties.push_back(list1[i]);
                }
            }
        }
        
        map<int,string>::iterator it = map_val.begin();
        const vector<string> result = ties.size() > 0 ? ties : vector<string>(1, it->second);
        
        return ties;
    }

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
{        
	map<int, string> map_val;
	vector<string> ties;
        vector<string> result;
        
        int min_sum = INT_MAX;
        
	for(size_t i = 0; i < list1.size(); ++i)
	{
		for(size_t j = 0; j < list2.size(); ++j)
		{
			if(list1[i].compare(list2[j]) == 0)
			{
	                    const int sum = i + j;
                    
        	            if(min_sum > sum)
        	            {
        	                result.clear();
        	                result.push_back(list1[i]);
                        
        	                min_sum = sum;
        	            }
			else if(min_sum == sum)
			{
                        	result.push_back(list1[i]);
			}
                }
            }
        }
        
        return result;
    }
}

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
    vector<string> result;
        
    int min_sum = INT_MAX;
        
    unordered_map<string, int> map_val;

    for(size_t i = 0; i < list1.size(); ++i)
        map_val.emplace(list1[i], i);
        
    for(size_t i = 0; i < list2.size(); i++)
    {
        auto it = map_val.find(list2[i]);
            
        if(it != map_val.end())
        {
            const int sum = i + it->second;
                
            if(min_sum > sum)
            {
                result.clear();
                result.push_back(it->first);
                    
                min_sum = sum;
            }
            else if(min_sum == sum )
            {
                result.push_back(it->first);
            }
        }
    }
        
    return result;
}
