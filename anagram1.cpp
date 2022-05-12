#include <bits/stdc++.h>
using namespace std;

/*
- 入力
辞書ファイル -> dic.txt
単語 -> input.txt
*/

int anagram1(string random_word, vector<pair<string,string>> dic){
    if(random_word==" "){
        return 0;
    }
    sort(random_word.begin(),random_word.end());
    long long low=0;
    long long high=dic.size()-1; 
        
    while(low<=high){
        long long mid=(low+high)/2;
        long long result = strcmp(random_word.c_str(), dic.at(mid).first.c_str());
        if(result == 0){
            cout << dic.at(mid).second <<endl;
                if(mid>0){
                long long lower=mid-1;
                    while(dic.at(lower).first == dic.at(mid).first){
                        cout << dic.at(lower).second << endl;
                        lower--;
                        if(lower>0){
                            lower--;
                        }else{
                            break;
                        }
                    }
                }
                if(mid<dic.size()-1){
                 long long higher=mid+1;
                    while(dic.at(higher).first == dic.at(mid).first){
                        cout << dic.at(higher).second << endl;
                        if(dic.size()>higher){
                            higher++;
                        }else{
                            break;
                        }
                    }
                }

            break;
        }else if(result>0){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return 0;
}


int main (){
    //配列random_wordsに入力された文字列を格納
    vector<string> random_words(0);

    ifstream file("input.txt");
    string word;
    while(getline(file, word)){
        random_words.push_back(word);
    }
    //cout << random_words.at(0) << endl;

    //dic.txtを読み込んで、元の単語をpairの配列dictionary.firstへ、ソート語の単語をdictionary.secondへ格納。
    ifstream ifs("dic.txt");
    string dic_word;
    vector<pair<string,string>> dictionary(0);
    while(getline(ifs, dic_word)){
        string original_word = dic_word;
        sort(dic_word.begin(),dic_word.end());
        dictionary.push_back(make_pair(dic_word,original_word));
    }
    sort(dictionary.begin(),dictionary.end());

    //全文字列に順にanagram1を適用。
    for(long long i=0;i<random_words.size();i++){
        anagram1(random_words.at(i), dictionary);
    }
    return 0;
}