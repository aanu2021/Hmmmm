int make(const vector<int> &v) {
    int r = 0;
    for (int x : v) {
        r |= 1 << (x - 1);
    }
    return r;
}

int solution(const vector<vector<int>> &customers, const vector<vector<int>> shops) {
    unordered_map<int, int> have;
    for (const auto& v : customers) {
        ++have[make(v)];
    }
    unordered_set<int> masks;
    for (const auto& v : shops) {
        masks.insert(make(v));
    }
    int r = 0;
    for (auto t1 = masks.begin(); t1 != masks.end(); ++t1) {
        for (auto t2 = t1; t2 != masks.end(); ++t2) {
            const int mask = (*t1) | (*t2);
            int may = 0;
            for (const auto& p : have) {
                if ((p.first & mask) == p.first) {
                    may += p.second;
                }
            }
            r = max(r, may);
        }
    }
    return r;
    
}

int main() {
    cout << solution({{1, 2, 3}, {1, 4, 2}}, {{1, 2, 3, 4, 5}, {2, 3, 4, 6, 7}}) << endl;
    cout << solution({{1, 2, 3}, {1, 7, 2}}, {{1, 2, 3, 4, 5}, {2, 3, 4, 6, 1}}) << endl;
    return 0;
}