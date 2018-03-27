#ifndef CS197C_LEXICON
#define CS197C_LEXICON
#include <iostream>
#include <string>
#include <ostream>
#include<vector>
#include <map>
#include <fstream>

using namespace std;


class Lexicon {
    private:
        map< string, int > lex;
    public:
        Lexicon(string &filename);
        ~Lexicon();
        int count();
        int count(string &token);
        bool contains(string &token);
        void increment(string &token);
        void increment(string &token, int n);
        void remove(string &token);
        void printLexicographically(ostream &out);
        void printCardinally(ostream &out);
        double distanceFrom(Lexicon &other, double (*scoringFunction)(int count1, int total1, int count2, int total2));
};

#endif
