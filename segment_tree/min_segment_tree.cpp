#include "../stdc++.h"

using namespace std;

void create_min_segment_tree_util(int l, int h, int tree_pos, vector<int>& arr, vector<int>& min_segment_tree) {
    if (l == h) {
        min_segment_tree[tree_pos] = arr[l];
        return;
    }

    int mid = (l + h) / 2;

    create_min_segment_tree_util(l , mid , (2 * tree_pos) + 1 , arr, min_segment_tree);
    create_min_segment_tree_util(mid + 1 , h , (2 * tree_pos) + 2 , arr, min_segment_tree);

    min_segment_tree[tree_pos] = min(min_segment_tree[(2 * tree_pos) + 1], min_segment_tree[(2 * tree_pos) + 2]);

    return;

}


vector<int> create_min_segment_tree(vector<int>& arr) {

    vector<int> min_segment_tree(4 * arr.size() , INT_MAX);

    create_min_segment_tree_util(0, arr.size()-1, 0, arr, min_segment_tree);

    return min_segment_tree;

}

int query_min_util(vector<int>& segment_tree, int arr_l, int arr_h, int l , int h, int seg_tree_pos){
    if ((arr_h < l) || ( h < arr_l)) {
        return INT_MAX;
    }

    if ((l <= arr_l) && (h >= arr_h)){
        return segment_tree[seg_tree_pos];
    }

    int mid = (arr_l + arr_h) / 2;

    return min(query_min_util(segment_tree, arr_l, mid , l , h, 2 * seg_tree_pos + 1), 
                query_min_util(segment_tree, mid+1, arr_h, l, h, 2 * seg_tree_pos + 2));
}

int query_min(vector<int>& segment_tree, vector<int>& arr, int l , int h) {

    return query_min_util(segment_tree, 0, arr.size()-1, l , h, 0);

}
int main() {

    vector<int> arr = { 1, 3, 2, 7, 9, 11 };

    vector<int> segment_tree = create_min_segment_tree(arr);

    int res = query_min(segment_tree, arr, 1, 4);


}