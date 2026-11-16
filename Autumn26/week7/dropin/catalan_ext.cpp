#include <iostream>
#include <vector>
#include <fstream>

unsigned long calc_C_k(const std::vector<unsigned long> &c) {
    unsigned long answer = 0;
    int n = c.size();
    if (n == 0) {
        return 1;
    }
    for (int i=0; i < n; ++i) {
        answer += c[i]*c[n-1-i];
    }
    return answer;
}

std::vector<unsigned long> catalan_numbers(int n) {
    std::vector<unsigned long> v;
    unsigned long C_k;
    for (int i = 0; i <= n; ++i) {
        C_k = calc_C_k(v);
        v.push_back(C_k);
    }

    return v;
}

unsigned long get_C_k(int i, std::vector<unsigned long> &v) {
    int n = v.size();
    if (i <= n-1) {
        return v[i];
    }
    v = catalan_numbers(i);
    return v[i];
}

void read_file(std::string filename, std::vector<std::string> &v) {
    std::ifstream infile;
    infile.open(filename);

    std::string s;
    while (infile >> s) {
        v.push_back(s);
    }
}

int count_operators_in_string(std::string s) {
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {
            ++count;
        }
    }

    return count;
}

std::vector<int> count_operators_in_vector(const std::vector<std::string> &v) {
    std::vector<int> counts;
    int n = v.size(), t;
    for (int i = 0; i < n; ++i) {
        t = count_operators_in_string(v[i]);
        counts.push_back(t);
    }
    return counts;
}

void construct_output(const std::vector<int> &counts, std::vector<unsigned long> &catalan, std::vector<unsigned long> &out) {
    int n = counts.size();
    for (int i = 0; i < n; ++i) {
        out.push_back(get_C_k(counts[i], catalan));
    }
}

void output_to_file(std::string filename, const std::vector<unsigned long> &output) {
    std::ofstream outfile;
    outfile.open(filename);

    for (int i = 0; i < output.size(); ++i) {
        outfile << output[i] << std::endl;
    }
}

int main() {
    std::string infilename = "expressions.txt", outfilename = "expression_counts.txt";

    std::vector<std::string> exprs;
    read_file(infilename, exprs);
    
    std::vector<int> counts = count_operators_in_vector(exprs);

    std::vector<unsigned long> catalan = catalan_numbers(50);

    std::vector<unsigned long> output;
    construct_output(counts, catalan, output);

    output_to_file(outfilename, output);

    return 0;    
}