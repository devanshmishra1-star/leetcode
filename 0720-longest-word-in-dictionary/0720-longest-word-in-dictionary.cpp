class Solution {
public:
    string longestWord(vector<string>& words) {
        // Sort the words lexicographically
        sort(words.begin(), words.end());
        
        unordered_set<string> valid_words;
        string result = "";
        
        for (const string& word : words) {
            // A word is valid if its length is 1 OR its prefix (minus the last char) is already built
            if (word.length() == 1 || valid_words.count(word.substr(0, word.length() - 1))) {
                valid_words.insert(word);
                
                // Update the result if we find a strictly longer word
                // (Sorting guarantees lexicographical order for equal lengths)
                if (word.length() > result.length()) {
                    result = word;
                }
            }
        }
        
        return result;
    }
};