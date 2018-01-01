// 158. Read N Characters Given Read4 II - Call multiple times

// The API: int read4(char *buf) reads 4 characters at a time from a file.

// The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

// By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

// Note:
// The read function may be called multiple times.

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int ptr = 0;
        while(ptr < n){ // not arrive the max size of buffer
        	if(buffPtr == 0){ // 
        		buffCnt = read4(buffPriv);
        	}

        	while(ptr < n && buffPtr < buffCnt){
        		buf[ptr++] = buffPriv[buffPtr++];
        	}
        	if(buffPtr == buffCnt) buffPtr = 0;

        	if(buffCnt < 4) break;
        }

        return ptr;
    }
private:
	int buffPtr = 0;
	int buffCnt = 0;
	char buffPriv[4];
};