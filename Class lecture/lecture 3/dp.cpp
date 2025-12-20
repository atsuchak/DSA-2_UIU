#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <string>

class Stopwatch {
public:
    Stopwatch() : running(false) {}

    void start() {
        if (!running) {
            start_time = std::chrono::high_resolution_clock::now();
            running = true;
        } else {
            std::cout << "Stopwatch is already running." << std::endl;
        }
    }

    void stop() {
        if (running) {
            end_time = std::chrono::high_resolution_clock::now();
            running = false;
        } else {
            std::cout << "Stopwatch is not running." << std::endl;
        }
    }

    void reset() {
        running = false;
        // Optionally, you can reset start_time and end_time here,
        // although they will be overwritten on the next start.
    }

    long long elapsedMilliseconds() const {
        if (running) {
            auto now = std::chrono::high_resolution_clock::now();
            return std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time).count();
        } else {
            return std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        }
    }

    long long elapsedSeconds() const {
        return elapsedMilliseconds() / 1000;
    }

private:
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;
    bool running;
};

using namespace std;

long long fibWithoutDP (int n) {
    if (n <= 1)
        return 1;
    return fibWithoutDP(n-1) + fibWithoutDP(n-2);
}

long long memo[1000];

long long fibWithDP (int n) {
    // Base case
    if (n <= 1)
        return 1;
    // Memoization
    if (memo[n] != -1)
        return memo[n];
    // Recursion
    memo[n] = fibWithDP(n-1) + fibWithDP(n-2);
    return memo[n];
}

long long staircase(int n) {
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = staircase(n-1) + staircase(n-2) + staircase(n-3);
    return memo[n];
}

int notes[] = {1, 5, 8, 12};
int taken[1000];

int coinChange (int n) {
    if (n == 0)
        return 0;
    if (n < 0)
        return INT32_MAX;
    if (memo[n] != -1)
        return memo[n];
    int minimum = INT32_MAX;
    for (int note: notes) {
        int temp = coinChange(n - note);
        if (temp < minimum) {
            minimum = temp;
            taken[n] = note;
        }
    }
    memo[n] = minimum + 1;
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    Stopwatch watch;
    // watch.start();
    // cout << fibWithoutDP(n) << endl;
    // cout << watch.elapsedMilliseconds() << endl;
    // watch.stop();

    memset(memo, -1, sizeof(memo));
    // watch.start();
    // cout << fibWithDP(n) << endl;
    // cout << watch.elapsedMilliseconds() << endl;
    // watch.stop();
    cout << coinChange(n) << endl;
    while (n > 0) {
        cout << taken[n] << " taka note is taken." << endl;
        n -= taken[n];
    }
}