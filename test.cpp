#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()==0)return false;
        int q = array[0].size()-1, p = array.size()-1;
        for(int i=0;i<array[0].size();i++){
            if(array[0][i] == target){
                return true;
            }else if(array[0][i] > target){
                q = i;
                break;
            }
        }
        for(int i=0;i<array.size();i++){
            if(array[i][0] == target){
                return true;
            }else if(array[i][0] > target){
                p = i;
                break;
            }
        }
        for(int i=0;i<=p;i++){
            vector<int> v = array[i];
            int l = 0, r = q;
            while(l<=q){
                int mid = (l+r)>>2;
                if(v[mid] == target){
                    return true;
                }else if(v[mid]>target){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int> > array;
    int target;
    vector<int> v{1,2,8,9};
    array.push_back(v);
    vector<int> v1{1,2,8,9};
    array.push_back(v1);
    vector<int> v2{1,2,8,9};
    array.push_back(v2);
    vector<int> v3{1,2,8,9};
    array.push_back(v3);

    Solution s=Solution();
    cout<<s.Find(7,array)<<endl;
    return 0;
}