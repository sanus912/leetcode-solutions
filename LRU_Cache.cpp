

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int k, int v) : key(k), value(v) {};
    };

    int capacity;
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;

public:

    LRUCache(int capacity) {
        this -> capacity = capacity;
    }

    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()) return -1;

        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->value;
    }


    void set(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()) {
            if(cacheList.size() == capacity) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }

            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
        else {
            cacheMap[key] -> value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }

    void printlist()
    {
        for (auto a : cacheList )
            cout << a.key << " " << a.value << ", ";
        cout << endl;
    }
};


int main() {

    LRUCache myLRU(5);

    // set some initial values:
    for (int i=0; i<5; ++i)
        myLRU.set(i,i*10);

    for (int i=0; i<3; ++i)
        cout << myLRU.get(i) << " ";
    cout << endl;

    myLRU.printlist();

    for (int i=5; i<7; ++i)
        myLRU.set(i,i*3);

    myLRU.printlist();
    return 0;
}
