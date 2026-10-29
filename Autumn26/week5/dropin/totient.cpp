#include <iostream>
#include <cmath>

int gcd(int a, int b) {
    int rem = a - (a/b * b);

    if (a%b==0) {
        return b;
    }
    else {
        return gcd(b, rem);
    }
}

int euler_totient(int a) {
    int n = 0;
    for (int i=1; i<=a; ++i) {
        if (gcd(a, i) == 1) {
            ++n;
        }
    }
    return n;
}

int totient_sum(int n, int &depth) {
    if (n==1 || n==0) {
        return 0;
    }

    ++depth;

    int sum = 0;
    int next_num = euler_totient(n);
    sum += next_num + totient_sum(next_num, depth);

    return sum;
}

int strongest_peak(int a, int b, int &depth, int &depth_prev, int &depth_next) {
    bool peak_found = false;
    depth=0; depth_prev=0; depth_next=0; 
    int x=-1;
    double max_strength = -std::pow(10, 9);
    double curr_strength;

    for (int i=a+1; i<b; ++i) {
        totient_sum(i, depth);
        totient_sum(i-1, depth_prev);
        totient_sum(i+1, depth_next);

        if (depth<=depth_prev && depth<=depth_next) {
            continue;
        }

        curr_strength = (depth-depth_prev + depth-depth_next)/2.;


        if (curr_strength > max_strength) {
            peak_found = true;
            max_strength = curr_strength;
            x = i;
        }
    }

    if (!peak_found) {
        depth=0; depth_prev=0; depth_next=0; 
        x=-1;
    }
    return x;
}

int main() {
    int a, b, c;
    int depth, prev_depth, next_depth;
    std::cin >> a >> b;
    std::cout << strongest_peak(a, b, depth, prev_depth, next_depth) << std::endl;
}