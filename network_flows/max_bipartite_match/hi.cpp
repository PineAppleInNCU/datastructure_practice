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


/*Complete the function below*/
int maxBPM(bool bpGraph[M][N],int m,int n)
{
//add code here.
 return 0;
}
