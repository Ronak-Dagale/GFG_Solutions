//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  public:
    // Constructor for initializing the cache capacity with the given value.
    int size;
    list<pair<int,int>>l;
    map<int,list<pair<int,int>>::iterator>mp;
    LRUCache(int cap) {
        // code here
        size=cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(mp.find(key)!=mp.end())
        {
          auto tmp=mp[key];
          int res=tmp->second;
          l.erase(tmp);
          l.push_front({key,res});
          mp[key]=l.begin();
          return res;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(mp.find(key)!=mp.end())
        {
            l.erase(mp[key]);
            l.push_front({key,value});
            mp[key]=l.begin();
        }
        else
        {
            if(mp.size()==size)
            {
               mp.erase(l.back().first);
               l.pop_back();
            }
            l.push_front({key,value});
            mp[key]=l.begin();
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends