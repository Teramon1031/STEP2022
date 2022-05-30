/*
search path from "Google" to "渋谷".
This code used DFS with recursive functions.
*/

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

map<string, string> pages;
map<string, set<string>> links;
map<string, bool> seen;
stack<string> path;

void stack_clear(stack<string> &q){
  stack<string> empty;
  swap(q, empty);
}

bool search_path(string &from, string &to){
  // boundary condition
  if(from == to){
    return true;
  }

  if(seen[from]){
    return false;
  }

  seen[from] = true;

  for(auto link:links[from]){
    bool result = search_path(link, to);
    if(result){
      // Since it's executed from the back of the recursion, push to the `Path` will be in the reverse order of access. 
      // popping the STACK will make the order correct.
      path.push(pages[link]);
      return true;
    }
  }
  return false;
}

void input_pages_and_links() {
  {
    // ifstream file("data/pages_small.txt");
    ifstream file("data/pages.txt");
    string data;
    // get each line as string data
    while (getline(file, data)) {
        // get the position of tab
      auto index = data.find('\t');
        // get the part of line from the 0th to the tab as id
      auto id = data.substr(0, index);
        // get the remaining line from the (index+1)th as title
      auto title = data.substr(index + 1, data.size() - id.size() - 1);
      pages[id] = title;
      seen[id] = false;
    }
  }

  {
    // ifstream file("data/links_small.txt");
    ifstream file("data/links.txt");
    string data;
    while (getline(file, data)) {
      auto index = data.find('\t');
        // get the link source as `from`
      auto from = data.substr(0, index);
      auto to = data.substr(index + 1, data.size() - from.size() - 1);
        // there can be more than one links leading from a single link.
        // so here "insert" is used.
      links[from].insert(to);
    }
  }
}

void output_path(string &from, string &to) {
  // make a txt file to output the result. 
  ofstream output_file;
  string filename = "output_dfs1.txt";
  output_file.open(filename, ios::out);
  
  if(search_path(from,to)){
    path.push(pages[from]);
    output_file << path.top() << endl;
    path.pop();
    while(!path.empty()){
      output_file << " -> " << path.top() << endl;
      path.pop();
    }
  }else{
    cout << "辿れないよ…(｡>_<｡)" << endl;
  }
  output_file.close();
}

int main() {
  stack_clear(path);

  input_pages_and_links();

  // enter two words to search a path between them
  string from_word, to_word;
  cout << "from: ";
  cin >> from_word;
  cout << "to: ";
  cin >> to_word;

  // convert input words to the corresoponding ids
  string from,to;
  for(auto page:pages){
    if(page.second==from_word){
      from = page.first;
    } 
    if(page.second==to_word){
      to = page.first;
    } 
  }
  
  output_path(from, to);
  
  return 0;
}
