//Paint Fill: Implement the "paint fill" function that one might see on many image editing programs.
//That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color,
//fill in the surrounding area until the color changes from the original color.

const int ScreenSize=7;
//red-white picture (sample case)
//so, color must be 0 or 1
typedef array<array<bool,ScreenSize>,ScreenSize> screen; //suppose that an image is balanced rectangle
typedef pair<int,int> point; //declare screen point aka pixel

//the recursive routine for filling an area with new color
//The runtime is O(N*N) at worst case, the space is O(N+N*N) (includig recursive stack & screen size)
void PaintFill(screen& image, const point& pixel, const bool& color){

if(pixel.first<0 || pixel.second<0 || pixel.first>ScreenSize-1 || pixel.second>ScreenSize-1) return;    //edge case throwing

if(image[pixel.first][pixel.second]==color) return; //if the pixel has a the same color as brush
else image[pixel.first][pixel.second]=color;

//DFS-like filling
PaintFill(image, make_pair(pixel.first-1,pixel.second), color);//backward horizontally
PaintFill(image, make_pair(pixel.first+1,pixel.second), color);//forward horizontally
PaintFill(image, make_pair(pixel.first,pixel.second-1), color);//downward vertically
PaintFill(image, make_pair(pixel.first,pixel.second+1), color);//upward vertically

return;

}
