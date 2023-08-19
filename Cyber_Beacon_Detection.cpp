long long sqr(long long x) {
    return x * x;
}

long long solution(int x1, int y1, int x2, int y2, int xx, int yy, int r) {
    x1 -= xx;
    y1 -= yy;
    x2 -= xx;
    y2 -= yy;
    const long long rr = sqr(r);
    long long ans = 0;
    for (int dx = 0, dy = r; sqr(dx) <= rr; ++dx) {
        while (sqr(dx) + sqr(dy) > rr) {
            --dy;
        }
        const int num = min(dy, y2) - max(-dy, y1);
        if (num < 0) {
            continue;
        }
        if (dx >= x1 && dx <= x2) {
            ans += num + 1;
        }
        if (dx && -dx >= x1 && -dx <= x2) {
            ans += num + 1;
        }
    }
    return ans;
    
  
}


int main() {
    cout << solution(0, 0, 1, 2, 0, 0, 1) << endl;
    cout << solution(0, 0, 2, 2, 0, 0, 3) << endl;
    return 0;
}