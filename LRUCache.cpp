#include <unordered_map>
#include <utility>
#include <list>
#include <iostream>

using namespace std;

class LRUCache{
    int _capacity;
    list<pair<int,int>> _cache;
    unordered_map<int, list<pair<int, int>>::iterator> _mapping;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (_mapping.count(key)) {
            int res = _mapping[key]->second;
            _cache.erase(_mapping[key]);
            _cache.push_front(make_pair(key, res));
            _mapping[key] = _cache.begin();
            return res;
        } 
        return -1;
    }
    
    void set(int key, int value) {
        if (_mapping.count(key)) {
            _cache.erase(_mapping[key]);
            _cache.push_front(make_pair(key, value));
            _mapping[key] = _cache.begin();
        } else {
            if (_cache.size() == _capacity) {
                _mapping.erase(_cache.back().first);
                _cache.pop_back();
            }
            _cache.push_front(make_pair(key, value));
            _mapping[key] = _cache.begin();
        }
    }
};

int main() {
    LRUCache cache(3);
    cache.set(3,1);
    cache.set(5,2);
    cache.set(4,3);
    cache.set(6,4);
    cache.set(7,5);
    cout << cache.get(3) << endl;
}