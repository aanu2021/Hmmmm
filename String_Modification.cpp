void better(int &x, int y) {
    if (y >= 0 && (x < 0 || x > y)) {
        x = y;
    }
}

int solution(const string &s) {
    vector<vector<int>> dp(26, vector<int>(2, -1));
    for (int i = 0; i < 26; ++i) {
        dp[i][0] = abs(i - (s[0] - 'a'));
    }
    // dp[x][0/1] the minimum cost when last character is x and whether the string is good.
    for (int i = 1; i < s.length(); ++i) {
        const int x = s[i] - 'a';
        vector<vector<int>> temp(26, vector<int>(2, -1));
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (dp[j][k] < 0) {
                    continue;
                }
                better(temp[j][1], dp[j][k] + abs(x - j));
                if (k == 1) {
                    for (int y = 0; y < 26; ++y) {
                        if (j != y) {
                            better(temp[y][0], dp[j][k] + abs(x - y)); 
                        }
                    }
                }
            }
        }
        dp = temp;
    }
    int r = -1;
    for (int i = 0; i < 26; ++i) {
        better(r, dp[i][1]);
    }
    return r;
}

int main() {
    cout << solution("aca") << endl;
    cout << solution("abab") << endl;
    return 0;
}