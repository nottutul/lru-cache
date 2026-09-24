#include <bits/stdc++.h>
using namespace std;

class LRUCache{
    private:
        int capacity;
        list<pair<string, int>> cacheList;
        unordered_map<string, list<pair<string,int>>::iterator> cacheMap;
    
    public:
        LRUCache(int cap): capacity(cap){
            if(cap <= 0){
                throw invalid_argument("Capacity must be positive.");
            }
        }

        // get value by key. O(1)
        int get(string key){
            // if key does not exist
            if(cacheMap.find(key)==cacheMap.end()){
                return -1;
            }

            // if exists move it to the front and return value
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return cacheMap[key]->second;
            
        }

        // put  or update key value pair. O(1);
        void put(string key, int value){
            // if already exist update it and move it to the front
            if(cacheMap.find(key) != cacheMap.end()){ 
                // update the value
                cacheMap[key]->second = value;
                // move to front
                cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
                return;
            }

            // if capacity full
            if(cacheList.size() >= capacity){
                auto lastNode = cacheList.back();
                // remove from map and list
                cacheMap.erase(lastNode.first);
                cacheList.pop_back(); 
            }

            // insert new pair at front
            cacheList.push_front({key, value});
            // store iterator to new node in map
            cacheMap[key] = cacheList.begin(); 
        }
    
};


int main() {
    int size;
    cout << "Enter the capacity of the cache: ";
    cin >> size;
    cout << endl;

    try {
        LRUCache cache(size);
        cout << "LRU Cache initialized successfully with capacity " << size << ".\n";
        cout << "--------------------------------------------------\n";
        cout << "Available Commands:\n";
        cout << "  1. put <key> <value>  (e.g., put A 10)\n";
        cout << "  2. get <key>          (e.g., get A)\n";
        cout << "  3. exit\n";
        cout << "--------------------------------------------------\n";

        string command;
        while (true) {
            cout << "\nEnter command: ";
            cin >> command;

            if (command == "exit") {
                cout << "Exiting program.\n";
                break;
            } 
            else if (command == "put") {
                string key;
                int value;
                cin >> key >> value;
                cache.put(key, value);
                cout << "Successfully inserted/updated [" << key << " -> " << value << "]\n";
            } 
            else if (command == "get") {
                string key;
                cin >> key;
                int result = cache.get(key);
                cout << "Result for : get(\"" << key << "\") -> " << result << endl;
            } 
            else {
                cout << "Invalid command! Use 'put', 'get', or 'exit'.\n";
            }
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

