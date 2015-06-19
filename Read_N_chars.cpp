using namespace std;


class Solution {
public:
    int read(char *buf, int n) {
        char b[4];
        int validlen;
        int len=0;
        while(len < n)
        {
            validlen = read4(b);
            for (int i = 0;i<validlen && len<n;i++){
                *(buf++) = b[i];
                len++;
            }

            if (validlen<4) break;
       }
        
       return len;
    }

    //multiple calls

    char _buf[4]; // buffer to save leftover bytes
    int offset = 0, validLen = 0; // offset of carry over bytes and valid len of carry over bytes
    int read(char *buf, int n) {
        int len = 0;
        // read carry over bytes
        for (; offset<validLen && len < n; offset++) {
            *(buf++) = _buf[offset];
            len++;
        }

        while (len < n) {
            validLen = read4(_buf); // read to _buffer first and copy the bytes to input buffer
            for (offset=0; offset<validLen && len < n; offset++) {
                *(buf++) = _buf[offset];
                len++;
            }
            if (validLen < 4) break; // if there is no enought bytes left, break
        }
        return len;
    }
};


int main() {

    

    return 0;
}
