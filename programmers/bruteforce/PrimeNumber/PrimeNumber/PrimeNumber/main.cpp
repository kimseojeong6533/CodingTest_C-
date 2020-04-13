//����Ž����, �Ҽ�ã��  with ����Լ�
#include <vector>
#include <string>
#include <iostream>//���� ��¿�
#include <algorithm>
#include <set>
using namespace std;

//����� �� ã���, ����� �� ����, ���ڿ� ��ġ��� //�ᱹ, �Ҽ��� ã�µ� �ҽ��� �Ǵ°��� ���ڿ���ġ����� set�����̳ʺ����� p�̴�.
void push(vector<pair<char, bool>> piece, set<int>& p, string a = "", int cnt = 0) {
	
	//ó������ ������ �ݺ����� ������.
	for (int j = 0; j < piece.size(); j++) {

		//j�ε����� ���õ� piece�� ��������� �ʴٸ�
		if (!piece[j].second) {

			//��������� ����
			piece[j].second = true;
			
			//���ڿ� �߰�
			a += piece[j].first;
			
			//���� ���ڿ��� ����� ���� ���
			p.insert(stoi(a));
			//cout << "p : " << a << endl;
			cnt++;
		}
		else//������̶�� ���� ������
			continue;

		//��� ������� �ƴ϶�� ���
		if (cnt != piece.size())    push(piece, p, a, cnt);
		
		//����� �Ϸ��ϸ� ������� �������� �ٲٱ�
		piece[j].second = false;
		
		//���ư��� ���� ���ڿ��� �ϳ� ���� (substr(������ ������ �����ε���,������ ���Ұ���)��, str(0,2)���, 0�ε������� 2���� �����Ѵٴ� ���̴�.
		a = a.substr(0, a.length() - 1);
		cnt--;
	}
}

//�Ҽ��Ǻ�
bool Decheck(int a) {
	for (int i = 2; i <= sqrt(a); i++)
		if (a % i == 0)//i�� ����������� �Ҽ��� �ƴ� 
			return false;
	return true;
}

int solution(string numbers) {
	int answer = 0;
	
	//��� ����� ���� ã�� ���� �뵵
	vector<pair<char, bool>> piece;

	//��� ����� ���� ������ ��(set�����̳��� Ư����, 011�� 11�� insert������, ���ٰ� ���� ������ ������ �ߺ��Ұ��� ��������)
	set<int> p;

	//�ݺ������� numbers�� �ɰ��� piece�� ����ִ´�.
	for (int i = 0; i < numbers.length(); i++)
		piece.push_back({ numbers[i], false });  //�ʱ�ȭ�ܰ��̹Ƿ� numbers�� � ���ҵ� �������� �ʾұ� ������ �⺻������ false�� �־���
		
												 
	//��� ����� �� ã��(���� �Լ�����)
	push(piece, p);
	
	for (auto c : p) {
		//0�� 1�ΰ��� �Ҽ����� ����
		if (c == 0 || c == 1)    continue;
		//�Ҽ��� üũ�ؼ� �Ҽ��� ī��Ʈ ����
		if (Decheck(c))        answer++;
	}
	return answer;
}


int main() {
	int ans_1=solution("011");
	cout << "011 : " << ans_1 << endl;

	return 0;
}