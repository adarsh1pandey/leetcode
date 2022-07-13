class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        int c=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            pair<int,int>temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            image[x][y]=color;
            if(x-1>=0 and !visited[x-1][y] and image[x-1][y]==c){
                q.push({x-1,y});
                visited[x-1][y]=true;
            }
             if(x+1<m and !visited[x+1][y] and image[x+1][y]==c){
                q.push({x+1,y});
                 visited[x+1][y]=true;
            }
             if(y-1>=0 and !visited[x][y-1] and image[x][y-1]==c){
                q.push({x,y-1});
                 visited[x][y-1]=true;
            }
             if(y+1<n and !visited[x][y+1] and image[x][y+1]==c){
                q.push({x,y+1});
                 visited[x][y+1]=true;
            }
        }
        return image;
        
        
    }
};