// Combination 
// using STL's next_permutation
 
#include<iostream>
#include<algorithm>
#include<vector>
 
using namespace std;
 
bool desc(int a, int b){
    return a > b;
}
 
vector <int> sub;
int main(){
    int n;
    int r;
    vector<int> idx;
    vector<int> list;
    
    cout << "몇 개의 원소를 가진 배열입니까?" << '\n';
    cin >> n;
    cout << "원소를 삽입하세요" << '\n';
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        list.push_back(tmp);
    }
    
    cout << "몇 개의 원소를 뽑아냅니까?" << '\n';
    cin >> r;
    for(int i = 0; i < r; i++)
        idx.push_back(1);
    for(int i = 0; i < n-r; i++)
        idx.push_back(0);
    sort(idx.begin(), idx.end(),desc);
    
    do{
        for(int i = 0; i < n; i++){
            if(idx[i] == 1)
            	sub.push_back(list[i]);
									
        }
        for(int k=0;k<sub.size();k++)
        {
        	printf("%d ",sub[k]);
		}
		printf("\n");
        sub.clear();
    }while(next_permutation(idx.begin(), idx.end(),desc));
    
    return 0;
}


