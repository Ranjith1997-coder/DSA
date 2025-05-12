#include "../stdc++.h" 

using namespace std;


int min_height_shelf_util(vector<pair<int,int>> books, int self_width, int book_size,  int index,  int height) {

    if (index == books.size()) {
        return height;
    }

    if (index == 0) {
        return min_height_shelf_util(books, self_width, book_size + books[index].first,  index + 1, height + books[index].second);
    } else {
        if (book_size + books[index].first <= self_width) {
            return min(min_height_shelf_util(books, self_width, book_size + books[index].first , index + 1 , max(height, books[index].second)), 
            min_height_shelf_util(books, self_width, books[index].first , index + 1 , height + books[index].second));
        } else {
            return min_height_shelf_util(books, self_width, books[index].first , index + 1 , height + books[index].second);
        }
    }
}

int min_height_shelf(vector<pair<int,int>> books, int shelf_width){

    int res = 0;

    return min_height_shelf_util(books, shelf_width, 0, 0, 0);

}

int main() {
    vector<pair<int,int>> books = {{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    // vector<pair<int,int>> books = {{1,3},{2,4},{3,2}};
    int shelf_width = 4;


    int min = min_height_shelf(books, shelf_width);
}