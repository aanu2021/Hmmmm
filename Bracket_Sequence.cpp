int solution(const string &s) {
    int ind = -1, d = 0;
    const int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++d;
        } else if (--d < -1) {
            return 0;
        } else if (d == -1 && ind < 0) {
            ind = i;
        }
    }
    if (ind >= 0 && d == -1) {
        return ind + 1;
    }
    ind = -1;
    d = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == ')') {
            ++d;
        } else if (--d < -1) {
            return 0;
        } else if (d == -1 && ind < 0) {
            ind = i;
        }
    }
    return ind >= 0 && d == -1 ? (n - ind) : 0;
}

