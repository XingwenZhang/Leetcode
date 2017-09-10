// 223. Rectangle Area

// Find the total area covered by two rectilinear rectangles in a 2D plane.

// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

// Rectangle Area
// Assume that the total area is never beyond the maximum possible value of int.



class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s_left = (C-A) * (D-B);
        int s_right = (G-E) * (H-F);
        int bottom_left_x, bottom_left_y, top_right_x, top_right_y;

        bottom_left_x = max(A,E);
        bottom_left_y = max(B,F);
        top_right_x = max(min(C,G),bottom_left_x);
        top_right_y = max(min(D,H),bottom_left_y);

        int s_over = (top_right_x - bottom_left_x) * (top_right_y - bottom_left_y);

        return s_left + s_right - s_over;
    }
};