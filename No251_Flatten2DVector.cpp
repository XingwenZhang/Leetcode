// 251. Flatten 2D Vector

// Implement an iterator to flatten a 2d vector.

// For example,
// Given 2d vector =

// [
//   [1,2],
//   [3],
//   [4,5,6]
// ]
// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

// Follow up:
// As an added challenge, try to code it using only iterators in C++ or iterators in Java.


class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        index = 0;
        start = vec2d.begin();
        end = vec2d.end();
    }

    int next() {
        // In reality, it should first check hasNext then call next()
        return (*start)[index++];
    }

    bool hasNext() {
        while(start != end && index == (*start).size()){
            start++;
            index = 0;
        }
        return start != end;
    }
private:
    vector<vector<int> >::iterator start, end;
    int index;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */