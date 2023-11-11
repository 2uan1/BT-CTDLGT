#include <iostream>
#include <vector>

using namespace std;

struct item {
    int weight;
    int value;

    item(int weight_, int value_) {
        weight = weight_;
        value = value_;
    }
};

void printItems(vector<item> items) {
    cout << "size = " << items.size() << endl;
    for (size_t i = 0; i < items.size(); i++) {
        cout << "item " << i << " has weight " << items.at(i).weight << " and value " << items.at(i).value << endl;
    }
}

vector<item> greedy(vector<item> items, int capacity) {
    int itemCount = items.size();
    float valueAdjustedForWeight[itemCount];
    bool taken[itemCount] = {false};
    vector<item> backpack;
    for (int i = 0; i < itemCount; i++) {
        valueAdjustedForWeight[i] = (float)items.at(i).value / (float)items.at(i).weight;
        cout << valueAdjustedForWeight[i] << " ";
    }
    cout << endl;
    while (capacity > 0) {
        int mostValuableIndex = 0;
        for (int i = 0; i < itemCount; i++) {
            if (taken[i] == false) {
                mostValuableIndex = i;
                break;
            }
        }
        for (int i = 0; i < itemCount; i++) {
            if (valueAdjustedForWeight[mostValuableIndex] < valueAdjustedForWeight[i] && !taken[i]) mostValuableIndex = i;
        }
        if (capacity >= items.at(mostValuableIndex).weight && taken[mostValuableIndex] == false) {
            taken[mostValuableIndex] = true;
            backpack.push_back(items.at(mostValuableIndex));
            capacity -= items.at(mostValuableIndex).weight;
        }
    }
    return backpack;
}

vector<item> dynamic(vector<item> items, int capacity) {
    vector<item> backpack;
    int itemCount = items.size();
    int valueTable[itemCount][capacity+1];

    for (int i = 0; i < itemCount; i++) {
        
        int currentItemValue = items.at(i).value;
        int currentItemWeight = items.at(i).weight;
        for (int j = 0; j <= capacity; j++) {

            if (i == 0) {
                if (j >= currentItemWeight) {
                    valueTable[i][j] = currentItemValue;
                } else {
                    valueTable[i][j] = 0;
                }
            } else {
                if (j >= currentItemWeight) {
                    valueTable[i][j] = max(valueTable[i-1][j], valueTable[i-1][j-currentItemWeight] + currentItemValue);
                } else {
                    valueTable[i][j] = valueTable[i-1][j];
                }
            }
            if (valueTable[i][j] < 10) {
                cout << valueTable[i][j] << "  ";
            } else {
                cout << valueTable[i][j] << " ";
            }
        }
        cout << endl;
    }

    int row = itemCount-1;
    int col = capacity;

    while (row != 0 && col != 0) {
        if (valueTable[row][col] != valueTable[row-1][col]) {
            backpack.push_back(items.at(row));
            col -= items.at(row).weight;
            row--;
        } else {
            row--;
        }
    }

    return backpack;
}

int main(int argc, char const *argv[])
{
    int capacity, itemCount;
    cout << "enter capacity and item count: ";
    cin >> capacity >> itemCount;
    vector<item> items;
    for (int i = 0; i < itemCount; i++) {
        int weight, value;
        cin >> weight >> value;
        item* dumb = new item(weight, value);
        items.push_back(*dumb);    
    }

    printItems(items);

    vector<item> backpack = dynamic(items, capacity);

    printItems(backpack);

    return 0;
}
