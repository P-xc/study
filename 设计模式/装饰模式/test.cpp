#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> getLeastNumbers(vector<int>& arr, int k) {
	vector<int> res(k,0);
	res[0] = arr[0] > arr[1] ? arr[1] : arr[0];
	res[1] = arr[0] > arr[1] ? arr[0] : arr[1];
	for(size_t i = 2; i < arr.size(); i++){

		if (arr[i] > res[0] && arr[i] < res[1]) {
			res[0] = arr[i];
		}
		else if (arr[i] < res[0]) {
			res[0] = arr[i];
		}
	}
	return res;

}
int main() {
	vector<int> nums = { 3,2,1 };
	getLeastNumbers(nums, 2);
	return 0;
}