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
