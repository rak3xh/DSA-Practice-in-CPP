#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int val;
    int indexInMap;
};

class RandomizedCollection
{
public:
    bool insert(int val)
    {
        valToIndices[val].push_back(items.size());
        items.emplace_back(Item{val, static_cast<int>(valToIndices[val].size() - 1)});
        return valToIndices[val].size() == 1;
    }

    bool remove(int val)
    {
        auto it = valToIndices.find(val);
        if (it == valToIndices.end())
            return false;

        int index = it->second.back();
        it->second.pop_back();
        if (it->second.empty())
            valToIndices.erase(it);

        if (index != items.size() - 1)
        {
            items[index] = items.back();
            valToIndices[items[index].val][items[index].indexInMap] = index;
        }

        items.pop_back();
        return true;
    }

    int getRandom()
    {
        return items[rand() % items.size()].val;
    }

private:
    unordered_map<int, vector<int>> valToIndices;
    vector<Item> items;
};

// C++ 20 Solution

/*
#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int val;
    int indexInMap;
};

class RandomizedCollection
{
    public:
    bool insert(int val)
    {
        valToIndices[val].push_back(items.size());
        items.emplace_back(val, valToIndices[val].size() - 1);
        return valToIndices[val].size() == 1;
    }

    bool remove(int val)
    {
        if (!valToIndices.contains(val))
        return false;

        const int index = valToIndices[val].back();
        valToIndices[items.back().val][items.back().indexInMap] = index;
        valToIndices[val].pop_back();
        if (valToIndices[val].empty())
        valToIndices.erase(val);
        items[index] = items.back();
        items.pop_back();
        return true;
    }

    int getRandom()
    {
        const int index = rand() % items.size();
        return items[index].val;
    }

    private:
    unordered_map<int, vector<int>> valToIndices;
    vector<Item> items;
};


//  Your RandomizedCollection object will be instantiated and called as such:
//  RandomizedCollection* obj = new RandomizedCollection();
//  bool param_1 = obj->insert(val);
//  bool param_2 = obj->remove(val);
//  int param_3 = obj->getRandom();

*/