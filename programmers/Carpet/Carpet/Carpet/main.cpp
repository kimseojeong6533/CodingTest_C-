#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;



vector<int> solution(int brown, int red) {
	vector<int> answer;
	int red_width, red_length = 0;  //가로,세로


	vector<int> arr;

	//red의 약수를 구해서 약수배열에 담자

	for (int j = 1; j <= red; j++)
	{
		if (red%j == 0)
		{
			arr.push_back(j);
		}
	}

	if (arr.size() % 2 == 0) //약수의 개수가 짝수이면
	{
		red_width = (arr[arr.size() / 2]);      //가로길이,세로길이순으로 삽입됨. 
		red_length = (arr[arr.size() / 2 - 1]);
	}
	else  //약수의 개수가 홀수이면,  
	{
		red_width = (arr[(arr.size() / 2)]);
		red_length = red_width;
	}

	cout << red_width << " " << red_length << endl;

	int width = red_width + 2;
	int length = red_length + 2;


	if ((width*length - red) == brown)
	{
		answer.push_back(width);
		answer.push_back(length);
	}

	return answer;
}

int main(void) {

	int brown = 24;
	int red = 24;
	vector<int> v;
	v = solution(brown, red);

	for (auto i : v)
	{
		cout << i << " ";
	}

	system("pause");
	return 0;
}