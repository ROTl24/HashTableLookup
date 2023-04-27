#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res; // ��Ž��������
	if (nums.size() < 4) return res; // ���У���� nums ����С�� 4��ֱ�ӷ��ؿ�����

	sort(nums.begin(), nums.end()); // ����Ϊ��ȥ�غ�˫ָ���㷨��׼��

	int n = nums.size();
	for (int i = 0; i < n - 3; i++) { // ��һ��ѭ����ö�ٵ�һ����
		if (i > 0 && nums[i] == nums[i - 1]) continue; // ��һ����ȥ��

		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break; // ��֦�������С���ĸ����������Ѿ����� target������϶�����
		if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue; // ��֦�������ǰ�����ĸ�����������С�� target����ǰ�����϶�����

		for (int j = i + 1; j < n - 2; j++) { // �ڶ���ѭ����ö�ٵڶ�����
			if (j > i + 1 && nums[j] == nums[j - 1]) continue; // �ڶ�����ȥ��

			if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break; // ��֦�������С���ĸ����������Ѿ����� target������϶�����
			if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue; // ��֦�������ǰ�����ĸ�����������С�� target����ǰ�����϶�����

			int left = j + 1, right = n - 1; // ˫ָ���ʼ��
			while (left < right) { // ������ѭ����ʹ��˫ָ���㷨
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum < target) {
					left++;
				}
				else if (sum > target) {
					right--;
				}
				else {
					res.push_back({ nums[i], nums[j], nums[left], nums[right] }); // �ҵ��˷����������ĸ���,�����Ϊһ��ϵ��
					left++;
					right--;
					/*
					�ⲿ�ִ�����˫ָ���㷨������ȥ�صĲ��֡�������ǰ���ѭ�����Ѿ��ҵ���һ��������������Ԫ�飬���������ָ�������ƶ�һλʱ����ָ���Ԫ����ǰһ��Ԫ����ͬ����ô�����Ԫ��һ����ǰ�����Ԫ���ظ��ˣ���Ҫ�������Ԫ�أ����������ƶ���ָ�룬�Ա����ظ����㡣ͬ�������ָ�������ƶ�һλʱ����ָ���Ԫ�����һ��Ԫ����ͬ��Ҳ��Ҫ�������Ԫ�أ����������ƶ���ָ�롣
					*/
					while (left < right && nums[left] == nums[left - 1]) left++; // ��ָ��ȥ��
					while (left < right && nums[right] == nums[right + 1]) right--; // ��ָ��ȥ��
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

	for (auto& arr : res) {  // ���� res �е�ÿһ����ά���飬����ÿһ����ά���飬ʹ�����ñ��⿽������������Ϊ arr
		for (auto& num : arr) {  // ���� arr �����е�ÿһ����������ÿһ������ʹ�����ñ��⿽������������Ϊ num
			cout << num << " ";  // ��� num �����е�����������֮���һ���ո�
		}
		cout << endl;  // ���һ�����з������ڻ���
	}


	return 0;
}
