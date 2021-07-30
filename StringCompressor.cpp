#include <bits/stdc++.h>
using namespace std;

class StringCompressor {
public :
    string compress(string& data) {
        if(data.size() == 1) {
            return data;
        }
        int traversalIndex = 0, compressedIndex = 0;
        while(traversalIndex < data.size()) {
            data[compressedIndex] = data[traversalIndex];
            int cnt = 0;
            while(traversalIndex < data.size() && data[traversalIndex] == data[compressedIndex]) {
                traversalIndex++, cnt++;
            }
            if(cnt == 1) {
                compressedIndex++;
            }
            else {
                string number = to_string(cnt);
                for(char& c : number) {
                    data[++compressedIndex] = c;
                }
                compressedIndex++;
            }
        }
        data.resize(compressedIndex);
        return data;
    }
    string decompress(string data) {
        string res;
        int i = 0;
        while(i < data.size() - 1) {
            res.push_back(data[i++]);
            char c = data[i];
            int num = 0;
            while(i < data.size() && c >= 48 && c <= 57) {
                num = (num * 10) + (c - 48);
                c = data[i++];
            }
            for(int it = 0; it < num - 1; it++) {
                res.push_back(res.back());
            }
        }
        return res;
    }
};

int main() {
    // Initializing object.
    StringCompressor sc;

    string data = "AAAAvsbnsdnadasdddddddscc";

    cout<<sc.compress(data)<<"\n";
    cout<<sc.decompress(data)<<"\n";
    return 0;
}
