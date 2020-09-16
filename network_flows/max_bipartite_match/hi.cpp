// 初始化好圖了 ， 但還缺把 source 跟 sink 接上原圖


#include <bits/stdc++.h>
using namespace std;

#define M 100
#define N 100

/*
  Q: job 會有 edge 指向 applicants 嗎?

 */


int maxBPM(bool bpGraph[M][N],int m,int n);
int main()
{
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;		
		bool bpGraph[M][N];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>bpGraph[i][j];
		cout << maxBPM(bpGraph,m,n)<<endl;
	}
    return 0;
}// } Driver Code Ends


typedef struct EDGENODE {
  int y;
  int residual;
  int flow;
  int capacity;
} edgenode;

void insert_edge(vector<vector<edgenode>> &adj, int x, int y) {
  edgenode e;
  e.y = y;
  e.residual = 1;
  e.capacity = 1;
  e.flow = 0;
  
  adj[x].push_back(e);
}

/*Complete the function below*/
int maxBPM(bool bpGraph[M][N],int m,int n)
{
//add code here.

  unordered_map<int, int> m2index;
  unordered_map<int, int> n2index; 
  vector<vector<edgenode>> adj = vector<vector<edgenode>>(m+n+2);

  int source = 0;
  int sink;

  cout << " m : " << m << endl;
  cout << " n : " << n << endl;

  int index = 1;
  for(int i = 0;i < m;i++) {
    m2index[i] = index;
    index++; 
  }
  for(int i = 0;i < n;i++) {
    n2index[i] = index;
    index++;
  }
  sink = index;

  cout << "source : " << source << endl;
  cout << "sink : " << sink << endl;  

  for(int i = 0;i < m;i++) {
    for(int j = 0;j < n;j++) {
      /*if(i == j ) {
        continue;
      }*/
      if(bpGraph[i][j]) {
        cout << "a new edge !" << endl;
        insert_edge(adj, m2index[i], n2index[j]);
      }
    } 
  }


  for(int i = 1;i < m + n;i++) {
    for(int j = 0;j < adj[i].size();j++) {
      cout << " " << i << " : "  <<adj[i][j].y << endl;
    }
    cout << endl;
  }

  return 0;
}





