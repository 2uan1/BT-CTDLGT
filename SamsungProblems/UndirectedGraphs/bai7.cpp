#include <iostream>
#include <vector>

using namespace std;

void floodFillDFS(int x, int y, vector<vector<int>>& image, int targetColor, int newColor, int row, int col) {
    if (x < 0 || x >= row || y < 0 || y >= col || image[x][y] != targetColor) {
        return;
    }

    image[x][y] = newColor;

    floodFillDFS(x + 1, y, image, targetColor, newColor, row, col);
    floodFillDFS(x - 1, y, image, targetColor, newColor, row, col);
    floodFillDFS(x, y + 1, image, targetColor, newColor, row, col);
    floodFillDFS(x, y - 1, image, targetColor, newColor, row, col);
}

void floodFill(int x, int y, vector<vector<int>>& image, int newColor, int row, int col) {
    int targetColor = image[x][y];

    floodFillDFS(x, y, image, targetColor, newColor, row, col);
}

void printScreen(vector<vector<int>>& image, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int row, col;
    cout << "Enter the row and column: ";
    cin >> row >> col;
    vector<vector<int>> image(row);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int color;
            cin >> color;
            image.at(i).push_back(color);
        }
    }

    cout << endl;
    printScreen(image, row, col);
    cout << endl;
    floodFill(0, 1, image, 3, row, col);
    printScreen(image, row, col);

    return 0;
}