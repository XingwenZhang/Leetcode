// 604. Design Compressed String Iterator

// Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

// The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

// next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
// hasNext() - Judge whether there is any letter needs to be uncompressed.

// Note:
// Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

// Example:

// StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

// iterator.next(); // return 'L'
// iterator.next(); // return 'e'
// iterator.next(); // return 'e'
// iterator.next(); // return 't'
// iterator.next(); // return 'C'
// iterator.next(); // return 'o'
// iterator.next(); // return 'd'
// iterator.hasNext(); // return true
// iterator.next(); // return 'e'
// iterator.hasNext(); // return false
// iterator.next(); // return ' '


class StringIterator {
public:
    StringIterator(string compressedString) {
        cur = ' ';
        res_cnt = 0;
        index = 0;
        compressed_string = compressedString;
    }
    
    char next() {
        if(res_cnt > 0){ 
        	res_cnt--;
        	return cur;
        }
        else if(index < compressed_string.size()){
        	cur = compressed_string[index];
        	int j = index + 1;
        	while(j < compressed_string.size() && isdigit(compressed_string[j])) j++;

        	string num = compressed_string.substr(index+1, j-index-1);
        	res_cnt = stoi(num);
        	index = j;
        	
        	res_cnt--;
        	return cur;
        }
        else{
        	return ' ';
        }
    }
    
    bool hasNext() {
        if(res_cnt <= 0 && index >= compressed_string.size()){
        	return false;
        }
        return true;
    }
private:
	char cur;
	int res_cnt;
	int index;
	string compressed_string;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */