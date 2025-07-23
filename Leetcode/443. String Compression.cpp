class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0 , i = 0;

        while(i < n) {
            char currentCharacter = chars[i];
            int count = 0;

            while(i < n && chars[i] == currentCharacter) {
                i++;
                count++;
            }

            // write the character count
            chars[index] = currentCharacter;
            index++;

            if(count > 1) {
                string countStr = to_string(count);
                for(char ch : countStr) {
                    chars[index++] = ch;
                }
            }
        }

        return index;
    }
};
