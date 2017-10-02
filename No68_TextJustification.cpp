// 68. Text Justification

// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left justified and no extra space is inserted between words.

// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.

// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.

// click to show corner cases.

// Corner Cases:
// A line other than the last line might contain only one word. What should you do in this case?
// In this case, that line should be left-justified.

// Very dirty code ^-^
// consider one line one word and last line
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if(maxWidth == 0){
            res.push_back("");
            return res;
        }
        int i=0;
        while(i < words.size()) {
            string row = "";
            int len = 0;
            int j = i;
            int word_len = 0;
            while (j < words.size() && word_len + words[j].size() + j - i <= maxWidth) { // If has space for words
                // len = len + words[j].size() + j - i;
                word_len += words[j].size();
                j++;
            }
            j--;
            if (j == words.size() - 1) {
                for (int k = i; k < j; k++) {
                    row += words[k];
                    row += " ";
                }
                row += words[j];
                row.append(maxWidth - word_len - j + i, ' ');
            } else {
                if (j == i) { // only one word on one line
                    row += words[j];
                    row.append(maxWidth - word_len, ' ');
                } else {
                    if ((maxWidth - word_len) % (j - i) == 0) { // Space divide evenly
                        int num_space = (maxWidth - word_len) / (j - i);
                        for (int k = i; k < j; k++) {
                            row += words[k];
                            row.append(num_space, ' ');
                        }
                        row += words[j];
                    } else {
                        int num_space = (maxWidth - word_len) / (j - i);
                        int num_rem = (maxWidth - word_len) % (j - i);
                        for (int k = i; k < j; k++) {
                            row += words[k];
                            row.append(num_space, ' ');
                            if (num_rem) {
                                row += " ";
                                num_rem--;
                            }
                        }
                        row += words[j];
                    }
                }
            }
            res.emplace_back(row);
            ++j;
            i=j;
        }

        return res;
    }
};