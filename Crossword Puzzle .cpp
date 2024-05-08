#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void printCrossword(const vector<string>& crossword) {
    for (const string& row : crossword) {
        cout << row << endl;
    }
}

bool canPlace(const vector<string>& crossword, const string& word, int row, int col, char direction) {
    int n = crossword.size();
    if (direction == 'h') {
        if (col + word.length() > n) return false;
        for (int i = 0; i < word.length(); ++i) {
            if (crossword[row][col + i] != '-' && crossword[row][col + i] != word[i]) {
                return false;
            }
        }
    } else {
        if (row + word.length() > n) return false;
        for (int i = 0; i < word.length(); ++i) {
            if (crossword[row + i][col] != '-' && crossword[row + i][col] != word[i]) {
                return false;
            }
        }
    }
    return true;
}

void placeWord(vector<string>& crossword, const string& word, int row, int col, char direction) {
    if (direction == 'h') {
        for (int i = 0; i < word.length(); ++i) {
            crossword[row][col + i] = word[i];
        }
    } else {
        for (int i = 0; i < word.length(); ++i) {
            crossword[row + i][col] = word[i];
        }
    }
}

bool solveCrossword(vector<string>& crossword, const vector<string>& words, int idx) {
    if (idx == words.size()) return true;

    int n = crossword.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (crossword[i][j] == '-' || crossword[i][j] == words[idx][0]) {
                if (canPlace(crossword, words[idx], i, j, 'h')) {
                    vector<string> temp = crossword;
                    placeWord(crossword, words[idx], i, j, 'h');
                    if (solveCrossword(crossword, words, idx + 1)) {
                        return true;
                    }
                    crossword = temp;
                }
                if (canPlace(crossword, words[idx], i, j, 'v')) {
                    vector<string> temp = crossword;
                    placeWord(crossword, words[idx], i, j, 'v');
                    if (solveCrossword(crossword, words, idx + 1)) {
                        return true;
                    }
                    crossword = temp;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<string> crossword;
    for(int i =0;i<10;i++)
    {
        string a;
        cin>>a;
        crossword.push_back(a);
    }
    string words;
    cin>>words;
    vector<string> wordList;
    stringstream ss(words);
    string word;
    while (getline(ss, word, ';')) {
        wordList.push_back(word);
    }

    solveCrossword(crossword, wordList, 0);

    printCrossword(crossword);

    return 0;
}
