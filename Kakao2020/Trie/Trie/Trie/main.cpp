#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX_N 10000

using namespace std;

struct Trie 
{
	Trie* next[10];
	bool term;
	Trie() : term(false) 
	{
		memset(next, 0, sizeof(next));
	}
	~Trie() 
	{
		for (int i = 0; i < 10; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(const char* key) 
	{
		if (*key == '\0')
			term = true;
		
		else 
		{
			int curr = *key - '0';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			
			next[curr]->insert(key + 1);
		}
	}

	bool find(const char* key) 
	{
		if (*key == '\0')
			return 0;
	
		if (term)
			return 1;
		
		int curr = *key - '0';
		return next[curr]->find(key + 1);
	}
};


int t, n, r;
char a[MAX_N][11];

int main() {
	
	scanf_s("%d", &t);
	
	while (t--) 
	{
		scanf_s("%d", &n);
		getchar();
		for (int i = 0; i < n; i++)
		{
			scanf_s("%s", &a[i]);
		}

		Trie *root = new Trie;
		r = 0;
		
		for (int i = 0; i < n; i++)
		{
			root->insert(a[i]);
		}

		for (int i = 0; i < n; i++) 
		{
			if (root->find(a[i])) 
			{
				r = 1;
			}
		}
		printf("%s\n", r ? "NO" : "YES");
	}

	return 0;
}
