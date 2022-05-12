#include <bits/stdc++.h>
using namespace std;

/*
- 入力
辞書ファイル -> dic.txt
単語 -> input2.txt
*/

vector<int> scorelist={1,3,2,2,1,3,3,1,1,4,4,2,2,1,1,3,4,1,1,1,2,3,3,4,3,4};

int anagram2(vector<int> charlist_random, vector<string> dic, vector<vector<int>> charlist_dic){ 
    int max_score=0;
    int max_dic=-1;
    
    for(int i=0; i<charlist_dic.size();i++){
        //check if the random_word includes each word on the dictionary
        bool incld=true;
        for(int k=0; k<26; k++){
          if(charlist_random.at(k)<charlist_dic.at(i).at(k)){
              incld=false;
          }
        }
    
        if(incld){
            int score=0;
            //calculate the score of dic.at(i)
             for(int k=0; k<dic.at(i).size(); k++){
                 int letter_num = dic.at(i).at(k)- 'a';
                 score += scorelist.at(letter_num);
             }
            //compare with max_score
            if(score>max_score){
                max_score = score;
                max_dic = i;
             }
        }
    }
    if(max_dic!=-1){
       cout << dic.at(max_dic) <<endl;
    }
        
    return 0;
}


int main (){
    //配列random_wordsに入力された文字列を格納
    vector<string> random_words(0);

    ifstream file("input2.txt");
    string word;
    while(getline(file, word)){
        random_words.push_back(word);
    }

    //与えられた文字列のアルファベット26文字をそれぞれカウント
    vector<vector<int>> charlist_random(random_words.size(), vector<int>(26));

    for(int i=0; i<random_words.size(); i++){
        for(int k=0;k<random_words.at(i).size();k++){
            char letter = random_words.at(i).at(k);
            int letter_num = letter - 'a';
            if(letter_num>=0 && letter_num < 26){
                charlist_random.at(i).at(letter_num)++;
            }
        }
    }

    //dic.txtを読み込んで、配列dictionaryへ格納。
    ifstream ifs("dic.txt");
    string dic_word;
    vector<string> dictionary(0);
    while(getline(ifs, dic_word)){
        dictionary.push_back(dic_word);
    }

    //辞書の単語のアルファベット26文字をそれぞれカウント
    vector<vector<int>> charlist_dic(dictionary.size(), vector<int>(26));

    for(int i=0; i<dictionary.size(); i++){
        for(int k=0;k<dictionary.at(i).size();k++){
            char letter = dictionary.at(i).at(k);
            int letter_num = letter - 'a';
            if(letter_num>=0 && letter_num < 26){
                charlist_dic.at(i).at(letter_num)++;
            }
        }
    }

    //全文字列に順にanagram2を適用。
    for(long long i=0;i<random_words.size();i++){
        anagram2(charlist_random.at(i), dictionary, charlist_dic);
    }
    return 0;
}