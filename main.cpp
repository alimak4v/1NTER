#include "Lexem.h"
#include <vector>
#include <fstream>

using namespace std;

vector<Lexem> lexems;

struct vertex {
    vertex* to[256] = {nullptr};
    bool terminal = false;
};

class Bor {
public:
    void add_string(string &s) {
        vertex* v = v0;
        for (char c: s) {
            if (!v->to[c]) {
                v->to[c]=new vertex;
            }
            v=v->to[c];
        }
        v->terminal = true;
    }

    pair<bool, Lexem> has(char* s, int size = 0, int s_index = 0) {
        vertex* cur = v0;
        Lexem answer;
        string line = "";

        for(int i = 0; i < size; ++i) {
            cur=cur->to[s[i]];
            line.push_back(s[i]);
            if (cur == nullptr) {
                answer.set_text(line);
                answer.set_type(line);
                answer.set_e(s_index);
                answer.set_s(i + 1);

                return {false, answer};
            }
            if (cur->terminal) {
                answer.set_text(line);
                answer.set_type(line);
                answer.set_e(s_index);
                answer.set_s(i + 1);

                return {true, answer};
            }
        }

        answer.set_text(line);
        answer.set_type(line);
        answer.set_e(s_index);
        answer.set_s(size);

        return {false, answer};
    }
private:
    vertex* v0 = new vertex;
};

int main() {
    cout << "бляяя" << endl;
    Bor working_system;

    {
        std::ifstream file_code;
        file_code.open("/Users/sinicynaleksej/1NTER/workwords");
        if (file_code.is_open()) {
            cout << "файл открылся" << endl;
            string ln;
            while (getline(file_code, ln)) {
                working_system.add_string(ln);
            }
            cout << "файл прочитан" << endl;
        }
        file_code.close();
    }

    char* code = new char;
    int size = 0;

    {
        std::ifstream file_code;
        file_code.open("/Users/sinicynaleksej/1NTER/code.mop");
        if (file_code.is_open()) {
            cout << "файл открылся" << endl;
            string ln;
            while (getline(file_code, ln)) {
                for (char s: ln) {
                    code[size] = s;
                    ++size;
                }
                code[size] = '\n';
                ++size;
            }
            cout << "файл прочитан" << endl;
        }
        file_code.close();
    }

    for (int start = 0; start < size; ++start) {
        cout << endl << "------------------" << endl << endl;
        char* first = code + start;

        Lexem worked_lexem;

        if (working_system.has(first, size - start, start).first) {
            worked_lexem = working_system.has(first, size - start, start).second;
            cout << "working word" << endl;
            cout << worked_lexem.get_text() << endl;
            cout << worked_lexem.get_e() << endl;

            start += (worked_lexem.get_text()).size() - 1;
        }
    }

    return 0;
}