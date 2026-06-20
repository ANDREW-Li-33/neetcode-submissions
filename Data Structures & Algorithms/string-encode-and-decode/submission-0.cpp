class Solution {
public:

    unordered_map<size_t, string> map;
    hash<string> hash_function;

    string encode(vector<string>& strs) {
        string encoded_string = "";
        size_t hash_value;
        for (string s : strs) {
            hash_value = hash_function(s);
            map[hash_value] = s;
            encoded_string += to_string(hash_value) + '_';
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings;
        string new_string = "";
        for (char c : s) {
            if (c != '_') {
                new_string += c;
            } else {
                size_t hash_value = stoull(new_string); 
                decoded_strings.push_back(map[hash_value]);
                new_string = "";
            }
        }
        return decoded_strings;
    }
};
