#include <bits/stdc++.h>
using namespace std;

class ToyTCPStream {
    // Initializing a string to store data stream.
    string res;
public :
    ToyTCPStream() {
        res = "";
    }
    void receive(int chunk, vector<char> data) {
        chunk--;
        // Increase size of res if its size is smaller.
        if(res.size() < chunk) {
            for(int i = res.size(); i <= chunk; i++) {
                res.push_back(' ');
            }
        }
        // Storing data in res while traversing data vector.
        for(int i = 0; i < data.size(); i++) {
            if(res.size() <= chunk) {
                res.push_back(data[i]);
            }
            else {
                res[chunk] = data[i];
            }
            chunk++;
        }
    }
    int read(vector<char>& data) {
        // Clearing data vector if there is some data already present in it.
        data.clear();
        for(char& character : res) {
            data.push_back(character);
        }
        return data.size();
    }
};

int main() {
    // Initializing object.
    ToyTCPStream t;
    // To store data coming from read method.
    vector<char> data;

    // Receiving some data.
    vector<char> v = {'m', ' ', 'A', 'r'};
    t.receive(4, v);
    v = {'I', ' ', 'a'};
    t.receive(1, v);

    // Reading data.
    int sz = t.read(data);
    for(int i = 0; i < sz; i++) {
        cout<<data[i];
    }
    
    // Receiving some more data.
    v = {'y', 'a', 'n'};
    t.receive(8, v);

    // Reading data.
    int sz = t.read(data);
    for(int i = 0; i < sz; i++) {
        cout<<data[i];
    }
    return 0;
}
