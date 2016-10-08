class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int sizeNote = ransomNote.size();
        int sizeMag = magazine.size();
        int *visited = new int[sizeMag];
        for(int k=0; k<sizeMag; k++)
        {
        	visited[k]=0;
        }
        int flag = 0;
        for(int i=0; i<sizeNote; i++)
        	for(int j=0; j<sizeMag; j++)
        	{
        		if((ransomNote[i]==magazine[j])&&(visited[j]==0))
        		{
        			visited[j]=1;
        			flag++;
        			//it is cruial because once you find you must skip out
        			//or you may find another same char
        			//and flag might increase again for the same char
        			break;
        		}
        	}
        delete[] visited;
        if(flag==sizeNote)
        {
        	return true;
        }
        else
        {
        	return false;
        }
    }
};