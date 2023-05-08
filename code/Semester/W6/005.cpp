#include <iostream>
#include <map>

using namespace std;
	
int main(){
	map<string, int> word_count;
	string word;

	while (getline(cin,word)){
		if (word.begin()==word.end())
			break;
        for (char& ch: word)
            ch = tolower(ch);
		word_count[word]++;
	}

	for (const auto &w: word_count){
		cout << w.first << ": ";
		cout << w.second;
	    cout << (w.second > 1 ? " veces": " vez") << endl;
	}

	return 0;
}