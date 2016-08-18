#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef std::vector<pair<int, int> > vpii;

struct Score {
  int left;
  int right;
  int up;
  int down;
};

int HighScore(vpii& flower, vpii& wall, const int N) {
   // if (N<=0){
   // 	return 0;
   // }

   // Static
   // int grid[N][N];
   // memset(grid, 0, sizeof(grid)); //or -1
   // cout<<grid[3][5]<<endl;
   

   // Dynamic
   // int** grid= new int*[N];
   // for(int i=0; i<N; ++i){
   // 	 grid[i]=new int[N];
   // }
   // cout<<grid[3][5]<<endl;

   // for(int i = 0; i < N; ++i) {
   //  delete [] grid[i];
   // }
   // delete [] grid;
   

   // Static
   // Score scores[N][N];
   // memset(scores, 0, sizeof(scores));
   // scores[2][3].right=5;
   // scores[2][3].up=7;


   // //Dynamic
   // Score** scores = new Score*[N];
   // for(int i=0;i<N;++i){
   // 	scores[i]=new Score[N];
   // }
   // scores[2][3].right=5;
   // scores[2][3].up=7;
   // cout<<scores[2][3].up<<scores[2][3].down<<scores[2][3].left<<scores[2][3].right<<endl;
   // for(int i=0;i<N;++i){
   // 	delete [] scores[i];
   // }
   // delete [] scores; 
   return -1;

}

int main() {
  vpii flower;
  vpii wall;
  string temp = "3523";
  temp[2]=temp[2]-7;
  cout<<temp<<endl;
  //HighScore(flower, wall, 10);
}