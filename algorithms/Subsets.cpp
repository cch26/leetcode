// Source : https://leetcode.com/problems/subsets/
// Date   : 2016/10/22

// Given a set of distinct integers, nums, return all possible subsets.
// Note: The solution set must not contain duplicate subsets.
//
// For example,
// If nums = [1,2,3], a solution is:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

// 递归
// 增量构造法
// 每个元素，都有两种选择，选或者不选
// 深搜，时间复杂度 O(2^n)，空间复杂度 O(n)
class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end()); // 输出要求有序
    vector<vector<int> > result;
    vector<int> path;
    subsets(S, path, 0, result);
    return result;
  }
private:
  static void subsets(const vector<int> &S, vector<int> &path, int step,
                      vector<vector<int> > &result) 
  {
    if (step == S.size()) 
    {
      result.push_back(path);
      return;
    }
    // ̼不选 S[step]
    subsets(S, path, step + 1, result);
    // 选 S[step]
    path.push_back(S[step]);
    subsets(S, path, step + 1, result);
    path.pop_back();
  }
}；

// 位向量法
// 开一个位向量 bool selected[n]，每个元素可以选或者不选
// 深搜，时间复杂度 O(2^n)，空间复杂度 O(n)
class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end()); // 输出要求有序
    vector<vector<int> > result;
    vector<bool> selected(S.size(), false);
    subsets(S, selected, 0, result);
    return result;
  }
private:
  static void subsets(const vector<int> &S, vector<bool> &selected, int step,
                      vector<vector<int> > &result) 
  {
    if (step == S.size()) 
    {
      vector<int> subset;
      for (int i = 0; i < S.size(); ++i)
      {
        if (selected[i]) subset.push_back(S[i]);
      }
      result.push_back(subset);
      return;
    }
    // ̼不选 S[step]
    selected[step] = false;
    subsets(S, selected, step + 1, result);
    // 选 S[step]
    selected[step] = true;
    subsets(S, selected, step + 1, result);
  }
}；

// 迭代
// 增量构造法
// 时间复杂度 O(2^n)，空间复杂度 O(1)
class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end()); // 输出要求有序
    vector<vector<int> > result(1);
    for (auto elem : S) 
    {
      result.reserve(result.size() * 2);
      auto half = result.begin() + result.size();
      copy(result.begin(), half, back_inserter(result));
      for_each(half, result.end(), [&elem](decltype(result[0]) &e){
        e.push_back(elem);
      });
    }
    return result;
  }
};

// 二进制法
// 本方法的前提是：集合的元素不超过int位数。用一个int整数表示位向量，第i位为1，则表示选择S[i]，为0则不选择。
// 这种方法最巧妙。因为它不仅能生成子集，还能方便的表示集合的并、交、差等集合运算。设两个集合的位向量分别为
// B1 和 B2，则 B1 ∪ B2，B1 ∩ B2，B1 △ B2分别对应集合的并、交、对称差。
// 二进制法，也可以看做是位向量法，只不过更加优化。
// 时间复杂度 O(2^n)，空间复杂度 O(1)
class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end()); // 输出要求有序
    vector<vector<int> > result;
    const size_t n = S.size();
    vector<int> v;
    for (size_t i = 0; i < 1 << n; ++i) 
    {
      for (size_t j = 0; j < n; ++j) 
      {
        if (i & 1 << j) v.push_back(S[j]);
      }
      result.push_back(v);
      v.clear();
    }
    return result;
  }
};
