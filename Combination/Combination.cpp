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
    
    cout << "�� ���� ���Ҹ� ���� �迭�Դϱ�?" << '\n';
    cin >> n;
    cout << "���Ҹ� �����ϼ���" << '\n';
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        list.push_back(tmp);
    }
    
    cout << "�� ���� ���Ҹ� �̾Ƴ��ϱ�?" << '\n';
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


