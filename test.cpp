#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res; // 存放结果的数组
	if (nums.size() < 4) return res; // 特判，如果 nums 长度小于 4，直接返回空数组

	sort(nums.begin(), nums.end()); // 排序，为了去重和双指针算法做准备

	int n = nums.size();
	for (int i = 0; i < n - 3; i++) { // 第一重循环，枚举第一个数
		if (i > 0 && nums[i] == nums[i - 1]) continue; // 第一个数去重

		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break; // 剪枝，如果最小的四个数加起来已经大于 target，后面肯定不行
		if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue; // 剪枝，如果当前最大的四个数加起来都小于 target，当前的数肯定不行

		for (int j = i + 1; j < n - 2; j++) { // 第二重循环，枚举第二个数
			if (j > i + 1 && nums[j] == nums[j - 1]) continue; // 第二个数去重

			if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break; // 剪枝，如果最小的四个数加起来已经大于 target，后面肯定不行
			if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue; // 剪枝，如果当前最大的四个数加起来都小于 target，当前的数肯定不行

			int left = j + 1, right = n - 1; // 双指针初始化
			while (left < right) { // 第三重循环，使用双指针算法
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum < target) {
					left++;
				}
				else if (sum > target) {
					right--;
				}
				else {
					res.push_back({ nums[i], nums[j], nums[left], nums[right] }); // 找到了符合条件的四个数,将其存为一个系列
					left++;
					right--;
					/*
					这部分代码是双指针算法中用来去重的部分。由于在前面的循环中已经找到了一个符合条件的四元组，所以如果左指针向右移动一位时，它指向的元素与前一个元素相同，那么这个四元组一定与前面的四元组重复了，需要跳过这个元素，继续向右移动左指针，以避免重复计算。同理，如果右指针向左移动一位时，它指向的元素与后一个元素相同，也需要跳过这个元素，继续向左移动右指针。
					*/
					while (left < right && nums[left] == nums[left - 1]) left++; // 左指针去重
					while (left < right && nums[right] == nums[right + 1]) right--; // 右指针去重
				}
			}
		}
	}

	return res;
}

int main() {
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	int target = 0;

	vector<vector<int>> res = fourSum(nums, target);

	for (auto& arr : res) {  // 遍历 res 中的每一个二维数组，对于每一个二维数组，使用引用避免拷贝，将其命名为 arr
		for (auto& num : arr) {  // 遍历 arr 数组中的每一个数，对于每一个数，使用引用避免拷贝，将其命名为 num
			cout << num << " ";  // 输出 num 数组中的数，并在数之间加一个空格
		}
		cout << endl;  // 输出一个换行符，用于换行
	}


	return 0;
}
