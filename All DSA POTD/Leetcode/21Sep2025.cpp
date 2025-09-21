#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem
{
public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (const vector<int> &e : entries)
        {
            const int shop = e[0];
            const int movie = e[1];
            const int price = e[2];
            unrented[movie].insert(make_pair(price, shop));
            shopAndMovieToPrice[make_pair(shop, movie)] = price;
        }
    }

    vector<int> search(int movie)
    {
        vector<int> ans;
        int i = 0;

        for (auto it = unrented[movie].begin(); it != unrented[movie].end() && i < 5; ++it, ++i)
        {
            ans.push_back(it->second);
        }

        return ans;
    }

    void rent(int shop, int movie)
    {
        const int price = shopAndMovieToPrice[make_pair(shop, movie)];
        unrented[movie].erase(make_pair(price, shop));
        rented.insert(make_pair(price, make_pair(shop, movie)));
    }

    void drop(int shop, int movie)
    {
        const int price = shopAndMovieToPrice[make_pair(shop, movie)];
        unrented[movie].insert(make_pair(price, shop));
        rented.erase(make_pair(price, make_pair(shop, movie)));
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> ans;
        int i = 0;

        for (auto it = rented.begin(); it != rented.end() && i < 5; ++it, ++i)
        {
            ans.push_back({it->second.first, it->second.second});
        }

        return ans;
    }

private:
    struct PairHash
    {
        size_t operator()(const pair<int, int> &p) const
        {
            return p.first ^ (p.second << 16); // better hash than XOR only
        }
    };

    // {movie: (price, shop)}
    unordered_map<int, set<pair<int, int>>> unrented;

    // {(shop, movie): price}
    unordered_map<pair<int, int>, int, PairHash> shopAndMovieToPrice;

    // (price, (shop, movie))
    set<pair<int, pair<int, int>>> rented;
};

// C++ 20 Solution
//  #include <bits/stdc++.h>
//  using namespace std;
//  class MovieRentingSystem
//  {
//  public:
//      MovieRentingSystem(int n, vector<vector<int>> &entries)
//      {
//          for (const vector<int> &e : entries)
//          {
//              const int shop = e[0];
//              const int movie = e[1];
//              const int price = e[2];
//              unrented[movie].insert({price, shop});
//              shopAndMovieToPrice[{shop, movie}] = price;
//          }
//      }

//     vector<int> search(int movie)
//     {
//         vector<int> ans;
//         int i = 0;

//         for (const auto &[price, shop] : unrented[movie])
//         {
//             ans.push_back(shop);
//             if (++i >= 5)
//                 break;
//         }

//         return ans;
//     }

//     void rent(int shop, int movie)
//     {
//         const int price = shopAndMovieToPrice[{shop, movie}];
//         unrented[movie].erase({price, shop});
//         rented.insert({price, {shop, movie}});
//     }

//     void drop(int shop, int movie)
//     {
//         const int price = shopAndMovieToPrice[{shop, movie}];
//         unrented[movie].insert({price, shop});
//         rented.erase({price, {shop, movie}});
//     }

//     vector<vector<int>> report()
//     {
//         vector<vector<int>> ans;
//         int i = 0;

//         for (const auto &[_, shopAndMovie] : rented)
//         {
//             ans.push_back({shopAndMovie.first, shopAndMovie.second});
//             if (++i >= 5)
//                 break;
//         }

//         return ans;
//     }

// private:
//     struct PairHash
//     {
//         size_t operator()(const pair<int, int> &p) const
//         {
//             return p.first ^ p.second;
//         }
//     };

//     // {movie: (price, shop)}
//     unordered_map<int, set<pair<int, int>>> unrented;

//     // {(shop, movie): price}
//     unordered_map<pair<int, int>, int, PairHash> shopAndMovieToPrice;

//     // (price, (shop, movie))
//     set<pair<int, pair<int, int>>> rented;
// };