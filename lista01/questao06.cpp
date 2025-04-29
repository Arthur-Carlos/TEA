#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, x;
    vector<pair<int,int>> v;
    cin >> n >> x;
    v.resize(n);
    for(size_t i=0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }

    sort(v.begin(),v.end());
    int i = 0;
    int j =v.size()-1;
    int k =v.size()-2;
    int l =v.size()-3;
    while(i<j){
        if(v[i].first + v[j].first + v[k].first + v[l].first == x){
            cout << v[i].second << ' ' << v[j].second << ' ' <<v[k].second << ' ' << v[l].second << '\n';
            return 0;
        } else if(v[i].first + v[j].first + v[k].first + v[l].first < x ){
            i++;
        } else{
            j--;
        }
    }

    while(i<k){
        if(v[i].first + v[j].first + v[k].first + v[l].first == x){
            cout << v[i].second << ' ' << v[j].second << ' ' <<v[k].second << ' ' << v[l].second << '\n';
            return 0;
        } else if(v[i].first + v[j].first + v[k].first + v[l].first < x ){
            i++;
        } else{
            k--;
        }
    }

    while(i<l){
        if(v[i].first + v[j].first + v[k].first + v[l].first == x){
            cout << v[i].second << ' ' << v[j].second << ' ' <<v[k].second << ' ' << v[l].second << '\n';
            return 0;
        } else if(v[i].first + v[j].first + v[k].first + v[l].first < x ){
            i++;
        } else{
            j--;
        }
    }
    cout << "-1\n";
    return 0;
}
