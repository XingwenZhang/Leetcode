/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
   		if(root==nullptr)
   		{
   			return;
   		}  
   		else
   		{
   			bfs(root);
   		}
    }
private:
	/*void bfs(TreeLinkNode* root)
	{
		queue<TreeLinkNode*> leafQue;
		leafQue.push(root);
		while(!leafQue.empty())
		{
			int len = leafQue.size();
			vector<TreeLinkNode*> temp;
			while(!leafQue.empty())
			{
				temp.push_back(leafQue.front());
				leafQue.pop();
			}
			for(int i=0; i<len-1; i++)
			{
				temp[i]->next = temp[i+1];
				//suppose binary tree is perfect, so check one child is OK
				if(temp[i]->left)
				{
					leafQue.push(temp[i]->left);
					leafQue.push(temp[i]->right);
				}
				
			}
			//the default value of next is NULL, no need handle the last one
			if(temp[len-1]->left)
			{
				leafQue.push(temp[len-1]->left);
				leafQue.push(temp[len-1]->right);
			}
		}
	}*/

	void bfs(TreeLinkNode* root)
	{
		queue<TreeLinkNode*> leafQue;
		leafQue.push(root);
		while(!leafQue.empty())
		{
			int len = leafQue.size();
			TreeLinkNode* prev = nullptr;
			//push the nodes in reverse order
			while(len--)
			{
				TreeLinkNode* temp = leafQue.front();
				leafQue.pop();

				temp->next = prev;
				if(temp->right) leafQue.push(temp->right);
				if(temp->left) leafQue.push(temp->left);
				prev = temp;

			}
		}
	}
};



//recursion
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
   		if(root==nullptr)
   		{
   			return;
   		}
   		TreeLinkNode* rootTemp = root;
   		while(rootTemp)
   		{
   			TreeLinkNode* cur = rootTemp;
   			while(cur)
   			{
   				if(cur->left)
   					cur->left->next = cur->right;
   				if(cur->next && cur->right)
   				{
   					cur->right->next = cur->next->left;
   				}
   				cur=cur->next;
   			}
   			
   			rootTemp = rootTemp->left;
   		}
    }
};



/*
//recursion
//for No117
class Solution
{
public:
	void connect(TreeLinkNode* root)
	{
		if(root==nullptr)		
		{
			return;
		}
		else
		{
			TreeLinkNode* levelPointer = root;
			while(levelPointer)
			{
				TreeLinkNode* cur = levelPointer;
				while(cur)
				{
					if(cur->left)
					{
						if(cur->right)
						{
							cur->left->next=cur->right;
						}
						else 
						{
							TreeLinkNode* cursor = cur->next;
							while(cursor)
							{
								if(!isLeaf(cursor))
								{
									if(curosr->left)
									{
										cur->left->next = cursor->left;
									}
									else
									{
										cur->left->next = cursor->right;
									}
									cur = cursor;
									break;
								}
								cursor = cursor->next;

							}
						}
					}
					else
					{
						if(cur->next)
						{
							if(!isLeaf(cur->next))
							{
								if(cur->next->left)
								{
									cur->right->next = cur->next->left;
								}
								else
								{
									cur->right->next = cur->next->right;
								}
							}
							else
							{
								TreeLinkNode* cursor2 = cur->next->next;
								while(cursor2)
								{
									if(!isLeaf(cursor2))
									{
										if(cursor2->left)
										{
											cur->right->next = cursor2->left;
										}
										else
										{
											cur->right->next = cursor2->right;
										}
										cur=cursor2;
										break;
									}
									cursor2=cursor2->next;
								}
							}
						}


					}

				}
				//update levelPoint
				//todo
			}

		}
	}
private:
	bool isLeaf(TreeLinkNode* node)
	{
		if(node->left==nullptr && node->right==nullptr)
			return true;
		else
			return false;
	}
};*/