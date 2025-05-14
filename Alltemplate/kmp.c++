// Function to compute the LPS (Longest Prefix Suffix) array
//use zero based index
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);  
    int len = 0; 
    int i = 1;   
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
