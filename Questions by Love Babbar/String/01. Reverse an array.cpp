

// Sol 1
void reverseString1(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
            swap(s[i++], s[j--]);
}



// Sol 2

void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n/2; i++)
            swap(s[i], s[n - 1 - i]);
}
