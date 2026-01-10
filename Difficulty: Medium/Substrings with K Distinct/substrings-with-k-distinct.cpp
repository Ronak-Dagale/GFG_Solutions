class Solution {
  public:
int atMostK(string &s, int k) {
    if (k < 0) return 0;
    vector<int> fre(26, 0);
    int j = 0, distinct = 0, ans = 0;

    for (int i = 0; i < s.size(); i++) {
        if (fre[s[i]-'a']++ == 0)
            distinct++;

        while (distinct > k) {
            if (--fre[s[j]-'a'] == 0)
                distinct--;
            j++;
        }

        ans += (i - j + 1);
    }
    return ans;
}

int countSubstr(string &s, int k) {
    return atMostK(s, k) - atMostK(s, k - 1);
}

};