#include <vector>
#include <time.h>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

template <class Comparable>
int max_elem(const vector<Comparable> A){
    int k = A[0];
    for (int i = 1; i < A.size(); i ++)
        if (k < A[i])
            k = A[i];
    return k;
}

void cout_str_vect(const vector<string> A){
    cout << "[ ";
    for (int i = 0; i < A.size(); i ++){
        cout << "\'" << A[i] << "\'"; 
        if (i != A.size()-1)
            cout << ", ";
    }
    cout << " ]";
    cout << endl;
}

template <class Comparable>
void cout_vector(const vector<Comparable> A){
    for (int i = 0; i < A.size(); i ++){
        cout << A[i] << ", ";
    }
    cout << endl;
}

void radix_sort(vector<string> &A){
    vector<string> C;
    C.assign(A.size(), "");
    int N = A.size();
    int R = 256;
    int W = 15;

    for (int d = W-1; d >= 0; d--){
        vector<int> count;
        count.assign(R+1, 0);

        for (int i = 0; i < N; i++)
            count[A[i][d] + 1]++;

        for (int r = 0; r < R; r++)
            count[r+1] += count[r];
        
        for (int i = 0; i < N; i++)
            C[count[A[i][d]] ++] = A[i];
        
        for (int i = 0; i < N; i++)
            A[i] = C[i];
    }

}

vector<string> splitLine(string &text, char sep)
{
    vector<string> tokens;
    size_t start = 0, end = 0;
    clock_t begin, end_;
    string substring;

    while ((end = text.find(sep, start)) != string::npos){
        substring = text.substr(start, end - start);
        if (substring.size() >= 4)
            tokens.push_back(substring);
        start = end + 1;
    }
    substring = text.substr(start);
    if (substring.size() >= 4)
        tokens.push_back(substring);
    
    return tokens;
}

string remove_extension(string str){
    size_t start = 0, end = 0;
    string extension;
    while (end = str.find('.', start) != string::npos) {
        start = end + 1;
    }
    return str.substr(0, start - 1);
}

string set_output_file(string input_filename){
    size_t start = 0, end = 0;
    string extension;
    while ((end = input_filename.find('.', start)) != string::npos) {
        start = end + 1;
    }
    return input_filename.substr(0, start - 1).append("_ordenado.txt");
}

int main(int argv, char ** argc){
    vector<string> C;
    vector<string> input_files = {
        "war_and_peace_clean.txt",
        "frankenstein_clean.txt"
    };

    vector<string> output_files;

    for (int i = 0; i < input_files.size(); i ++){
        output_files.push_back(set_output_file(input_files[i]));
    }

    clock_t begin, end;

    fstream file_in, file_out;


    for (int i = 0; i < input_files.size(); i ++){
        file_in.open(input_files[i], ios::in);
        file_out.open(output_files[i], ios::out);

        begin = clock();
        while (!file_in.eof()){
            string line;
            getline(file_in, line, '\n');
            C = splitLine(line, ' ');
        }
        end = clock();
        
        cout << "size: " << C.size() << endl;
        cout << "time to read file: " << (double)(end-begin)/CLOCKS_PER_SEC << endl;

        begin = clock();
        radix_sort(C);
        end = clock();
        
        cout << "radix sort time: " << (double)(end-begin)/CLOCKS_PER_SEC << endl;

        begin = clock();

        vector<string>::iterator last = C.begin();
        int count = 1;
        file_out << *last<< " ";
        for (vector<string>::iterator it = C.begin()+1; it != C.end(); ++it){
            if (*last != *it){
                file_out << count << endl;
                count = 1;
                *last = *it;
                file_out << *it << " ";
            }
            else {
                count ++;
            }
        }
        file_out << count;
        end = clock();

        cout << "time to write file: " << (double)(end-begin)/CLOCKS_PER_SEC << endl;

        file_in.close();
        file_out.close();
    }

    return 0;
}


