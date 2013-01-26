//
//  paragraph_layout.cpp
//  Algorithm
//
//  Created by Shuai on 8/17/12.
//
//

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

struct Line
{
    unsigned start;
    unsigned end;
    unsigned len;
};

struct State
{
    unsigned line;
    unsigned shift;
    unsigned line_len;
    unsigned cubes_accumulation;
    int next_state;
};

void layout_text(const vector<string>& text, unsigned column)
{
    if (text.empty())
        return;
    
    vector<Line> lines;
    
    int start = 0, length = 0;
    for (size_t i=0; i<text.size(); i++)
    {
        length += text[i].size() + (i > start ? 1 : 0);
        if (length > column)
        {
            Line l = {start, i, length - text[i].size() - 1};
            lines.push_back(l);
            start = i;
            length = text[i].size();
        }
    }

    Line l = {start, text.size(), length};
    lines.push_back(l);
    
    cout << "---Original Text----" << endl;
    for (size_t i=0; i<lines.size(); i++) {
        printf("Line %3d ", i);
        for (size_t j=lines[i].start; j<lines[i].end; j++) {
            cout << text[j];
            if (j < lines[i].end - 1)
                cout << " ";
        }
        cout << endl;
    }
    
    cout << "\n---Formated Text----" << endl;

    
    vector<State> states;
    State initial = {lines.size() - 1, 0, lines[lines.size() - 1].len, 0, -1};
    states.push_back(initial);
    
    size_t begin = 0;
    for (int i=lines.size() - 2; i >= 0; i--)
    {
        size_t end = states.size();
        unsigned shift_word_length = 0;

        for (int word = lines[i].end; word > lines[i].start; word --)
        {
            if (word != lines[i].end)
                shift_word_length += text[word].size() + 1;
            
            unsigned minimal_cubic = 0xffffffff;
            int minimal_state = -1;
            for (size_t state=begin; state < end; state++)
            {
                unsigned len = shift_word_length + states[state].line_len;
                if (len <= column)
                {
                    unsigned cubic = states[state].line == lines.size() - 1 ? 0 : (column-len)*(column-len)*(column-len);
                    cubic += states[state].cubes_accumulation;
                    
                    if (cubic < minimal_cubic)
                    {
                        minimal_cubic = cubic;
                        minimal_state = state;
                    }
                }
            }
            
            if (minimal_state == -1) {
                break;
            }
            
            State s = {i, lines[i].end - word, lines[i].len - shift_word_length, minimal_cubic, minimal_state};
            states.push_back(s);
        }
        
        begin = end;
    }

    size_t minimal_state = -1;
    unsigned minimal_cubic = 0xffffffff;
    for (size_t i=states.size()-1; i>=0; i--) {
        if (states[i].line != 0) {
            break;
        }
        
        unsigned cubic = states[i].cubes_accumulation + (column - states[i].line_len)*(column - states[i].line_len)*(column - states[i].line_len);
        if (cubic < minimal_cubic)
        {
            minimal_cubic = cubic;
            minimal_state = i;
        }
    }
    
    unsigned word = 0;
    unsigned len = 0;
    while (minimal_state != -1) {
        printf("Line %3d ", states[minimal_state].line);
        unsigned max_word = lines[states[minimal_state].line].end - states[minimal_state].shift;
        len = max_word - word - 1;
        for (; word < max_word; word++) {
            cout << text[word];
            if (word < max_word -1)
            {
                cout << " ";
            }
            
            len += text[word].size();
        }
        assert(len <= column);
        
        while (len++ < column) {
            cout << "-";
        }
        len = 0;
        cout << endl;
        minimal_state = states[minimal_state].next_state;
    }
}

void test_layout_text()
{
    vector<string> text;
    fstream file;
    file.open("/Users/shuais/Desktop/Algorithm/Algorithm/layout.txt");

    
    string word;
    if (file.is_open())
    {
        while (file.good())
        {
            getline(file, word, ' ');
            text.push_back(word);
        }
    }
    
//    text.push_back(string("THIS"));
//    text.push_back(string("IS"));
//    text.push_back(string("AN"));
//    text.push_back(string("TESTCASE"));

    layout_text(text, 50);
}
