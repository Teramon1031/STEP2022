#include <bits/stdc++.h>
using namespace std;

int main (){
    // vector<long long> cnt={1,2,5,10,50,100,200,500,1000,2000,3000};
    cout << "format: N << ' ' << ms" << endl;
    long long N = 1;

    while(N<1010){
    
    vector<vector<int>> a(N,vector<int>(N,1));
    vector<vector<int>> b(N,vector<int>(N,2));
    vector<vector<int>> c(N,vector<int>(N,0));


    auto start = chrono::system_clock::now();

    for(long long i=0;i<N;i++){
        for(long long j=0; j<N; j++){
            for(long long k=0; k<N; k++){
              c.at(i).at(j)+=a.at(i).at(k)*b.at(k).at(j);
            }
        }
    }

    auto end = chrono::system_clock::now();

    // for(int i=0;i<N;i++){
    //     for(int j:c.at(i)){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    auto dur = end-start;
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();

    cout << N << ' ' << msec << endl;
    if(N<10){
        N++;
    }else{
        N+=10;
    // }else if(N<1000){
    //     N+=100;
    // }else if(N<10000){
    //     N+=1000;
    // }else{
    //     N+=10000;
    // }
    }
    }

    return 0;

}
