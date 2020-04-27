#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string new_id = "ace123";

	string sub1="";
	string sub2="";
	for (int i = 0; i < new_id.size(); i++)
	{
		if (new_id[i] >= 97 && new_id[i] <= 122) //¼Ò¹®ÀÚ
		{
			sub1 += new_id[i];
		}
		else
		{
			sub2 += new_id[i];
		}
	}
	printf("%s, %s", sub1, sub2);
	return 0;
}