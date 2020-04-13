//완전탐색중, 소수찾기  with 재귀함수
#include <vector>
#include <string>
#include <iostream>//메인 출력용
#include <algorithm>
#include <set>
using namespace std;

//경우의 수 찾기용, 경우의 수 담기용, 문자열 합치기용 //결국, 소수를 찾는데 소스가 되는것은 문자열합치기용인 set컨테이너변수인 p이다.
void push(vector<pair<char, bool>> piece, set<int>& p, string a = "", int cnt = 0) {
	
	//처음붙터 끝까지 반복문을 돌린다.
	for (int j = 0; j < piece.size(); j++) {

		//j인덱스에 관련된 piece가 사용중이지 않다면
		if (!piece[j].second) {

			//사용중으로 변경
			piece[j].second = true;
			
			//문자열 추가
			a += piece[j].first;
			
			//현재 문자열을 경우의 수에 담기
			p.insert(stoi(a));
			//cout << "p : " << a << endl;
			cnt++;
		}
		else//사용중이라면 위로 보내기
			continue;

		//모두 사용중이 아니라면 재귀
		if (cnt != piece.size())    push(piece, p, a, cnt);
		
		//사용을 완료하면 사용하지 않음으로 바꾸기
		piece[j].second = false;
		
		//돌아가기 전에 문자열을 하나 감소 (substr(추출할 원소의 시작인덱스,추출할 원소개수)로, str(0,2)라면, 0인덱스부터 2개를 추출한다는 뜻이다.
		a = a.substr(0, a.length() - 1);
		cnt--;
	}
}

//소수판별
bool Decheck(int a) {
	for (int i = 2; i <= sqrt(a); i++)
		if (a % i == 0)//i가 나누어떨어지면 소수가 아님 
			return false;
	return true;
}

int solution(string numbers) {
	int answer = 0;
	
	//모든 경우의 수를 찾기 위한 용도
	vector<pair<char, bool>> piece;

	//모든 경우의 수를 모으는 곳(set컨테이너의 특성상, 011과 11을 insert했을때, 같다고 보기 때문에 문제의 중복불가가 가능해짐)
	set<int> p;

	//반복문으로 numbers를 쪼개서 piece에 집어넣는다.
	for (int i = 0; i < numbers.length(); i++)
		piece.push_back({ numbers[i], false });  //초기화단계이므로 numbers의 어떤 원소도 참조하지 않았기 떄문에 기본적으로 false를 넣어줌
		
												 
	//모든 경우의 수 찾기(위에 함수있음)
	push(piece, p);
	
	for (auto c : p) {
		//0과 1인경우는 소수에서 제외
		if (c == 0 || c == 1)    continue;
		//소수를 체크해서 소수면 카운트 증가
		if (Decheck(c))        answer++;
	}
	return answer;
}


int main() {
	int ans_1=solution("011");
	cout << "011 : " << ans_1 << endl;

	return 0;
}