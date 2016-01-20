/*
Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <array>
#include <iostream>

using namespace std;

typedef array<array<int,4>,4> Image;

// typedef array<byte, 4> Pixel;

int replacePixel(Image& image, int newVal, int row, int col)
{
    int tempVal = image[row][col];
    image[row][col] = newVal;
    return tempVal;
}

void rotateImage90(Image& image, bool clockwise)
{
    for(int k = 0; k < image.size() / 2; k++)
    {
        for(int i = 0; i < image.size() - 1 - 2*k; i++)
        {
            //i represents steps from the corner
            int thisRow = i + k;
            int thisCol = image.size() - 1 - k;
            
            int newVal = image[k][i+k];
            
            newVal = replacePixel(image, newVal, thisRow, thisCol);

            thisRow = image.size() - 1 - k;
            thisCol = image.size() - 1 - i - k;

            newVal = replacePixel(image, newVal, thisRow, thisCol);    

            thisRow = image.size() - 1 - i - k;
            thisCol = k;

            newVal = replacePixel(image, newVal, thisRow, thisCol);    

            thisRow = k;
            thisCol = i + k;
            
            newVal = replacePixel(image, newVal, thisRow, thisCol);
        }
    }
}


void printImage(Image& image)
{
    for(int i = 0; i < image.size(); i++)
{
    for(int j = 0; j < image[i].size(); j++)
{
    cout << image[i][j] << " ";
}
cout << endl;
}
}



int main(){
    array<array<int,4>,4> image = { { { 1, 2, 3, 4},
                                    { 5, 6, 7, 8},
                                    { 9, 10,11,12},
                                    { 13,14,15,16} } };
    printImage(image);
    rotateImage90(image, 1);
    
    rotateImage90(image, 1);
    rotateImage90(image, 1);
    rotateImage90(image, 1);
    cout << endl << endl;
    printImage(image);
    
}


