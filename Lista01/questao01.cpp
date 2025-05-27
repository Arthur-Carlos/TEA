#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    vector<int> v;
    cin >> n;
    v.resize(n);
    for(auto& x: v){
        cin >> x;
    }
    int unico = v.size() > 0;
    sort(v.begin(),v.end());
    for(size_t i = 1; i<v.size(); i++ ){
        if(v[i]!=v[i-1]){
            unico ++;
        }
    }
    cout << unico << '\n';
    return 0;
}
