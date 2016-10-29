/*#include<vector>
#include<iostream>
#include<list>
using namespace std;*/

class Digraph
{
private:
	const int verticesNum;
	int edgesNum;
	//vector<vector<int> > adj;
	list<int> *adj;

public:
	Digraph(int v) : verticesNum(v)
	{
		edgesNum = 0;
		adj = new list<int>[v];
	}
	int vecNum() { return verticesNum; }
	int edgNum() { return edgesNum; }
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		edgesNum++;
	}
	list<int> adjVertex(int v)
	{
		return adj[v];
	}

};


class DirectedDFS
{
public:
	DirectedDFS(Digraph G, vector<int> s)
	{
		int len = G.vecNum();
		marked.clear();
		marked.resize(len,false);
		/*for (int i=0; i<len; i++)
		{
			marked[i] = false;
		}*/
		dfs(G, s);
	}

	vector<bool> getMarked()
	{
		return marked;
	}

	void dfs(Digraph G, vector<int> vSet)
	{
		for (int v : vSet)
		{
			dfsHelper(G, v);
		}
	}

private:
	vector<bool> marked;
	//int startPoint;
	//stack<int> vertices;

	void dfsHelper(Digraph G, int start)
	{
		marked[start] = true;
		for (int i : G.adjVertex(start))
		{
			if (!marked[i])
			{
				dfsHelper(G, i);
			}
		}
	}
};


class Solution {
public:
	bool isMatch(string s, string p)
	{
		NFA(p);
		return recognize(s);
	}

private:
	//char* re;
	Digraph* G;
	int statusNum;
	string re;
	void NFA(string regexp)
	{
		//stack<int> ops;
		//re = regexp.c_str();
		re = regexp;
		statusNum = regexp.size();
		G = new Digraph(statusNum + 1);

		for (int i = 0; i<statusNum; i++)
		{
			//int lp = i;
			if (i<statusNum - 1 && regexp[i + 1] == '*')
			{
				G->addEdge(i, i + 1);
				G->addEdge(i + 1, i);
			}
			if (regexp[i] == '*')
			{
				G->addEdge(i, i + 1);
			}
		}
	}

	bool recognize(string s)
	{
		vector<int> start;
		start.push_back(0);
		DirectedDFS *dfs = new DirectedDFS(*G, start);
		vector<int> pc;
		for (int v = 0; v<G->vecNum(); v++)
		{
			if ((dfs->getMarked())[v])
			{
				pc.push_back(v);
			}
		}

		for (int i = 0; i<s.size(); i++)
		{
			vector<int> match;
			for (int v : pc)
			{
				if (v<statusNum)
				{
					if (re[v] == s[i] || re[v] == '.')
					{
						match.push_back(v + 1);
					}
				}
			}
			pc.clear();
			dfs = new DirectedDFS(*G, match);
			for (int v = 0; v<G->vecNum(); v++)
			{
				if ((dfs->getMarked())[v])
				{
					pc.push_back(v);
				}
			}

		}

		for (int v : pc)
			if (v == statusNum)
				return true;

		return false;
	}
};


/*int main()
{
	Solution s;
	string sp = "ACD";
	string p = "";
	if (s.isMatch(sp, p))
	{
		cout << "matched" << endl;
	}
	else
	{
		cout << "no matched";
	}
}*/

