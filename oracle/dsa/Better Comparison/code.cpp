#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string betterCompression(string &S)
{
    unordered_map<char, int> freq_map;
    string result;

    for (int i = 0; i < S.length();)
    {
        char current_char = S[i++];
        int freq = 0;
        while (i < S.length() && isdigit(S[i]))
        {
            freq = freq * 10 + (S[i] - '0');
            i++;
        }
        freq_map[current_char] += freq;
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
        if (freq_map.find(c) != freq_map.end() && freq_map[c] > 0)
        {
            result += c;
            result += to_string(freq_map[c]);
        }
    }

    return result;
}
int main()
{
    string compressed = "a13b56d6c2b4a5d11c19";
    string proper_compressed = betterCompression(compressed);
    cout << proper_compressed << endl; // Output: "a3b2c10"
    return 0;
}